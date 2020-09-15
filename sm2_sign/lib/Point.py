from lib import EllipticCurve
from lib import mathtools
import math


class Point(object):
    '''
        x, y is the coordinate
        z means whether it is infinite
    '''

    def __init__(self, curve, x, y, z):
        self.curve = curve
        self.x = x
        self.y = y
        self.z = z

        if not curve.testPoint(x, y, z):
            raise Exception(
                "The point %s is not on this curve %s" % (self, curve))

    def __str__(self):
        return "( %s, %s )" % (self.x, self.y)

    def encode(self):
        l = int((math.log(self.curve.p, 2) + 8 - 1) // 8)
        l *= 2
        x1 = hex(self.x)[2:].zfill(l)
        y1 = hex(self.y)[2:].zfill(l)
        S = '04' + x1 + y1
        return S

    def decode(self):
        return str(self)

    def toHex(self):
        l = int((math.log(self.curve.p, 2) + 8 - 1) // 8)
        l *= 2
        x1 = hex(self.x)[2:].zfill(l)
        y1 = hex(self.y)[2:].zfill(l)
        S = '04' + x1 + y1
        return S

    def cToHex(self):
        l = math.ceil(math.log(self.curve.p, 2))
        l = int(math.ceil(l / 8) * 8) // 4
        sx = hex(self.x)[2:].zfill(l)
        sy = hex(self.y)[2:].zfill(l)
        return (sx, sy)

    def toBin(self):
        h = str(self)
        l = int(len(h) * 4)
        return bin(int(h, 16))[2:].zfill(l)

    def cToBin(self):
        l = math.ceil(math.log(self.curve.p, 2))
        l = int(math.ceil(l / 8) * 8)
        sx = bin(self.x)[2:].zfill(l)
        sy = bin(self.y)[2:].zfill(l)
        return (sx, sy)

    def isInfinite(self):
        return self.z

    def __repr__(self):
        return str(self)

    def __eq__(self, other):
        return (self.curve, self.x, self.y) == (other.curve, other.x, other.y)

    def __neg__(self):
        neg_x = self.x
        neg_y = (-self.y) % self.curve.p
        return Point(self.curve, neg_x, neg_y, False)

    def __add__(self, Q):
        if self.curve != Q.curve:
            raise Exception("different curves")
        if self.isInfinite():
            return Q
        if Q.isInfinite():
            return self
        if Q == -self:
            return Point(self.curve, 0, 1, True)

        xp = self.x
        yp = self.y
        xq = Q.x
        yq = Q.y
        if self == Q:
            lamb = ((3 * xp * xp % self.curve.p + self.curve.a) * mathtools.inv(2 * yp, self.curve.p)) % self.curve.p
        else:
            lamb = (yq - yp) % self.curve.p * mathtools.inv((xq - xp), self.curve.p)

        xr = (lamb * lamb - xp - xq) % self.curve.p
        yr = (lamb * (xp - xr) - yp) % self.curve.p

        return Point(self.curve, xr, yr, False)

    def __mul__(self, n):
        if not isinstance(n, int):
            raise Exception("n must be an int!")
        if n == 0:
            return Point(self.curve, 0, 1, True)
        if n == 1:
            return self

        Q = Point(self.curve, 0, 1, True)
        i = 1 << (int(math.log(n, 2)))
        while i > 0:
            Q = Q + Q
            if n & i == i:
                Q = Q + self
            i = i >> 1
        return Q
