#ifndef _SHA3_H
#define _SHA3_H

// include
#include "Keccak.h"
#include <string.h>

// function

void SHA3_INIT(SHA3 *A, uint32_t hashLen);

void SHA3_UPDATE(SHA3 *A, const uint8_t *in, uint32_t inlen);

void SHA3_FINAL(SHA3_OUT *out, SHA3 *A);

void SHA3_PRINT(SHA3_OUT *out);

void SHA3_HASH(SHA3_OUT *out, uint32_t hashLen, const uint8_t *in, uint32_t inlen);

//interface

#define SHA3_224(out, in, inlen) SHA3_HASH(out, 28, in, inlen)

#define SHA3_256(out, in, inlen) SHA3_HASH(out, 32, in, inlen)

#define SHA3_384(out, in, inlen) SHA3_HASH(out, 48, in, inlen)

#define SHA3_512(out, in, inlen) SHA3_HASH(out, 64, in, inlen)

#endif // !_SHA3_H
