def str_to_hex(s):
    return ''.join([hex(ord(c))[2:].zfill(2) for c in s])

def str_to_int(s):
    return int(str_to_hex(s), 16)

def int_to_byte(n):
    nhex = hex(n)[2:]
    while len(nhex) % 2 != 0:
        nhex = '0' + nhex
    return int.to_bytes(n, len(nhex) // 2, byteorder='big')

def int_to_str(n):
    return int_to_byte(n).decode('ascii')

def hex_to_chr(h):
    return int_to_str(int(h, 16))