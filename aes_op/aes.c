#include "CP_cal.h"
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#define RotWord(word) { byte tempByte; tempByte = word.s0; word.s0 = word.s1; word.s1 = word.s2; word.s2 = word.s3; word.s3 = tempByte; }

typedef union {
	uint32_t s;
	struct {
		byte s3;
		byte s2;
		byte s1;
		byte s0;
	};
}Col;

void SubWord(Col *word) {
	byte A[8] = { 0xf1, 0xe3, 0xc7, 0x8f, 0x1f, 0x3e, 0x7c, 0xf8 };
	byte temp, result;
	result.hex = 0x00;
	(*word).s0 = GF28_inv_by_GF24((*word).s0);
	temp.hex = A[0].hex & (*word).s0.hex;
	result.bit0 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
	temp.hex = A[1].hex & (*word).s0.hex;
	result.bit1 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
	temp.hex = A[2].hex & (*word).s0.hex;
	result.bit2 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = A[3].hex & (*word).s0.hex;
	result.bit3 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = A[4].hex & (*word).s0.hex;
	result.bit4 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = A[5].hex & (*word).s0.hex;
	result.bit5 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
	temp.hex = A[6].hex & (*word).s0.hex;
	result.bit6 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
	temp.hex = A[7].hex & (*word).s0.hex;
	result.bit7 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	(*word).s0.hex = result.hex;

	result.hex = 0x00;
	(*word).s1 = GF28_inv_by_GF24((*word).s1);
	temp.hex = A[0].hex & (*word).s1.hex;
	result.bit0 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
	temp.hex = A[1].hex & (*word).s1.hex;
	result.bit1 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
	temp.hex = A[2].hex & (*word).s1.hex;
	result.bit2 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = A[3].hex & (*word).s1.hex;
	result.bit3 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = A[4].hex & (*word).s1.hex;
	result.bit4 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = A[5].hex & (*word).s1.hex;
	result.bit5 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
	temp.hex = A[6].hex & (*word).s1.hex;
	result.bit6 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
	temp.hex = A[7].hex & (*word).s1.hex;
	result.bit7 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	(*word).s1.hex = result.hex;

	result.hex = 0x00;
	(*word).s2 = GF28_inv_by_GF24((*word).s2);
	temp.hex = A[0].hex & (*word).s2.hex;
	result.bit0 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
	temp.hex = A[1].hex & (*word).s2.hex;
	result.bit1 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
	temp.hex = A[2].hex & (*word).s2.hex;
	result.bit2 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = A[3].hex & (*word).s2.hex;
	result.bit3 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = A[4].hex & (*word).s2.hex;
	result.bit4 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = A[5].hex & (*word).s2.hex;
	result.bit5 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
	temp.hex = A[6].hex & (*word).s2.hex;
	result.bit6 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
	temp.hex = A[7].hex & (*word).s2.hex;
	result.bit7 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	(*word).s2.hex = result.hex;

	result.hex = 0x00;
	(*word).s3 = GF28_inv_by_GF24((*word).s3);
	temp.hex = A[0].hex & (*word).s3.hex;
	result.bit0 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
	temp.hex = A[1].hex & (*word).s3.hex;
	result.bit1 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
	temp.hex = A[2].hex & (*word).s3.hex;
	result.bit2 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = A[3].hex & (*word).s3.hex;
	result.bit3 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = A[4].hex & (*word).s3.hex;
	result.bit4 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = A[5].hex & (*word).s3.hex;
	result.bit5 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
	temp.hex = A[6].hex & (*word).s3.hex;
	result.bit6 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
	temp.hex = A[7].hex & (*word).s3.hex;
	result.bit7 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	(*word).s3.hex = result.hex;
	return;
}

void AddRoundKey(Col *state, Col *RoundKey) {
	state[0].s ^= RoundKey[0].s;
	state[1].s ^= RoundKey[1].s;
	state[2].s ^= RoundKey[2].s;
	state[3].s ^= RoundKey[3].s;
	return;
}

void SubBytes(Col *state) {
	byte A[8] = { 0xf1, 0xe3, 0xc7, 0x8f, 0x1f, 0x3e, 0x7c, 0xf8 };
	byte temp, result;
	for (register int i = 0; i < 4; i++) {
		result.hex = 0x00;
		state[i].s0 = GF28_inv_by_GF24(state[i].s0);
		temp.hex = A[0].hex & state[i].s0.hex;
		result.bit0 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
		temp.hex = A[1].hex & state[i].s0.hex;
		result.bit1 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
		temp.hex = A[2].hex & state[i].s0.hex;
		result.bit2 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
		temp.hex = A[3].hex & state[i].s0.hex;
		result.bit3 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
		temp.hex = A[4].hex & state[i].s0.hex;
		result.bit4 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
		temp.hex = A[5].hex & state[i].s0.hex;
		result.bit5 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
		temp.hex = A[6].hex & state[i].s0.hex;
		result.bit6 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
		temp.hex = A[7].hex & state[i].s0.hex;
		result.bit7 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
		state[i].s0.hex = result.hex;

		result.hex = 0x00;
		state[i].s1 = GF28_inv_by_GF24(state[i].s1);
		temp.hex = A[0].hex & state[i].s1.hex;
		result.bit0 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
		temp.hex = A[1].hex & state[i].s1.hex;
		result.bit1 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
		temp.hex = A[2].hex & state[i].s1.hex;
		result.bit2 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
		temp.hex = A[3].hex & state[i].s1.hex;
		result.bit3 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
		temp.hex = A[4].hex & state[i].s1.hex;
		result.bit4 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
		temp.hex = A[5].hex & state[i].s1.hex;
		result.bit5 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
		temp.hex = A[6].hex & state[i].s1.hex;
		result.bit6 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
		temp.hex = A[7].hex & state[i].s1.hex;
		result.bit7 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
		state[i].s1.hex = result.hex;

		result.hex = 0x00;
		state[i].s2 = GF28_inv_by_GF24(state[i].s2);
		temp.hex = A[0].hex & state[i].s2.hex;
		result.bit0 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
		temp.hex = A[1].hex & state[i].s2.hex;
		result.bit1 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
		temp.hex = A[2].hex & state[i].s2.hex;
		result.bit2 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
		temp.hex = A[3].hex & state[i].s2.hex;
		result.bit3 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
		temp.hex = A[4].hex & state[i].s2.hex;
		result.bit4 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
		temp.hex = A[5].hex & state[i].s2.hex;
		result.bit5 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
		temp.hex = A[6].hex & state[i].s2.hex;
		result.bit6 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
		temp.hex = A[7].hex & state[i].s2.hex;
		result.bit7 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
		state[i].s2.hex = result.hex;

		result.hex = 0x00;
		state[i].s3 = GF28_inv_by_GF24(state[i].s3);
		temp.hex = A[0].hex & state[i].s3.hex;
		result.bit0 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
		temp.hex = A[1].hex & state[i].s3.hex;
		result.bit1 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
		temp.hex = A[2].hex & state[i].s3.hex;
		result.bit2 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
		temp.hex = A[3].hex & state[i].s3.hex;
		result.bit3 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
		temp.hex = A[4].hex & state[i].s3.hex;
		result.bit4 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
		temp.hex = A[5].hex & state[i].s3.hex;
		result.bit5 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
		temp.hex = A[6].hex & state[i].s3.hex;
		result.bit6 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7 ^ 0x01;
		temp.hex = A[7].hex & state[i].s3.hex;
		result.bit7 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
		state[i].s3.hex = result.hex;
	}
	return;
}

void MixColumns(Col *state) {
	byte middle0, middle1, middle2, middle3;
	byte total;
	for (register int i = 0; i < 4; i++) {
		middle0.hex = state[i].s0.hex ^ state[i].s1.hex;
		middle1.hex = state[i].s1.hex ^ state[i].s2.hex;
		middle2.hex = state[i].s2.hex ^ state[i].s3.hex;
		middle3.hex = state[i].s3.hex ^ state[i].s0.hex;
		total.hex = middle0.hex ^ middle2.hex;

		state[i].s0.hex ^= DOUBLE(middle0).hex ^ total.hex;
		state[i].s1.hex ^= DOUBLE(middle1).hex ^ total.hex;
		state[i].s2.hex ^= DOUBLE(middle2).hex ^ total.hex;
		state[i].s3.hex ^= DOUBLE(middle3).hex ^ total.hex;
	}
	return;
}

void ShiftRows(Col *state) {
	byte temp;

	temp = state[0].s1;
	state[0].s1 = state[1].s1;
	state[1].s1 = state[2].s1;
	state[2].s1 = state[3].s1;
	state[3].s1 = temp;

	temp = state[0].s2;
	state[0].s2 = state[2].s2;
	state[2].s2 = temp;
	temp = state[1].s2;
	state[1].s2 = state[3].s2;
	state[3].s2 = temp;

	temp = state[3].s3;
	state[3].s3 = state[2].s3;
	state[2].s3 = state[1].s3;
	state[1].s3 = state[0].s3;
	state[0].s3 = temp;
	return;
}

void KeyExpansion(Col *key, Col *initkey) {
	Col temp;
	uint8_t Rcon[10] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36 };
	key[0] = initkey[0];
	key[1] = initkey[1];
	key[2] = initkey[2];
	key[3] = initkey[3];

	for (register int i = 4; i < 44; i++) {
		temp = key[i - 1];
		if (i % 4 == 0) {
			RotWord(temp);
			SubWord(&temp);
			temp.s0.hex ^= Rcon[i / 4 - 1];
		}
		key[i].s = key[i - 4].s ^ temp.s;
	}
	return;
}

void GetRoundKey(Col *RoundKey, Col *key, uint8_t start) {
	RoundKey[0] = key[start];
	RoundKey[1] = key[start + 1];
	RoundKey[2] = key[start + 2];
	RoundKey[3] = key[start + 3];
	return;
}

void Encrypt(Col *state, Col *key) {
	Col RoundKey[4];
	GetRoundKey(RoundKey, key, 0);
	AddRoundKey(state, RoundKey);
	for (uint8_t i = 1; i < 10; i++) {
		GetRoundKey(RoundKey, key, 4 * i);
		SubBytes(state);
		ShiftRows(state);
		MixColumns(state);
		AddRoundKey(state, RoundKey);
	}
	GetRoundKey(RoundKey, key, 4 * 10);
	SubBytes(state);
	ShiftRows(state);
	AddRoundKey(state, RoundKey);
	return;
}

void readMessage(Col *state, FILE *MF) {
	uint8_t i = 0;
	uint32_t *buf = malloc(4);
	while ((fread(buf, 4, 1, MF)) == 1) {
		state[i].s = (uint32_t)(*buf);
		i++;
	}
	return;
}

int main() {
	//FILE *MF = fopen("plaintext.txt", "r");
	clock_t start, finish;
	double dura = 1;
	Col state[4];
	Col initkey[4];
	Col key[44];
	//unsigned char *message = malloc(32);
	//message = "0123456789abcdeffedcba9876543210";
	//readMessage(state, MF);
	//state[0].s = 0x876e46a6;
	//state[1].s = 0xf24ce78c;
	//state[2].s = 0x4d904ad8;
	//state[3].s = 0x97ecc395;
	state[0].s = 0x4120736d;
	state[1].s = 0x616c6c20;
	state[2].s = 0x74657874;
	state[3].s = 0x20313642;
	initkey[0].s = 0x0f1571c9;
	initkey[1].s = 0x47d9e859;
	initkey[2].s = 0x0cb7add6;
	initkey[3].s = 0xaf7f6798;
	//readMessage(state, MF);
	KeyExpansion(key, initkey);
	printf("encrypt one time:\n");
	Encrypt(state, key);
	printf("0x%02x 0x%02x 0x%02x 0x%02x\n", state[0].s0.hex, state[1].s0.hex, state[2].s0.hex, state[3].s0.hex);
	printf("0x%02x 0x%02x 0x%02x 0x%02x\n", state[0].s1.hex, state[1].s1.hex, state[2].s1.hex, state[3].s1.hex);
	printf("0x%02x 0x%02x 0x%02x 0x%02x\n", state[0].s2.hex, state[1].s2.hex, state[2].s2.hex, state[3].s2.hex);
	printf("0x%02x 0x%02x 0x%02x 0x%02x\n", state[0].s3.hex, state[1].s3.hex, state[2].s3.hex, state[3].s3.hex);

	printf("\n%08x%08x%08x%08x\n", state[0].s, state[1].s, state[2].s, state[3].s);

	printf("\nencrypt 1e+06 times\n");
	start = clock();
	for (int i = 0; i < 100000; i++) {
		Encrypt(state, key);
	}
	finish = clock();
	dura = (double)(finish - start) / CLOCKS_PER_SEC;
	
	printf("time used: %fs\n", dura);

	if (!(dura - 0 < 0.0000001)) {
		printf("%fMbps\n", (double)(100000.0) * 128 / (1024 * 1024 * dura));
	}

	system("pause");
	
	return 0;
}
