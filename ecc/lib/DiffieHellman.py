from lib import mathtools
from lib import EllipticCurve
from lib import Point
import random


class DiffieHellman(object):
    def __init__(self, curve):
        self.curve = curve
        self.g = Point.Point(self.curve, self.curve.gx, self.curve.gy, False)

    def KeyGen(self):
        return random.randint(0, self.curve.n - 1)

    def Encrypt(self, x):
        return self.g * x

    def Decrypt(self, x, gy):
        return gy * x
