#include "sha1.h"

void SHA1_INIT(SHA1 *text) {

	text->state[0] = 0x67452301;
	text->state[1] = 0xefcdab89;
	text->state[2] = 0x98badcfe;
	text->state[3] = 0x10325476;
	text->state[4] = 0xc3d2e1f0;

	//	text->state[0] = 0x01234567;
	//	text->state[1] = 0x89abcdef;
	//	text->state[2] = 0xfedcba98;
	//	text->state[3] = 0x76543210;
	//	text->state[4] = 0xc3d2e1f0;
	text->count = 0;
	text->origin = 0;
	memset(text->buf, 0, 64);
}

void SHA1_ROUND(uint32_t state[5], const uint8_t *buf) {
	uint32_t a, b, c, d, e = 0;
	BLOCK *block = (BLOCK *)malloc(sizeof(BLOCK));
	memcpy(block, buf, 64);

	a = state[0];
	b = state[1];
	c = state[2];
	d = state[3];
	e = state[4];

	R00(a, b, c, d, e, 0);
	R00(e, a, b, c, d, 1);
	R00(d, e, a, b, c, 2);
	R00(c, d, e, a, b, 3);
	R00(b, c, d, e, a, 4);
	R00(a, b, c, d, e, 5);
	R00(e, a, b, c, d, 6);
	R00(d, e, a, b, c, 7);
	R00(c, d, e, a, b, 8);
	R00(b, c, d, e, a, 9);
	R00(a, b, c, d, e, 10);
	R00(e, a, b, c, d, 11);
	R00(d, e, a, b, c, 12);
	R00(c, d, e, a, b, 13);
	R00(b, c, d, e, a, 14);
	R00(a, b, c, d, e, 15);
	R01(e, a, b, c, d, 16);
	R01(d, e, a, b, c, 17);
	R01(c, d, e, a, b, 18);
	R01(b, c, d, e, a, 19);
	R1(a, b, c, d, e, 20);
	R1(e, a, b, c, d, 21);
	R1(d, e, a, b, c, 22);
	R1(c, d, e, a, b, 23);
	R1(b, c, d, e, a, 24);
	R1(a, b, c, d, e, 25);
	R1(e, a, b, c, d, 26);
	R1(d, e, a, b, c, 27);
	R1(c, d, e, a, b, 28);
	R1(b, c, d, e, a, 29);
	R1(a, b, c, d, e, 30);
	R1(e, a, b, c, d, 31);
	R1(d, e, a, b, c, 32);
	R1(c, d, e, a, b, 33);
	R1(b, c, d, e, a, 34);
	R1(a, b, c, d, e, 35);
	R1(e, a, b, c, d, 36);
	R1(d, e, a, b, c, 37);
	R1(c, d, e, a, b, 38);
	R1(b, c, d, e, a, 39);
	R2(a, b, c, d, e, 40);
	R2(e, a, b, c, d, 41);
	R2(d, e, a, b, c, 42);
	R2(c, d, e, a, b, 43);
	R2(b, c, d, e, a, 44);
	R2(a, b, c, d, e, 45);
	R2(e, a, b, c, d, 46);
	R2(d, e, a, b, c, 47);
	R2(c, d, e, a, b, 48);
	R2(b, c, d, e, a, 49);
	R2(a, b, c, d, e, 50);
	R2(e, a, b, c, d, 51);
	R2(d, e, a, b, c, 52);
	R2(c, d, e, a, b, 53);
	R2(b, c, d, e, a, 54);
	R2(a, b, c, d, e, 55);
	R2(e, a, b, c, d, 56);
	R2(d, e, a, b, c, 57);
	R2(c, d, e, a, b, 58);
	R2(b, c, d, e, a, 59);
	R3(a, b, c, d, e, 60);
	R3(e, a, b, c, d, 61);
	R3(d, e, a, b, c, 62);
	R3(c, d, e, a, b, 63);
	R3(b, c, d, e, a, 64);
	R3(a, b, c, d, e, 65);
	R3(e, a, b, c, d, 66);
	R3(d, e, a, b, c, 67);
	R3(c, d, e, a, b, 68);
	R3(b, c, d, e, a, 69);
	R3(a, b, c, d, e, 70);
	R3(e, a, b, c, d, 71);
	R3(d, e, a, b, c, 72);
	R3(c, d, e, a, b, 73);
	R3(b, c, d, e, a, 74);
	R3(a, b, c, d, e, 75);
	R3(e, a, b, c, d, 76);
	R3(d, e, a, b, c, 77);
	R3(c, d, e, a, b, 78);
	R3(b, c, d, e, a, 79);

	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;
	state[4] += e;

	a = b = c = d = e = 0;
}

void SHA1_UPDATE(SHA1 *text, const uint8_t *s, uint32_t add_len, uint32_t len) {
	const uint8_t *data = s;
	size_t i = 0, j = 0;
	// i means the number of encoded bytes

	j = (text->count >> 3) & 63; // start position
	text->origin += add_len << 3; // bits
	text->count += len << 3;

	if ((j + len) > 63) {
		memcpy(&text->buf[j], data, (i = 64 - j));
		SHA1_ROUND(text->state, text->buf);
		for (; i + 63 < len; i += 64) {
			SHA1_ROUND(text->state, data + i);
		}
		j = 0;
	}
	// insert remaining data
	memcpy(&text->buf[j], &data[i], len - i);
}

void SHA1_FINAL(SHA1_OUT *out, SHA1 *text) {
	SHA1_UPDATE(text, (uint8_t *)"\x80", 0, 1);
	while ((text->count % 512) != 448) {
		SHA1_UPDATE(text, (uint8_t *)"\x00", 0, 1);
	}
	text->origin = ((text->origin       & 0x00000000000000ff) << 56)\
		         | ((text->origin >> 8  & 0x00000000000000ff) << 48)\
		         | ((text->origin >> 16 & 0x00000000000000ff) << 40)\
		         | ((text->origin >> 24 & 0x00000000000000ff) << 32)\
		         | ((text->origin >> 32 & 0x00000000000000ff) << 24)\
		         | ((text->origin >> 40 & 0x00000000000000ff) << 16)\
		         | ((text->origin >> 48 & 0x00000000000000ff) << 8)\
		         | ((text->origin >> 56 & 0x00000000000000ff));

	//	text->origin = ((text->origin & 0x00000000ffffffff) << 32)\
					 | ((text->origin & 0xffffffff00000000)      );

	SHA1_UPDATE(text, text->oristr, 0, 8);
	out->state[0] = text->state[0];
	out->state[1] = text->state[1];
	out->state[2] = text->state[2];
	out->state[3] = text->state[3];
	out->state[4] = text->state[4];
	memset(text->buf, 0, 64);
	memset(text->state, 0, 20);
	text->count = 0;
}

void SHA1_PRINT(SHA1_OUT *out, uint8_t *mode) {
	if (strcmp(mode, "hex") == 0) {
		for (int i = 0; i < 20; i += 4) {
			printf("%02x", out->hash[i + 3]);
			printf("%02x", out->hash[i + 2]);
			printf("%02x", out->hash[i + 1]);
			printf("%02x", out->hash[i]);
		}
		printf("\n");
	}
	memset(out->state, 0, 20);
}

void SHA1_HASH(uint8_t *s, SHA1_OUT *out) {
	SHA1 text;
	SHA1_INIT(&text);
	SHA1_UPDATE(&text, s, strlen(s), strlen(s));
	SHA1_FINAL(out, &text);
	SHA1_PRINT(out, "hex");
}
/*
int main() {
	uint8_t *s1 = "abcd";
	SHA1 A;
	SHA1_OUT out;
	SHA1_INIT(&A);
	SHA1_UPDATE(&A, s1, strlen(s1), strlen(s1));
	SHA1_FINAL(&out, &A);
	SHA1_PRINT(&out, "hex");
	system("pause");

	return 0;
}
*/