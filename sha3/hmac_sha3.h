#ifndef __HMAC_SHA3_H
#define __HMAC_SHA3_H

#include "sha3.h"
#include "Keccak.h"
#include <stdlib.h>

void HMAC_SHA3(const uint8_t * key, uint32_t klen, const uint8_t * s, uint32_t slen, SHA3_OUT * out, uint32_t hashlen, uint32_t B);

#define HMAC_SHA3_224(key, klen, s, slen, out) HMAC_SHA3(key, klen, s, slen, out, 28, 144)
#define HMAC_SHA3_256(key, klen, s, slen, out) HMAC_SHA3(key, klen, s, slen, out, 32, 136)
#define HMAC_SHA3_384(key, klen, s, slen, out) HMAC_SHA3(key, klen, s, slen, out, 48, 104)
#define HMAC_SHA3_512(key, klen, s, slen, out) HMAC_SHA3(key, klen, s, slen, out, 64, 62)

#endif // !__HMAC_SHA3_H
#pragma once
