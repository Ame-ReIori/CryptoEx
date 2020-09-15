import time
import FiniteField_8

S = [['63', '7c', '77', '7b', 'f2', '6b', '6f', 'c5', '30', '01', '67', '2b', 'fe', 'd7', 'ab', '76'],
     ['ca', '82', 'c9', '7d', 'fa', '59', '47', 'f0',
         'ad', 'd4', 'a2', 'af', '9c', 'a4', '72', 'c0'],
     ['b7', 'fd', '93', '26', '36', '3f', 'f7', 'cc',
         '34', 'a5', 'e5', 'f1', '71', 'd8', '31', '15'],
     ['04', 'c7', '23', 'c3', '18', '96', '05', '9a',
         '07', '12', '80', 'e2', 'eb', '27', 'b2', '75'],
     ['09', '83', '2c', '1a', '1b', '6e', '5a', 'a0',
         '52', '3b', 'd6', 'b3', '29', 'e3', '2f', '84'],
     ['53', 'd1', '00', 'ed', '20', 'fc', 'b1', '5b',
         '6a', 'cb', 'be', '39', '4a', '4c', '58', 'cf'],
     ['d0', 'ef', 'aa', 'fb', '43', '4d', '33', '85',
         '45', 'f9', '02', '7f', '50', '3c', '9f', 'a8'],
     ['51', 'a3', '40', '8f', '92', '9d', '38', 'f5',
         'bc', 'b6', 'da', '21', '10', 'ff', 'f3', 'd2'],
     ['cd', '0c', '13', 'ec', '5f', '97', '44', '17',
         'c4', 'a7', '7e', '3d', '64', '5d', '19', '73'],
     ['60', '81', '4f', 'dc', '22', '2a', '90', '88',
         '46', 'ee', 'b8', '14', 'de', '5e', '0b', 'db'],
     ['e0', '32', '3a', '0a', '49', '06', '24', '5c',
         'c2', 'd3', 'ac', '62', '91', '95', 'e4', '79'],
     ['e7', 'c8', '37', '6d', '8d', 'd5', '4e', 'a9',
         '6c', '56', 'f4', 'ea', '65', '7a', 'ae', '08'],
     ['ba', '78', '25', '2e', '1c', 'a6', 'b4', 'c6',
         'e8', 'dd', '74', '1f', '4b', 'bd', '8b', '8a'],
     ['70', '3e', 'b5', '66', '48', '03', 'f6', '0e',
         '61', '35', '57', 'b9', '86', 'c1', '1d', '9e'],
     ['e1', 'f8', '98', '11', '69', 'd9', '8e', '94',
         '9b', '1e', '87', 'e9', 'ce', '55', '28', 'df'],
     ['8c', 'a1', '89', '0d', 'bf', 'e6', '42', '68', '41', '99', '2d', '0f', 'b0', '54', 'bb', '16']]

S_INVERSE = [['52', '09', '6a', 'd5', '30', '36', 'a5', '38', 'bf', '40', 'a3', '9e', '81', 'f3', 'd7', 'fb'],
             ['7c', 'e3', '39', '82', '9b', '2f', 'ff', '87',
                 '34', '8e', '43', '44', 'c4', 'de', 'e9', 'cb'],
             ['54', '7b', '94', '32', 'a6', 'c2', '23', '3d',
                 'ee', '4c', '95', '0b', '42', 'fa', 'c3', '4e'],
             ['08', '2e', 'a1', '66', '28', 'd9', '24', 'b2',
                 '76', '5b', 'a2', '49', '6d', '8b', 'd1', '25'],
             ['72', 'f8', 'f6', '64', '86', '68', '98', '16',
                 'd4', 'a4', '5c', 'cc', '5d', '65', 'b6', '92'],
             ['6c', '70', '48', '50', 'fd', 'ed', 'b9', 'da',
                 '5e', '15', '46', '57', 'a7', '8d', '9d', '84'],
             ['90', 'd8', 'ab', '00', '8c', 'bc', 'd3', '0a',
                 'f7', 'e4', '58', '05', 'b8', 'b3', '45', '06'],
             ['d0', '2c', '1e', '8f', 'ca', '3f', '0f', '02',
                 'c1', 'af', 'bd', '03', '01', '13', '8a', '6b'],
             ['3a', '91', '11', '41', '4f', '67', 'dc', 'ea',
                 '97', 'f2', 'cf', 'ce', 'f0', 'b4', 'e6', '73'],
             ['96', 'ac', '74', '22', 'e7', 'ad', '35', '85',
                 'e2', 'f9', '37', 'e8', '1c', '75', 'df', '6e'],
             ['47', 'f1', '1a', '71', '1d', '29', 'c5', '89',
                 '6f', 'b7', '62', '0e', 'aa', '18', 'be', '1b'],
             ['fc', '56', '3e', '4b', 'c6', 'd2', '79', '20',
                 '9a', 'db', 'c0', 'fe', '78', 'cd', '5a', 'f4'],
             ['1f', 'dd', 'a8', '33', '88', '07', 'c7', '31',
                 'b1', '12', '10', '59', '27', '80', 'ec', '5f'],
             ['60', '51', '7f', 'a9', '19', 'b5', '4a', '0d',
                 '2d', 'e5', '7a', '9f', '93', 'c9', '9c', 'ef'],
             ['a0', 'e0', '3b', '4d', 'ae', '2a', 'f5', 'b0',
                 'c8', 'eb', 'bb', '3c', '83', '53', '99', '61'],
             ['17', '2b', '04', '7e', 'ba', '77', 'd6', '26', 'e1', '69', '14', '63', '55', '21', '0c', '7d']]


def xor(a, b):
    # len(a) == len(b)
    length = len(a)
    a = bin(int(a, 16))[2:].zfill(length * 4)
    b = bin(int(b, 16))[2:].zfill(length * 4)
    result = ''
    for i in range(len(a)):
        result += str(int(a[i]) ^ int(b[i]))
    return hex(int(result, 2))[2:].zfill(length)


def ByteSub(state, box):
    '''
        input: a 4*4 list as a matrix method
        output: a 4*4 list as a matrix method
    '''
    for i in range(len(state)):
        for j in range(len(state[i])):
            row = int(state[i][j][0], 16)
            col = int(state[i][j][1], 16)
            state[i][j] = box[row][col]
    return state


def IByteSub(state, box):
    '''
        input: a 4*4 list as a matrix method
        output: a 4*4 list as a matrix method
    '''
    for i in range(len(state)):
        for j in range(len(state[i])):
            row = int(state[i][j][0], 16)
            col = int(state[i][j][1], 16)
            state[i][j] = box[row][col]
    return state


def AddRoundKey(state, key):
    for i in range(len(state)):
        for j in range(len(state[i])):
            state[i][j] = xor(state[i][j], key[i][j])
    return state


def ShiftRow(state):
    for i in range(len(state)):
        for j in range(i, len(state[i])):
            state[i][j], state[j][i] = state[j][i], state[i][j]
    for shift in range(4):
        state[shift] = state[shift][shift:] + state[shift][:shift]
    for i in range(len(state)):
        for j in range(i, len(state[i])):
            state[i][j], state[j][i] = state[j][i], state[i][j]
    return state


def IShiftRow(state):
    '''
        calculate a^T first
    '''
    for i in range(len(state)):
        for j in range(i, len(state[i])):
            state[i][j], state[j][i] = state[j][i], state[i][j]
    for shift in range(4):
        state[shift] = state[shift][4 - shift:] + state[shift][:4 - shift]
    for i in range(len(state)):
        for j in range(i, len(state[i])):
            state[i][j], state[j][i] = state[j][i], state[i][j]
    return state


def MixColumn(state):
    M = [['02', '03', '01', '01'], ['01', '02', '03', '01'],
         ['01', '01', '02', '03'], ['03', '01', '01', '02']]
    mx = '100011011'
    result = []
    for i in range(len(state)):
        tempCol = []
        for j in range(len(M)):
            temp = '00'
            for k in range(len(M[j])):
                calM = bin(int(M[j][k], 16))[2:].zfill(8)
                calByte = bin(int(state[i][k], 16))[2:].zfill(8)
                cal = hex(int(FiniteField_8.mul(calM, calByte, mx), 2))[
                    2:].zfill(2)
                temp = xor(temp, cal)
            tempCol.append(temp)
        result.append(tempCol)
    return result


def IMixColumn(state):
    M = [['0e', '0b', '0d', '09'], ['09', '0e', '0b', '0d'],
         ['0d', '09', '0e', '0b'], ['0b', '0d', '09', '0e']]
    mx = '100011011'
    result = []
    for i in range(len(state)):
        tempCol = []
        for j in range(len(M)):
            temp = '00'
            for k in range(len(M[j])):
                calM = bin(int(M[j][k], 16))[2:].zfill(8)
                calByte = bin(int(state[i][k], 16))[2:].zfill(8)
                cal = hex(int(FiniteField_8.mul(calM, calByte, mx), 2))[
                    2:].zfill(2)
                temp = xor(temp, cal)
            tempCol.append(temp)
        result.append(tempCol)
    return result


def KeyExpansion(key):
    Rcon = [['01', '00', '00', '00'],
            ['02', '00', '00', '00'],
            ['04', '00', '00', '00'],
            ['08', '00', '00', '00'],
            ['10', '00', '00', '00'],
            ['20', '00', '00', '00'],
            ['40', '00', '00', '00'],
            ['80', '00', '00', '00'],
            ['1b', '00', '00', '00'],
            ['36', '00', '00', '00']]
    w = []
    for i in range(4):
        w.append(key[i])
    for i in range(4, 44):
        tempRow = []
        temp = w[i - 1]  # a list
        if i % 4 == 0:
            temp = temp[1:] + temp[:1]
            temp = [temp]  # temp should be a matrix
            temp = ByteSub(temp, S)
            # return a matrix with 1 row and 4 columns
            for p in range(len(temp[0])):
                temp[0][p] = xor(temp[0][p], Rcon[i // 4 - 1][p])
        else:
            temp = [temp]
        for m in range(4):
            tempRow.append(xor(w[i - 4][m], temp[0][m]))
        w.append(tempRow)
    return w


def init(m, key):
    '''
        consider row as columns of state and key
    '''
    mMatrix = []
    keyMatrix = []
    tempMRow = []
    tempKeyRow = []
    for i in range(0, len(m), 2):
        tempM = m[i] + m[i + 1]
        tempKey = key[i] + key[i + 1]
        tempMRow.append(tempM)
        tempKeyRow.append(tempKey)
        if (i + 2) % 8 == 0:
            mMatrix.append(tempMRow)
            keyMatrix.append(tempKeyRow)
            tempMRow = []
            tempKeyRow = []
    return (mMatrix, keyMatrix)


def encode(m, key):
    r = 10
    state, key = init(m, key)
    key = KeyExpansion(key)
    cipherText = ''
    RoundKey = []
    tempRoundKey = []
    for i in range(len(key)):
        tempRoundKey.append(key[i])
        if (i + 1) % 4 == 0:
            RoundKey.append(tempRoundKey)
            tempRoundKey = []
    state = AddRoundKey(state, RoundKey[0])
    for count in range(1, r):
        state = ByteSub(state, S)
        state = ShiftRow(state)
        state = MixColumn(state)
        state = AddRoundKey(state, RoundKey[count])
    state = ByteSub(state, S)
    state = ShiftRow(state)
    state = AddRoundKey(state, RoundKey[count + 1])
    for p in state:
        for q in p:
            cipherText += q
    return cipherText


def decode(c, key):
    r = 10
    state, key = init(c, key)
    key = KeyExpansion(key)
    plainText = ''
    RoundKey = []
    tempRoundKey = []
    for i in range(len(key)):
        tempRoundKey.append(key[i])
        if (i + 1) % 4 == 0:
            RoundKey.append(tempRoundKey)
            tempRoundKey = []
    state = AddRoundKey(state, RoundKey[r])
    for count in range(1, r):
        state = IShiftRow(state)
        state = IByteSub(state, S_INVERSE)
        state = AddRoundKey(state, RoundKey[r - count])
        state = IMixColumn(state)
    state = IShiftRow(state)
    state = IByteSub(state, S_INVERSE)
    state = AddRoundKey(state, RoundKey[0])
    for p in state:
        for q in p:
            plainText += q
    return plainText


def main():
    print('Please choose your operation: 1.encryption 2.decryption')
    op = input()
    if op == '1':
        mText = open(r'E:\CryptoCode\CodeInPython\Experiment5\AES\plaintext.txt', 'r')
        keyText = open(r'E:\CryptoCode\CodeInPython\Experiment5\AES\key.txt', 'r')
        cipherText = open(r'E:\CryptoCode\CodeInPython\Experiment5\AES\cipherText.txt', 'w')
        m = mText.read()
        key = keyText.read()
        start = time.time()
        c = encode(m, key)
        end = time.time()
        cipherText.write(c)
        print('time cost: ', end - start, 's')
        mText.close()
        keyText.close()
        cipherText.close()
    elif op == '2':
        mText = open(r'E:\CryptoCode\CodeInPython\Experiment5\AES\decode_plaintext.txt', 'w')
        keyText = open(r'E:\CryptoCode\CodeInPython\Experiment5\AES\key.txt', 'r')
        cipherText = open(r'E:\CryptoCode\CodeInPython\Experiment5\AES\cipherText.txt', 'r')
        c = cipherText.read()
        key = keyText.read()
        start = time.time()
        m = decode(c, key)
        end = time.time()
        mText.write(m)
        print('time cost: ', end - start, 's')
        mText.close()
        keyText.close()
        cipherText.close()
    return


if __name__ == "__main__":
    main()

    input()
    