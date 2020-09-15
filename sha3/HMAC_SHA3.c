#include "hmac_sha3.h"

void HMAC_SHA3(const uint8_t * key, uint32_t klen, const uint8_t * s, uint32_t slen, SHA3_OUT * out, uint32_t hashlen, uint32_t B) {
	SHA3 isha3, osha3;
	SHA3_OUT tempkey, isha3out, osha3out;
	uint8_t *buf = malloc(B);
	if (klen > B) {
		SHA3_HASH(&tempkey, hashlen, key, klen);
		key = tempkey.s;
		klen = hashlen;
	}
	SHA3_INIT(&isha3, hashlen);

	memset(isha3out.s, 0, hashlen);
	isha3out.len = 0;

	for (int i = 0; i < B; i++) {
		buf[i] = i < klen ? key[i] ^ 0x36 : 0x36;
	}

	SHA3_UPDATE(&isha3, buf, B);
	SHA3_UPDATE(&isha3, s, slen);

	SHA3_FINAL(&isha3out, &isha3);

	SHA3_INIT(&osha3, hashlen);
	memset(osha3out.s, 0, hashlen);
	osha3out.len = 0;

	for (int i = 0; i < B; i++) {
		buf[i] = i < klen ? key[i] ^ 0x5c : 0x5c;
	}

	SHA3_UPDATE(&osha3, buf, B);
	SHA3_UPDATE(&osha3, isha3out.s, hashlen);

	SHA3_FINAL(&osha3out, &osha3);

	memcpy(out->s, osha3out.s, hashlen);
	out->len = hashlen;
	free(buf);
}

