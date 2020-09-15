#include "Keccak.h"

uint8_t rc(uint8_t t) {
	if (t % 255 == 0) {
		return 1;
	}
	uint16_t r = 0b1000000000000000; // 9 bits
	for (int i = 1; i < (t % 255) + 1; i++) {
		r >>= 1;
		r ^= (r & 0b0000000010000000) << 8;
		r ^= (r & 0b0000000010000000) << 4;
		r ^= (r & 0b0000000010000000) << 3;
		r ^= (r & 0b0000000010000000) << 2;
		r &= 0b1111111100000000;
	}
	return (uint8_t)(r >> 15);
}

void Round(SHA3 *A, uint8_t r) {
	//const
	// for(int i = 0; i < 24; i++) time = (i + 1) * (i + 2) / 2 % 64;
	const uint8_t ROWTIME[24] = {
		1,  3,  6,  10, 15, 21, 28, 36, 45, 55, 2,  14,
		27, 41, 56, 8,  25, 43, 62, 18, 39, 61, 20, 44
	};
	// draw the matrix and get the answer
	const uint8_t REPLACEPOS[24] = {
		10, 7,  11, 17, 18, 3, 5,  16, 8,  21, 24, 4,
		15, 23, 19, 13, 12, 2, 20, 14, 22, 9,  6,  1
	};

	uint8_t replace_index;
	uint64_t C[5];
	uint64_t D[5];
	uint64_t front, temp;
	uint64_t RC = 0x0000000000000000;

	// theta
	for (int i = 0; i < 5; i++) {
		C[i] = A->state.lane[i] ^ A->state.lane[i + 5] ^ A->state.lane[i + 10] ^ A->state.lane[i + 15] ^ A->state.lane[i + 20];
	}

	for (int i = 0; i < 5; i++) {
		D[i] = C[(i + 4) % 5] ^ ROW(C[(i + 1) % 5], 1, 64);
		for (int j = 0; j < 25; j += 5) {
			A->state.lane[i + j] ^= D[i];
		}
	}

	// rho and pi
	front = A->state.lane[1];
	for (int i = 0; i < 24; i++) {
		replace_index = REPLACEPOS[i];
		temp = A->state.lane[replace_index];
		A->state.lane[replace_index] = ROW(front, ROWTIME[i], 64);
		front = temp;
	}

	// chi
	for (int i = 0; i < 25; i += 5) {
		// temp store A->state.lane[i, i+1, i+2, i+3, i+4]
		// use C
		for (int j = 0; j < 5; j++) {
			C[j] = A->state.lane[i + j];
		}
		for (int j = 0; j < 5; j++) {
			A->state.lane[i + j] ^= (~C[(j + 1) % 5]) & C[(j + 2) % 5];
		}
	}

	// iota
	RC ^= ((uint64_t)(rc(0 + 7 * r)) << 0);
	RC ^= ((uint64_t)(rc(1 + 7 * r)) << 1);
	RC ^= ((uint64_t)(rc(2 + 7 * r)) << 3);
	RC ^= ((uint64_t)(rc(3 + 7 * r)) << 7);
	RC ^= ((uint64_t)(rc(4 + 7 * r)) << 15);
	RC ^= ((uint64_t)(rc(5 + 7 * r)) << 31);
	RC ^= ((uint64_t)(rc(6 + 7 * r)) << 63);

	A->state.lane[0] ^= RC;
}

void Keccak_P(SHA3 *A) {
	for (int i = 0; i < 24; i++) {
		Round(A, i);
	}
}