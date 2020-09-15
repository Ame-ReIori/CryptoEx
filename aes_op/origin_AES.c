#include "init_S_box.h"
#include "calOnGF28.h"
#include<stdlib.h>
#include<time.h>
#include<windows.h>
/*
	input: plaintext -- hex code(32 length) -- char [32] 
		   key -- hex code(32 length) -- char [32]
	output: ciphertext -- hex code(32 length) -- char [32]
*/
/*
typedef union{
	struct
	{
		DWORD LowPart;
		LONG HighPart;
	};
	LONGLONG QuadPart;
}LARGE_INTEGER;
*/
extern unsigned char S[16][16];
extern unsigned char S_INV[16][16];
unsigned char state[4][4] = { 0x00 };
unsigned char key_state[4][4] = { 0x00 };
unsigned char RoundKey_list[44][4] = { 0x00 };
unsigned char state_byte[4][4] = { 0x00 };
unsigned char key_state_byte[4][4] = { 0x00 };

void print_4(unsigned char box[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			print_hex(box[i][j]);
		}
		printf("\n");
	}
}

void print_44_4(unsigned char box[44][4]) {
	for (int i = 0; i < 44; i++) {
		for (int j = 0; j < 4; j++) {
			print_hex(box[i][j]);
		}
		printf("\n");
	}
}
/*
void convertStrToUnChar(char* str, unsigned char* UnChar)
{
	int i = strlen(str), j = 0, counter = 0;
	char c[2];
	unsigned int bytes;

	for (j = 0; j < i; j += 2){
		if (0 == j % 2){
			c[0] = str[j];
			c[1] = str[j + 1];
			sscanf(c, "%02x", &bytes);
			UnChar[counter] = bytes;
			counter++;
		}
	}
	return;
}
*/

void ByteSub() {
	int n = 0;
	int b[8] = { 0,0,0,0,0,0,0,0 };
	int c[8] = { 1,1,0,0,0,1,1,0 };
	int tempState[8] = { 0,0,0,0,0,0,0,0 };
	unsigned char temp = 0x00;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp = 0x00;
			if (state[i][j] != 0x00) {
				temp = GF28_inv(state[i][j]);
			}
			state[i][j] = 0x00;
			while (temp != 0) {
				b[n] = temp % 2;
				temp /= 2;
				n += 1;
			}
			for (int k = 0; k < 8; k++) {
				tempState[k] = b[k] ^ b[(k + 4) % 8] ^ b[(k + 5) % 8] ^ b[(k + 6) % 8] ^ b[(k + 7) % 8] ^ c[k];
				if (tempState[k] & 1) {
					state[i][j] ^= (1 << k);
				}
			}
			b[0] = b[1] = b[2] = b[3] = b[4] = b[5] = b[6] = b[7] = 0;
			n = 0;
		}
	}
}

void IByteSub() {
	int n = 0;
	int b[8] = { 0,0,0,0,0,0,0,0 };
	int d[8] = { 1,0,1,0,0,0,0,0 };
	int tempState[8] = { 0,0,0,0,0,0,0,0 };
	unsigned char temp = 0x00;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp = state[i][j];
			while (temp != 0) {
				b[n] = temp % 2;
				temp /= 2;
				n += 1;
			}
			temp = 0x00;
			for (int k = 0; k < 8; k++) {
				tempState[k] = b[(k + 2) % 8] ^ b[(k + 5) % 8] ^ b[(k + 7) % 8] ^ d[k];
				if (tempState[k] & 1) {
					temp ^= (1 << k);
				}
			}
			if (temp != 0x00) {
				temp = GF28_inv(temp);
			}
			state[i][j] = temp;
			b[0] = b[1] = b[2] = b[3] = b[4] = b[5] = b[6] = b[7] = 0;
			n = 0;
		}
	}
}


void ByteSubByBox(unsigned char box[16][16]) {
	int row = 0, col = 0;
	unsigned char temp = 0x00;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp = state[i][j];
			row = temp >> 4;
			temp = temp << 4;
			col = temp >> 4;
			state[i][j] = box[row][col];
		}
	}
}

void AddRoundKey(unsigned char RoundKey[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			state[i][j] ^= RoundKey[i][j];
		}
	}
}

void ShiftRow() {
	unsigned char temp = 0x00;
	
	// the second row
	temp = state[1][0]; 
	state[1][0] = state[1][1]; 
	state[1][1] = state[1][2]; 
	state[1][2] = state[1][3]; 
	state[1][3] = temp;

	//the third row
	temp = state[2][0]; 
	state[2][0] = state[2][2]; 
	state[2][2] = temp; 
	temp = state[2][1];
	state[2][1] = state[2][3]; 
	state[2][3] = temp;

	//the forth row
	temp = state[3][3]; 
	state[3][3] = state[3][2]; 
	state[3][2] = state[3][1]; 
	state[3][1] = state[3][0]; 
	state[3][0] = temp;
	return;
}

void IShiftRow() {
	unsigned char temp = 0x00;

	// the second row
	temp = state[1][3];
	state[1][3] = state[1][2];
	state[1][2] = state[1][1];
	state[1][1] = state[1][0];
	state[1][0] = temp;

	//the third row
	temp = state[2][0];
	state[2][0] = state[2][2];
	state[2][2] = temp;
	temp = state[2][1];
	state[2][1] = state[2][3];
	state[2][3] = temp;

	//the forth row
	temp = state[3][0];
	state[3][0] = state[3][1];
	state[3][1] = state[3][2];
	state[3][2] = state[3][3];
	state[3][3] = temp;
	return;
}

void MixColumn() {
	unsigned char M[4][4] = { { 0x02,0x03,0x01,0x01 }, 
							  { 0x01,0x02,0x03,0x01 }, 
							  { 0x01,0x01,0x02,0x03 }, 
							  { 0x03,0x01,0x01,0x02 } };
	unsigned char calMatrix[4][4] = { 0x00 };
	unsigned char temp = 0x00;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			calMatrix[i][j] = state[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp = 0x00;
			for (int k = 0; k < 4; k++) {
				temp ^= GF28_mul(calMatrix[k][j], M[i][k]);
			}
			state[i][j] = temp;
		}
	}
}

void IMixColumn() {
	unsigned char M[4][4] = { { 0x0e,0x0b,0x0d,0x09 },
							  { 0x09,0x0e,0x0b,0x0d },
							  { 0x0d,0x09,0x0e,0x0b },
							  { 0x0b,0x0d,0x09,0x0e } };
	unsigned char calMatrix[4][4] = { 0x00 };
	unsigned char temp = 0x00;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			calMatrix[i][j] = state[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp = 0x00;
			for (int k = 0; k < 4; k++) {
				temp ^= GF28_mul(calMatrix[k][j], M[i][k]);
			}
			state[i][j] = temp;
		}
	}
}

void KeyExpansion() {
	unsigned char Rcon[10] = { 0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x1b,0x36 };
	unsigned char temp[4] = { 0x00 };
	unsigned char rotTemp = 0x00;
	int row = 0, col = 0;
	int i = 0, j = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			RoundKey_list[i][j] = key_state[i][j];
		}
	}
	for (i = 4; i < 44; i++) {
		for (j = 0; j < 4; j++) {
			temp[j] = RoundKey_list[(i - 1) / 4 * 4 + j][(i - 1) % 4];
		}
		if (i % 4 == 0) {
			rotTemp = temp[0];
			temp[0] = temp[1];
			temp[1] = temp[2];
			temp[2] = temp[3];
			temp[3] = rotTemp;
			for (j = 0; j < 4; j++) {
				row = temp[j] >> 4;
				temp[j] <<= 4;
				col = temp[j] >> 4;
				temp[j] = S[row][col];
			}
			temp[0] ^= Rcon[i / 4 - 1];
		}
		// i % 4
		for (j = 0; j < 4; j++) {
			RoundKey_list[i / 4 * 4 + j][i % 4] = RoundKey_list[(i / 4 - 1) * 4 + j][i % 4] ^ temp[j];
		}
		
	}
}

void init(char *plainText, char *key) {
	int i = strlen(plainText);
	int row = 0, col = 0;
	char tempM[2], tempK[2];
	unsigned int byte_m, byte_key;
	for (int j = 0; j < i; j++) {
		if (j % 2 == 0) {
			tempM[0] = plainText[j];
			tempM[1] = plainText[j + 1];
			tempK[0] = key[j];
			tempK[1] = key[j + 1];
			sscanf(tempM, "%02x", &byte_m);
			sscanf(tempK, "%02x", &byte_key);
			state[row][col] = byte_m;
			key_state[row][col] = byte_key;
			row++;
			col += row / 4;
			row %= 4;	
		}
	}
	return;
}

char *encrypt(char *plainText, char *key) {
	unsigned char RoundKey[4][4] = { 0x00 };
	char *cipherText = (char *)malloc(33 * sizeof(char));
/*
	LARGE_INTEGER num;
	long long start_init, end_init;
	long long start_add, end_add;
	long long start_byte, end_byte;
	long long start_shift, end_shift;
	long long start_mix, end_mix;
	long long start_key, end_key;
	long long freq;
*/
	int round = 10;
/*
	QueryPerformanceFrequency(&num);
	freq = num.QuadPart;
	QueryPerformanceCounter(&num);
	start_init = num.QuadPart;
*/
	init(plainText, key);

/*	QueryPerformanceCounter(&num);
	end_init = num.QuadPart;
	printf("time_init=%lldus\n", (end_init - start_init) * 1000000000 / freq);

	QueryPerformanceFrequency(&num);
	freq = num.QuadPart;
	QueryPerformanceCounter(&num);
	start_key = num.QuadPart;*/
	KeyExpansion();
/*	QueryPerformanceCounter(&num);
	end_key = num.QuadPart;
	printf("time_key=%lldus\n", (end_key - start_key) * 1000000000 / freq);*/
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			RoundKey[i][j] = RoundKey_list[i][j];
		}
	}
	AddRoundKey(RoundKey);
	for (int k = 1; k < round; k++) {
		ByteSubByBox(S);
		ShiftRow();
		MixColumn();
		for (int i = 4 * k; i < 4 * (k + 1); i++) {
			for (int j = 0; j < 4; j++) {
				RoundKey[i % 4][j] = RoundKey_list[i][j];
			}
		}
		AddRoundKey(RoundKey);
	}
	ByteSubByBox(S);
	ShiftRow();
	for (int i = 4 * round; i < 4 * (round + 1); i++) {
		for (int j = 0; j < 4; j++) {
			RoundKey[i % 4][j] = RoundKey_list[i][j];
		}
	}
	AddRoundKey(RoundKey);
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			sprintf(cipherText + i * 2 + j * 8, "%02x", state[i][j]);
		}
	}
	return cipherText;
}

char *decrypt(char *cipherText, char *key) {
	unsigned char RoundKey[4][4] = { 0x00 };
	char *plainText = (char *)malloc(33 * sizeof(char));
	int round = 10;
	init(cipherText, key);
	KeyExpansion();
	for (int i = 4 * round; i < 4 * (round + 1); i++) {
		for (int j = 0; j < 4; j++) {
			RoundKey[i % 4][j] = RoundKey_list[i][j];
		}
	}
	AddRoundKey(RoundKey);
	for (int k = round - 1; k > 0; k--) {
		IShiftRow(); 
		ByteSubByBox(S_INV);
		for (int i = 4 * k; i < 4 * (k + 1); i++) {
			for (int j = 0; j < 4; j++) {
				RoundKey[i % 4][j] = RoundKey_list[i][j];
			}
		}
		AddRoundKey(RoundKey);
		IMixColumn();
	}
	IShiftRow(); 
	ByteSubByBox(S_INV);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			RoundKey[i][j] = RoundKey_list[i][j];
		}
	}
	AddRoundKey(RoundKey);
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			sprintf(plainText + i * 2 + j * 8, "%02x", state[i][j]);
		}
	}
	return plainText;
}
/*
int main() {
	FILE *fp, *fk;
	fp = fopen("plaintext.txt", "r");
	fk = fopen("key.txt", "r");
	char *plainText = (char *)malloc(33 * sizeof(char));
	char *key = (char *)malloc(33 * sizeof(char));
	char *cipherText;
//	int row = 0, col = 0;
//	LARGE_INTEGER num;
//	long long start, end, freq;
//	long long start_state, end_state;
//	QueryPerformanceFrequency(&num);
//	freq = num.QuadPart;
//	QueryPerformanceCounter(&num);
//	start_state = num.QuadPart;
//	while (1) {
//		unsigned char buffer = 0x00;
//		fread(&buffer, 1, sizeof(char), fp);
//		printf("%02x ", buffer);
//		if (buffer != 0x00) {
//			state_byte[row][col] = buffer;
//			row++;
//			col += row / 4;
//			row %= 4;
//		}		
//		if (feof(fp)) {
//			break;
//		}
//	}
//	QueryPerformanceCounter(&num);
//	end_state = num.QuadPart;
//	printf("\n");
//	printf("time_state=%lldus\n", (end_state - start_state) * 1000000000 / freq);
//	printf("\n");
//	print_4(state_byte);
	fread(plainText, 1, 32, fp);
	plainText[32] = '\0';
	fread(key, 1, 32, fk);
	key[32] = '\0';
	
	init_S();
	LARGE_INTEGER num;
	long long start, end, freq;
	QueryPerformanceFrequency(&num);
	freq = num.QuadPart;
	QueryPerformanceCounter(&num);
	start = num.QuadPart;
	for (int i = 0; i < 100000; i++) {
		cipherText = encrypt(plainText, key);
	}
	QueryPerformanceCounter(&num);
	end = num.QuadPart;
	printf("time=%lldms\n", (end - start) * 1000 / freq);
	printf("%s\n", cipherText);
	init_S_INV();
	printf("%s", decrypt(cipherText, key));
	return 0;
}
*/
