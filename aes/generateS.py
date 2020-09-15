'''
used to generate S box
'''

import FiniteField_8
k = [[1, 0, 0, 0, 1, 1, 1, 1],
     [1, 1, 0, 0, 0, 1, 1, 1],
     [1, 1, 1, 0, 0, 0, 1, 1],
     [1, 1, 1, 1, 0, 0, 0, 1],
     [1, 1, 1, 1, 1, 0, 0, 0],
     [0, 1, 1, 1, 1, 1, 0, 0],
     [0, 0, 1, 1, 1, 1, 1, 0],
     [0, 0, 0, 1, 1, 1, 1, 1]]

k_inverse = [[0, 0, 1, 0, 0, 1, 0, 1],
             [1, 0, 0, 1, 0, 0, 1, 0],
             [0, 1, 0, 0, 1, 0, 0, 1],
             [1, 0, 1, 0, 0, 1, 0, 0],
             [0, 1, 0, 1, 0, 0, 1, 0],
             [0, 0, 1, 0, 1, 0, 0, 1],
             [1, 0, 0, 1, 0, 1, 0, 0],
             [0, 1, 0, 0, 1, 0, 1, 0]]


def matrixMul(a, b):
    result = []
    for i in range(len(a)):
        temp = []
        for j in range(len(b[0])):
            tempNum = 0
            for k in range(len(a[i])):
                tempNum += int(a[i][k]) * int(b[k][j])
                tempNum = tempNum % 2
            temp.append(tempNum)
        result.append(temp)
    return result


def xor(a, b):
    # len(a) == len(b)
    result = ''
    for i in range(len(a)):
        temp = str(int(a[i]) ^ int(b[i]))
        result += temp
    return result


c = '01100011'
c_inverse = '00000101'
mx = '100011011'


def generate_S_inverse():
    count = 0
    tempRow = []
    S_inverse = []
    for i in range(2**8):
        # convert byte to binary code
        # to calculate inverse
        count += 1
        byte = bin(i)[2:].zfill(8)[::-1]
        byte_sub = []
        for m in byte:
            byte_sub.append(list(m))
        byte_sub = matrixMul(k_inverse, byte_sub)
        byte = ''
        for p in byte_sub:
            for q in p:
                byte += str(q)
        byte = xor(byte, c_inverse[::-1])
        byte = byte[::-1]
        byte = FiniteField_8.xInverse(byte, mx).zfill(8)
        byte = hex(int(byte, 2))[2:].zfill(2)
        tempRow.append(byte)
        if count % 16 == 0:
            S_inverse.append(tempRow)
            tempRow = []
    return S_inverse


def generate_S():
    count = 0
    tempRow = []
    S = []
    for i in range(2**8):
        # convert byte to binary code
        # to calculate inverse
        count += 1
        byte = bin(i)[2:].zfill(8)
        byte = FiniteField_8.xInverse(byte, mx).zfill(8)[::-1]
        byte_sub = []
        for m in byte:
            byte_sub.append(list(m))
        byte_sub = matrixMul(k, byte_sub)
        byte = ''
        for p in byte_sub:
            for q in p:
                byte += str(q)
        byte = xor(byte, c[::-1])
        byte = hex(int(byte[::-1], 2))[2:].zfill(2)
        tempRow.append(byte)
        if count % 16 == 0:
            S.append(tempRow)
            tempRow = []
    return S


if __name__ == "__main__":
    s = generate_S()
    print('s = ')
    for p in s:
        print(p)
    s_inverse = generate_S_inverse()
    print('s_inverse = ')
    for q in s_inverse:
        print(q)
