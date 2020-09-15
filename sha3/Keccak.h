#ifndef _KECCAK_H
#define _KECCAK_H

// include
#include <stdint.h>
#include <stdio.h>

// data structure
typedef struct {
	union {
		uint8_t b[200];
		uint64_t lane[25];
	}state;
	uint32_t hashLen; // out hash len
	uint32_t rLen; // 200 - 2 * hashLen
	uint32_t len;
} SHA3;

typedef struct {
	uint8_t s[64];
	uint32_t len;
} SHA3_OUT;


// function
#define ROW(value, i, len) ((value << i) | (value >> (len - i)))
#define SWAP(a, b) temp = a; a = b; b = temp;

uint8_t rc(uint8_t t);

void Round(SHA3 *A, uint8_t r);

void Keccak_P(SHA3 *A);

#endif // !_KECCAK_H
