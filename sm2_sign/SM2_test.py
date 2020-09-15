from lib import EllipticCurve as ECC
from lib import Point
from lib import mathtools
from lib import SM2_SIGN
from lib import strtools
import math
import random
import hashlib


def test():

    p = 0x8542D69E4C044F18E8B92435BF6FF7DE457283915C45517D722EDB8B08F1DFC3
    n = 0x8542D69E4C044F18E8B92435BF6FF7DD297720630485628D5AE74EE7C32E79B7
    a = 0x787968B4FA32C3FD2417842E73BBFEFF2F3C848B6831D7E0EC65228B3937E498
    b = 0x63E4C6D3B23B0C849CF84241484BFE48F61D59A5B16BA06E6E12D1DA27C5249A
    gx = 0x421DEBD61B62EAB6746434EBC3CC315E32220B3BADD50BDC4C4E6C147FEDD43D
    gy = 0x0680512BCBB42C07D47349D2153B70C4E5D7FDFCBFA36EA1A85841B9E46E09A2
    '''
        p = 211
        n = 240
        a = 0
        b = -4
        gx = 2
        gy = 2
        '''
    # pt = open(r'E:\CryptoCode\CodeInPython\Experiment10\SM2_KEY\Message.txt', 'r')
    sk = open(r'E:\CryptoCode\CodeInPython\Experiment10\SM2_KEY\PrivateKey.txt', 'w')
    pk = open(r'E:\CryptoCode\CodeInPython\Experiment10\SM2_KEY\PublicKey.txt', 'w')

    cfile = open(
        r'E:\CryptoCode\CodeInPython\Experiment10\SM2_KEY\Ciphertext.txt', 'w')
    mfile = open(
        r'E:\CryptoCode\CodeInPython\Experiment10\SM2_KEY\MessageDecrypted.txt', 'w')
    label1 = '------------------------------------Public Key------------------------------------\n'
    label2 = '----------------------------------Public Key End----------------------------------\n'
    label3 = '-----------------------------------Private Key------------------------------------\n'
    label4 = '---------------------------------Private Key End----------------------------------\n'

    curve = ECC.EllipticCurve(p, n, a, b, gx, gy)

    SM_2 = SM2_SIGN.SM2(curve)
    ska, pka = SM_2.KeyGen()

    sk.write(label3 + str(pka) + '\n' + hex(ska)[2:] + '\n' + label4)
    pk.write(label1 + str(pka) + '\n' + label2)

    # m = pt.read()
    m = 'message digest'
    '''
        ska = 0x1649AB77A00637BD5E2EFE283FBF353534AA7F7CB89463F208DDBC2920BB0DA0
        xa = 0x435B39CCA8F3B508C1488AFC67BE491A0F7BA07E581A0E4849A5CF70628A7E0A
        ya = 0x75DDBA78F15FEECB4C7895E2C1CDF5FE01DEBB2CDBADF45399CCF77BBA076A42
        pka = Point.Point(curve, xa, ya, False)
        '''

    ID = 'ALICE123@YAHOO.COM'
    pka = (0x0AE4C7798AA0F119471BEE11825BE46202BB79E2A5844495E97C04FF4DF2548A,
           0x7C0240F88F1CD4E16352A73C17B7F16F07353E53A176D684A9FE0C6BB798E857)
    ska = 0x128B2FA8BD433C6C068C8D803DFF79792A519A55171B1B650C23661D15897263
    c = SM_2.Sign(pka, ska, m, ID)
    print(SM_2.Check(pka, c, ID))
    # pt.close()
    sk.close()
    pk.close()
    cfile.close()
    mfile.close()


if __name__ == "__main__":

    test()
    input()
