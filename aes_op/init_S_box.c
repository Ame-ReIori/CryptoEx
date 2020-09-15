#include "calOnGF28.h"

unsigned char S[16][16] = { 0x00 };
unsigned char S_INV[16][16] = { 0x00 };

void print_hex(unsigned char a) {
	char *buffer = (char *)malloc(3);
	_itoa_s(a, buffer, 3, 16);
	printf("0x%s ", buffer);
	return;
}

void print_16(unsigned char box[16][16]) {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			print_hex(box[i][j]);
		}
		printf("\n");
	}
}

void init_S() {
	int n = 0;
	int b[8] = { 0,0,0,0,0,0,0,0 };
	int c[8] = { 1,1,0,0,0,1,1,0 };
	int b_n[8] = { 0,0,0,0,0,0,0,0 };
	unsigned char temp = 0x00;
	unsigned char num = 0x00;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (num == 0x00) {
				temp = 0x00;
			}
			else {
				temp = GF28_inv(num);
			}
			while (temp != 0) {
				b[n] = temp % 2;
				temp /= 2;
				n += 1;
			}
			for (int k = 0; k < 8; k++) {
				b_n[k] = b[k] ^ b[(k + 4) % 8] ^ b[(k + 5) % 8] ^ b[(k + 6) % 8] ^ b[(k + 7) % 8] ^ c[k];
				if (b_n[k] & 1) {
					S[i][j] ^= (1 << k);
				}
			}
			b[0] = b[1] = b[2] = b[3] = b[4] = b[5] = b[6] = b[7] = 0;
			num++;
			n = 0;
		}
	}
	return;
}

void init_S_INV() {
	int n = 0;
	int b[8] = { 0,0,0,0,0,0,0,0 };
	int d[8] = { 1,0,1,0,0,0,0,0 };
	int b_n[8] = { 0,0,0,0,0,0,0,0 };
	unsigned char temp = 0x00;
	unsigned char num = 0x00;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			temp = num;
			
			while (temp != 0) {
				b[n] = temp % 2;
				temp /= 2;
				n += 1;
			}
			for (int k = 0; k < 8; k++) {
				b_n[k] = b[(k + 2) % 8] ^ b[(k + 5) % 8] ^ b[(k + 7) % 8] ^ d[k];
				if (b_n[k] & 1) {
					S_INV[i][j] ^= (1 << k);
				}
			}
			if (S_INV[i][j] == 0x00) {
				S_INV[i][j] = 0x00;
			}
			else {
				S_INV[i][j] = GF28_inv(S_INV[i][j]);
			}
			b[0] = b[1] = b[2] = b[3] = b[4] = b[5] = b[6] = b[7] = 0;
			num++;
			n = 0;
		}
	}
	return;
}
/*
int main() {
	init_S();
	print_16(S);
	printf("\n"); 
	init_S_INV();
	print_16(S_INV);
	return 0;
}
*/