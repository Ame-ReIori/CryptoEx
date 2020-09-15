class EllipticCurve(object):
    def __init__(self, p, n, a, b, gx, gy):
        self.p = p
        self.n = n
        self.a = a
        self.b = b
        self.gx = gx
        self.gy = gy

    ''' testPoint
        test whether a point is a point on the curve
        z: True means it is infinite
    '''

    def testPoint(self, x, y, z):
        left = (y % self.p * y % self.p) % self.p
        right = (x % self.p * x % self.p * x %
                 self.p + self.a * x % self.p + self.b) % self.p
        return (left == right) or z

    def __str__(self):
        return "The curve is y^2 = x^3 + %sx + %s, p = %s, n = %s" % (self.a, self.b, self.p, self.n)

    def __repr__(self):
        return str(self)

    def __eq__(self, other):
        return (self.a, self.b, self.p, self.n) == (other.a, other.b, other.p, other.n)
