import time

# eg. fx = '1001' gx = '1011'
# input: str
# output: str
# add by xor


def add(fx, gx):
    length = len(fx) if len(fx) > len(gx) else len(gx)
    fx = fx.zfill(length)
    gx = gx.zfill(length)
    hx = ''
    for i in range(length):
        hx += str(int(fx[i]) ^ int(gx[i]))
    return hx

# mx = '100011011'
# input: str
# output: str


def mul(fx, gx, mx):
    fx = fx.zfill(8)
    gx = gx.zfill(8)
    resultList = []  # store the result of fx x 0x01,0x02,...,0x80

    # the first result need to be added
    # fx x 0x01 = fx
    resultList.append(fx)

    for i in range(1, 8):
        if(resultList[i - 1][0] == '0'):
            addNum = bin(int(resultList[i - 1], 2) << 1)[2:].zfill(8)
        else:
            tempNum = bin(int(resultList[i - 1], 2) << 1)[3:]
            mNum = int(mx[1:], 2)  # int of mx
            addNum = bin(int(tempNum, 2) ^ mNum)[2:].zfill(8)
        resultList.append(addNum)

    result = 0b00000000

    gxNum = int(gx, 2)
    j = 0
    while gxNum > 0:
        if(gxNum & 1):
            result = result ^ int(resultList[j], 2)
        j += 1
        gxNum >>= 1

    return bin(result)[2:].zfill(8)

# ax mod bx
# make sure len(ax) > len(bx)
# input: str
# output: list


def divAndmod(ax, bx):
    result = []
    divNum = 0
    ax = str(int(ax))
    bx = str(int(bx))
    while len(ax) >= len(bx):

        level = len(ax) - len(bx)
        # print('level=',level)
        addNum = 1
        divNum += (addNum << level)

        for i in range(len(bx)):
            # change ax
            a = list(ax)
            a[i] = str(int(ax[i]) ^ int(bx[i]))
            ax = ''.join(a)

        k = 0
        for j in range(len(ax)):
            if ax[j] == '0':
                k += 1
            else:
                break
        ax = ax[k:]

        # print('ax=',ax)

    divNum = bin(divNum)[2:]

    if ax == '':
        ax = '0'
    if divNum == '':
        divNum = '0'

    result.append(divNum)
    result.append(ax)
    return result


def divF(ax, bx):
    return divAndmod(ax, bx)[0]


def mod(ax, bx):
    return divAndmod(ax, bx)[1]


def exGCDGF(ax, bx):

    m = ax
    if(bx == '0'):
        return ('1', '0', ax)
    (x, y, r) = exGCDGF(bx, mod(ax, bx))
    qx = divF(ax, bx)
    temp = x
    x = y
    y = add(temp, mul(qx, y, m))
    return (x, y, r)


def xInverse(ax, mx):
    return exGCDGF(ax, mx)[0]


def div(ax, bx, mx):
    return mul(ax, xInverse(bx, mx), mx)


if __name__ == '__main__':
    mx = '100011011'
    print('Please choose you operation, you can choose add/minus, multiply, mod, inverse, div(please input as mentioned above):\n')
    while True:
        op = input()
        if op == 'add/minus':
            fx = input('Please input you data in the method of poly:')
            gx = input('Please input you data in the method of poly:')
            time_start = time.perf_counter()

            print('The result is ', add(fx, gx))

            time_end = time.perf_counter()
            print('time cost:', time_end - time_start, 's')
        elif op == 'multiply':
            fx = input('Please input you data in the method of poly:')
            gx = input('Please input you data in the method of poly:')
            time_start = time.perf_counter()

            print('The result is ', mul(fx, gx, mx))
            time_end = time.perf_counter()
            print('time cost:', time_end - time_start, 's')
        elif op == 'mod':
            fx = input('Please input you data in the method of poly:')
            gx = input('Please input you data in the method of poly:')
            time_start = time.perf_counter()

            print('The result is ', mod(fx, gx))
            time_end = time.perf_counter()
            print('time cost:', time_end - time_start, 's')
        elif op == 'inverse':
            x = input('Please input you data in the method of poly:')
            time_start = time.perf_counter()

            print('The result is ', xInverse(x, mx))
            time_end = time.perf_counter()
            print('time cost:', time_end - time_start, 's')
        elif op == 'div':
            time_start = time.perf_counter()
            fx = input('Please input you data in the method of poly:')
            gx = input('Please input you data in the method of poly:')
            time_start = time.perf_counter()

            print('The result is ', div(fx, gx, mx))
            time_end = time.perf_counter()
            print('time cost:', time_end - time_start, 's')
        else:
            print('Incorrect input, please do it again')
