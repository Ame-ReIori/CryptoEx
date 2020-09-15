import time
import box

'''
	author: Ame_ReIori.Guan.YeWei
	complete date: 3/22/2019

	input: 16 bits text in hex code
	output: 16 bits text in hex code
''' 

def h2b(h):
	'''
		input: n bits text in hex code
		output: 4n bits text in binary code

		turn hex into bin
	'''
	return bin(int(h,16))[2:].zfill(len(h)*4)

def b2h(b):
	'''
		input: 4n bits text in binary code
		output: n bits text in hex code

		turn hex into bin
	'''
	return hex(int(b,2))[2:].zfill(len(b)//4)

def ip(text):
	'''
		input: 64 bits text in binary code
		output: 64 bits text in binary code

		replace letters in text according to IP
	'''
	result = ''
	for i in box.IP:
		tempBin = text[i-1]
		result += tempBin

	return result

def ip_inverse(text):
	'''
		input: 64 bits text in binary code
		output: 64 bits text in binary code

		replace letters in text according to IP_INVERSE
	'''
	result = ''
	for i in box.IP_INVERSE: 
		tempBin = text[i-1]
		result += tempBin

	return result

def e(text):
	'''
		input: 32 bits text in binary code
		output: 48 bits text in binary code

		extend the input from 32->48 bits (in binary code)
	'''
	result = ''
	for i in box.E:
		tempBin = text[i-1]
		result += tempBin

	return result

def s(text):
	'''
		input: 48 bits text in binary code
		output: 32 bits text in binary code

		zip the text from 48->32 bits (in binary code) 
	'''
	text_list = []
	#divide the text into 8 parts
	for k in range(8):
		tempText = text[6*k:6*(k+1)]
		tempText = tempText
		text_list.append(tempText)

	result = ''
	#input each text in text_list into S_box
	#each output 4 bits
	#finally get 32 bits text

	for i in range(len(text_list)):
		tempResult = replace_by_S(text_list[i],box.S[i])
		result += tempResult

	return result



def p(text):
	'''
		input: 32 bits text in binary code
		output: 32 bits text in binary code

		replace letters according to P
	'''
	result = ''
	for i in box.P:
		tempCh = text[i-1]
		result += tempCh
	return result

def replace_by_S(text, S):
	'''
		input: 6 bits text in binary code
			   S_box
		output: 4 bits text in binary code

		zip the code 6->4
	'''
	#choose row and col

	row = int(text[0]+text[-1],2)
	col = int(text[1:-1],2)

	index = 16 * row + col

	result = bin(S[index])[2:].zfill(4)

	return result

def replace(text, box):
	'''
		input: 64 bits text in binary code 
			   box
		output: 64 bits text in binary code

		replace letters in text according to box PC_1 and PC_2
	'''
	result = ''
	for i in box:
		tempCh = text[i-1]
		result += tempCh
	return result

def xor(a, b):
	'''
		input: two string with the same length in binary code
		output: xor stirng
	'''

	result = ''
	for i in range(len(a)):
		tempBin = bin(int(a[i])^int(b[i]))[2:]
		result += tempBin
	return result


def generate_Ki(key):
	'''
		input: 64 bits key in binary code
		output: a list which stores sub_keys in binary code with 48 bits

		generate sub_keys according to PC_1, L, PC_2
	'''
	ki_list = []
	updateKey = [] #store the temp Ki

	#delete parity bit
	key = replace(key, box.PC_1)

	tempKey = key
	for i in range(16):
		left = tempKey[:28]
		right = tempKey[28:]
		shift = box.L[i] #shift number

		#left shift
		left = left[shift:] + left[:shift]
		right = right[shift:] + right[:shift]

		tempKey = left + right

		updateKey = replace(tempKey, box.PC_2)

		ki_list.append(updateKey)

	return ki_list


def encode(m, key):
	'''
		input: 16 bits text in hex code
			   16 bits key in hex code
		output: 16 bits text in hex code

		DES encode
	'''
	#ip(m)
	m = h2b(m)
	key = h2b(key)
	ki_list = generate_Ki(key)
	m = ip(m)
	L = m[:32]
	R = m[32:]

	#start 16 iteration
	for i in range(16):
		tempL = L
		L = R
		R = e(R)
		R = xor(R, ki_list[i])
		R = s(R)
		R = p(R)
		R = xor(tempL, R)

	result = R + L

	result = ip_inverse(result)

	return b2h(result)


def decode(c, key):
	'''
		input: 16 bits text in hex code
			   16 bits key in hex code
		output: 16 bits text in hex code

		DES decode
	'''
	#ip(c)
	c = h2b(c)
	key = h2b(key)
	ki_list = generate_Ki(key)
	c = ip(c)
	L = c[:32]
	R = c[32:]

	#start 16 iteration
	for i in range(16):
		tempL = L
		L = R
		R = e(R)
		R = xor(R, ki_list[15 - i])
		R = s(R)
		R = p(R)
		R = xor(tempL, R)

	result = R + L

	result = ip_inverse(result)

	return b2h(result)


def main():
	print('Please choose your operation: 1、encode 2、decode')
	op = eval(input())
	if op == 1:
		m = input('Please input your message: ')
		key = input('Please input your key: ')
		time_start = time.perf_counter()
		c = encode(m, key)
		time_end = time.perf_counter()
		print('The ciphertext is:' + c)
		print('time cost:',time_end - time_start,'s')
	elif op == 2:
		c = input('Please input your ciphertext: ')
		key = input('Please input your key: ')
		time_start = time.perf_counter()
		m = decode(c, key)
		time_end = time.perf_counter()
		print('The message is:' + m)
		print('time cost:',time_end - time_start,'s')

if __name__ == '__main__':
	main()

	input()