from lib import EllipticCurve as ECC
from lib import Point
from lib import mathtools
from lib import strtools
import math
import random
import hashlib


def KDF(Z, klen):
    # use hex to implement
    v = 64  # 256 bits / 4
    length = math.ceil(klen / v)
    ct = 0x00000001
    K = ''
    H = ''
    for i in range(length):
        S = Z + hex(ct)[2:].zfill(8)
        K += H
        H = hashlib.sha256(int.to_bytes(
            int(S, 16), len(S) // 2, byteorder='big')).hexdigest() 
        ct += 1
    if isinstance(klen/v, int):
        K += H
    else:
        H = H[len(H) - klen + klen // v * v:]
        K += H
    return K


class SM2(object):
    def __init__(self, curve):
        self.curve = curve
        self.g = Point.Point(self.curve, self.curve.gx, self.curve.gy, False)

    ''' KeyGenerate
        d is sk
        P is pk
    '''

    def KeyGen(self):
        d = random.randint(1, self.curve.n - 2)
        P = self.g * d
        return (d, P)

    def Sign(self, pk, sk, m, ID):
        entlen = len(ID) * 8
        ENTL = int.to_bytes(entlen, 2, byteorder='big')
        Z_B = ENTL + ID.encode('utf-8')
        a_byte = strtools.int_to_byte(self.curve.a)
        b_byte = strtools.int_to_byte(self.curve.b)
        gx_byte = strtools.int_to_byte(self.curve.gx)
        gy_byte = strtools.int_to_byte(self.curve.gy)
        pk0_byte = strtools.int_to_byte(pk[0])
        pk1_byte = strtools.int_to_byte(pk[1])
        Z_B += a_byte + b_byte + gx_byte + gy_byte + pk0_byte + pk1_byte
        Z = hashlib.sha256(Z_B).digest()
        M_BAR = Z + m.encode('utf-8')
        e = int(hashlib.sha256(M_BAR).hexdigest(),16)
        while True:
            k = random.randint(1, self.curve.n - 1)
            x1, y1 = (self.g * k).x, (self.g * k).x
            r = (e + x1) % self.curve.n
            if r == 0 or r + k == self.curve.n:
                continue
            s = mathtools.inv(1 + sk, self.curve.n) * (k - r * sk) % self.curve.n
            if s != 0:
                break
        return (m, (hex(r)[2:], hex(s)[2:]))

    def Check(self, pk, sign, ID):

        entlen = len(ID) * 8
        ENTL = int.to_bytes(entlen, 2, byteorder='big')
        Z_B = ENTL + ID.encode('utf-8')
        a_byte = strtools.int_to_byte(self.curve.a)
        b_byte = strtools.int_to_byte(self.curve.b)
        gx_byte = strtools.int_to_byte(self.curve.gx)
        gy_byte = strtools.int_to_byte(self.curve.gy)
        pk0_byte = strtools.int_to_byte(pk[0])
        pk1_byte = strtools.int_to_byte(pk[1])
        Z_B += a_byte + b_byte + gx_byte + gy_byte + pk0_byte + pk1_byte
        Z = hashlib.sha256(Z_B).digest()
        
        M = Z + sign[0].encode('utf-8')
        e = int(hashlib.sha256(M).hexdigest(), 16)
        r = int(sign[1][0], 16)
        s = int(sign[1][1], 16)
        t = (r + s) % self.curve.n
        PA = Point.Point(self.curve, pk[0], pk[1], False)

        H = self.g * s + PA * t
        x = H.x
        R = (e + x) % self.curve.n
        return R == r

