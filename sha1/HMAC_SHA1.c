#include "hmac.h"

void HMAC_SHA1(const uint8_t * key, uint32_t klen, const uint8_t * s, uint32_t slen, SHA1_OUT * out) {
	SHA1 isha1, osha1;
	SHA1_OUT tempkey, isha1out, osha1out;
	uint8_t buf[B], temp[21];
	if (klen > B) {
		SHA1_HASH(key, &tempkey);
		key = tempkey.hash;
		klen = 20;
	}
	SHA1_INIT(&isha1);
	for (int i = 0; i < B; i++) {
		buf[i] = i < klen ? key[i] ^ 0x36 : 0x36;
	}
	SHA1_UPDATE(&isha1, buf, 64, 64);
	SHA1_UPDATE(&isha1, s, slen, slen);

	SHA1_FINAL(&isha1out, &isha1);

	for (int i = 0; i < 20; i+=4) {
		temp[i + 0] = isha1out.hash[i + 3];
		temp[i + 1] = isha1out.hash[i + 2];
		temp[i + 2] = isha1out.hash[i + 1];
		temp[i + 3] = isha1out.hash[i + 0];
	}
	temp[20] = '\0';


	SHA1_INIT(&osha1);


	for (int i = 0; i < B; i++) {
		buf[i] = i < klen ? key[i] ^ 0x5c : 0x5c;
	}

	SHA1_UPDATE(&osha1, buf, 64, 64);
	SHA1_UPDATE(&osha1, temp, 20, 20);

	SHA1_FINAL(&osha1out, &osha1);

	memcpy(out->hash, osha1out.hash, 20);
}

int main() {
	uint8_t *key = "aaaa";
	uint8_t *s = "abcd";
	SHA1_OUT out;

	HMAC_SHA1(key, strlen(key), s, strlen(s), &out);
	SHA1_PRINT(&out, "hex");
	system("pause");
}
