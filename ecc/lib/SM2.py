from lib import EllipticCurve as ECC
from lib import Point
from lib import mathtools
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

    def Encrypt(self, pk, m):
        while True:
            k = random.randint(1, self.curve.n - 1)
            k = 0x4C62EEFD6ECFC2B95B92FD6C3D9575148AFA17425546D49018E5388D49DD7B4F
            C1 = (self.g * k).encode()
            Q = pk * k
            x2, y2 = Q.cToHex()
            t = KDF(x2 + y2, len(m))
            if int(t, 16) != 0:
                break
        C2 = hex(int(m, 16) ^ int(t, 16))[2:].zfill(len(m))
        C3 = hashlib.sha256(int.to_bytes(
            int(x2 + m + y2, 16), len(x2 + m + y2) // 2, byteorder='big')).hexdigest()
        C = C1 + C2 + C3
        return C

    def Decrypt(self, sk, c):
        l = int((math.log(self.curve.p, 2) + 8 - 1) // 8)
        l = 2 * l
        lt = 2 * l + 2
        C1_hex = c[:lt]
        x1 = int(C1_hex[2:2+l], 16)
        y1 = int(C1_hex[2+l:], 16)
        C1 = Point.Point(self.curve, x1, y1, False)
        if self.curve.testPoint(C1.x, C1.y, C1.z) == False:
            raise Exception("The point %s is not the one on %s" %
                            (C1, self.curve))
        C3 = c[len(c) - 64:]
        C2 = c[lt:len(c) - 64]
        Q = C1 * sk
        x2, y2 = Q.cToHex()
        t = KDF(x2 + y2, len(C2))
        if int(t, 16) == 0:
            raise Exception("Error! t = 0")
        m = hex(int(C2, 16) ^ int(t, 16))[2:].zfill(len(C2))
        u = hashlib.sha256(int.to_bytes(int(x2 + m + y2, 16), len(x2 + m + y2) // 2, byteorder='big')).hexdigest()
        if u != C3:
            raise Exception("Error! u != C3")
        return m
