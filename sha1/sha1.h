#ifndef __SHA1_H
#define __SHA1_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define row(value, i, len) ((value << i) | (value >> (len - i)))
// before 16
#define w0(t) (block->word[t] = (row(block->word[t], 24, 32) & 0xff00ff00) \
							   |(row(block->word[t], 8, 32) & 0x00ff00ff))
// after 16
#define w1(t) (block->word[t] = row((block->word[t - 16] ^ block->word[t - 14] \
								   ^ block->word[t - 8]  ^ block->word[t - 3]), 1, 32))
//before 16
#define R00(a, b, c, d, e, i) \
	 e += (((b & c) | ((~b) & d)) + row(a, 5, 32) + w0(i) + 0x5a827999); b = row(b, 30, 32);
// after 16
#define R01(a, b, c, d, e, i) \
	 e += (((b & c) | ((~b) & d)) + row(a, 5, 32) + w1(i) + 0x5a827999); b = row(b, 30, 32);
#define R1(a, b, c, d, e, i) \
	 e += ((b ^ c ^ d) + row(a, 5, 32) + w1(i) + 0x6ed9eba1); b = row(b, 30, 32);
#define R2(a, b, c, d, e, i) \
	 e += (((b & c) | (b & d) | (c & d)) + row(a, 5, 32) + w1(i) + 0x08f1bbcdc); b = row(b, 30, 32);
#define R3(a, b, c, d, e, i) \
	 e += ((b ^ c ^ d) + row(a, 5, 32) + w1(i) + 0xca62c1d6); b = row(b, 30, 32);

typedef union {
	uint32_t state[5];
	uint8_t hash[20];
} SHA1_OUT;

typedef struct {
	uint32_t state[5];
	uint64_t count;
	union {
		uint64_t origin;
		uint8_t oristr[8];
	};
	uint8_t buf[64];
} SHA1;

typedef union {
	uint8_t byte[64];
	uint32_t word[80];
} BLOCK;

void SHA1_INIT(SHA1 *text);

void SHA1_ROUND(uint32_t state[5], const uint8_t *buf);

void SHA1_UPDATE(SHA1 *text, const uint8_t *s, uint32_t add_len, uint32_t len);

void SHA1_FINAL(SHA1_OUT *out, SHA1 *text);

void SHA1_PRINT(SHA1_OUT *out, uint8_t *mode);

void SHA1_HASH(uint8_t *s, SHA1_OUT *out);

#endif // !__SHA1_H

