def str_to_hex(s):
    return ''.join([hex(ord(c))[2:].zfill(2) for c in s])

def str_to_int(s):
    return int(str_to_hex(s), 16)

def int_to_byte(n):
    result = b''
    nhex = hex(n)[2:]
    if len(nhex) % 2 != 0:
        nhex = '0' + nhex
    for i in range(0, len(nhex), 2):
        temp = nhex[i] + nhex[i + 1]
        tempbyte = int.to_bytes(int(temp, 16), 1, 'big')
        result += tempbyte
    return result

def int_to_str(n):
    return int_to_byte(n).decode('ascii')

def hex_to_chr(h):
    return int_to_str(int(h, 16))

def str_to_byte(s):
    return s.encode('utf-8')