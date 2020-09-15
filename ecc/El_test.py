from lib import ElGamal as El
from lib import EllipticCurve as ECC
from lib import mathtools
from lib import Point
from lib import strtools

if __name__ == "__main__":

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
    pt = open(r'E:\CryptoCode\CodeInPython\Experiment8\El_KEY\Message.txt', 'r')
    sk = open(r'E:\CryptoCode\CodeInPython\Experiment8\El_KEY\PrivateKey.txt', 'w')
    pk = open(r'E:\CryptoCode\CodeInPython\Experiment8\El_KEY\PublicKey.txt', 'w')

    cfile = open(
        r'E:\CryptoCode\CodeInPython\Experiment8\El_KEY\Ciphertext.txt', 'w')
    mfile = open(
        r'E:\CryptoCode\CodeInPython\Experiment8\El_KEY\MessageDecrypted.txt', 'w')
    label1 = '------------------------------------Public Key------------------------------------\n'
    label2 = '----------------------------------Public Key End----------------------------------\n'
    label3 = '-----------------------------------Private Key------------------------------------\n'
    label4 = '---------------------------------Private Key End----------------------------------\n'

    curve = ECC.EllipticCurve(p, n, a, b, gx, gy)
    m = pt.read()
    m = strtools.str_to_int(m)

    El_A = El.ElGamal(curve)
    El_B = El.ElGamal(curve)

    pka, ska = El_A.KeyGen()
    sk.write(label3 + str(pka) + '\n' + hex(ska)[2:] + '\n' + label4)
    pk.write(label1 + str(pka) + '\n' + label2)

    c = El_B.Encrypt(pka, m)
    cfile.write(str(c))
    m1 = El_A.Decrypt(ska, c[0], c[1])
    mfile.write(strtools.int_to_str(m1))
