from lib import DiffieHellman as DH
from lib import EllipticCurve as ECC
from lib import mathtools
from lib import Point

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
    skA = open(
        r'E:\CryptoCode\CodeInPython\Experiment8\DH_KEY\PrivateKeyA.txt', 'w')
    skB = open(
        r'E:\CryptoCode\CodeInPython\Experiment8\DH_KEY\PrivateKeyB.txt', 'w')

    pkA = open(r'E:\CryptoCode\CodeInPython\Experiment8\DH_KEY\PublicA.txt', 'w')
    pkB = open(r'E:\CryptoCode\CodeInPython\Experiment8\DH_KEY\PublicB.txt', 'w')

    secret = open(
        r'E:\CryptoCode\CodeInPython\Experiment8\DH_KEY\Secret.txt', 'w')

    label1 = '------------------------------------Private Key------------------------------------\n'
    label2 = '----------------------------------Private Key End----------------------------------\n'
    label3 = '-------------------------------------Public A--------------------------------------\n'
    label4 = '-------------------------------------Public B--------------------------------------\n'
    label5 = '-------------------------------Secret Decrypted By A-------------------------------\n'
    label6 = '-------------------------------Secret Decrypted By B-------------------------------\n'
    label7 = '----------------------------------------end----------------------------------------\n'

    curve = ECC.EllipticCurve(p, n, a, b, gx, gy)

    DH_A = DH.DiffieHellman(curve)
    DH_B = DH.DiffieHellman(curve)

    na = DH_A.KeyGen()
    nb = DH_A.KeyGen()
    skA.write(label1 + hex(na)[2:] + '\n' + label2)
    skB.write(label1 + hex(nb)[2:] + '\n' + label2)

    pa = DH_A.Encrypt(na)
    pb = DH_B.Encrypt(nb)
    pkA.write(label3 + pa.encode() + '\n' + label7)
    pkB.write(label4 + pb.encode() + '\n' + label7)

    sa = DH_A.Decrypt(na, pb)
    sb = DH_B.Decrypt(nb, pa)

    secret.write(label5 + sa.encode() + '\n' + label6 + sb.encode() + '\n' + label7)
