#ifndef __HMAC_H
#define __HMAC_H

#include "sha1.h"

#define B 64

void HMAC_SHA1(const uint8_t * key, uint32_t klen, const uint8_t * s, uint32_t slen, SHA1_OUT *out);

#endif // !__HMAC_H
#pragma once
