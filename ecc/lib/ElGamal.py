from lib import EllipticCurve
from lib import mathtools
from lib import Point
import random


class ElGamal(object):
    def __init__(self, curve):
        self.curve = curve
        self.g = Point.Point(self.curve, self.curve.gx, self.curve.gy, False)

    def KeyGen(self):
        sk = random.randint(1, self.curve.n - 1)
        pk = self.g * sk
        return (pk, sk)

    def Encrypt(self, pk, m):
        k = random.randint(1, self.curve.n - 1)
        c1 = self.g * k  # key
        c2 = (pk * k).x + int(m)  # ciphertext
        return (c1, c2)

    def Decrypt(self, sk, c1, c2):
        return c2 - (c1 * sk).x
