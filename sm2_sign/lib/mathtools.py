def EXGCD(a, b):
    if b == 0:
        return (1, 0, a)
    (x, y, r) = EXGCD(b, a % b)
    temp = x
    x = y
    y = temp - a // b * y
    return (x, y, r)


def inv(a, m):
    return EXGCD(a, m)[0]
