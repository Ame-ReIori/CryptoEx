#include "sha3.h"

void SHA3_INIT(SHA3 *A, uint32_t hashLen) {
	memset(A->state.b, 0, 200);
	A->hashLen = hashLen;
	A->rLen = 200 - 2 * hashLen;
	A->len = 0;
}

void SHA3_UPDATE(SHA3 *A, const uint8_t *s, uint32_t len /*string len*/) {
	uint32_t i, j;
	j = A->len;
	for (int i = 0; i < len; i++) {
		A->state.b[j++] ^= s[i];
		if (j >= A->rLen) {
			Keccak_P(A);
			j = 0;
		}
	}
	A->len = j;
}

void SHA3_FINAL(SHA3_OUT *out, SHA3 *A) {
	A->state.b[A->len] ^= 0x06;
	A->state.b[A->rLen - 1] ^= 0x80;

	Keccak_P(A);

	for (int i = 0; i < A->hashLen; i++) {
		out->s[out->len++] = A->state.b[i];
	}
}

void SHA3_PRINT(SHA3_OUT *out) {
	for (int i = 0; i < out->len; i++) {
		printf("%02x", out->s[i]);
	}
	printf("\n");
}

void SHA3_HASH(SHA3_OUT * out, uint32_t hashLen, const uint8_t * in, uint32_t inlen) {
	SHA3 A;
	memset(out->s, 0, 64);
	out->len = 0;
	SHA3_INIT(&A, hashLen);
	SHA3_UPDATE(&A, in, inlen);
	SHA3_FINAL(out, &A);
}
