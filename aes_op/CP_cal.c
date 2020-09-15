#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdint.h>

/*
	use GF((2^4)^2) or GF(((2^2)^2)^2) to cal mul and inv on GF(2^8)
*/
typedef union {
	uint8_t hex;
	struct {
		uint8_t bit0 : 1;
		uint8_t bit1 : 1;
		uint8_t bit2 : 1;
		uint8_t bit3 : 1;
		uint8_t bit4 : 1;
		uint8_t bit5 : 1;
		uint8_t bit6 : 1;
		uint8_t bit7 : 1;
	};
	struct {
		uint8_t low : 4;
		uint8_t high : 4;
	};
} byte;
/*
int T_28_242[8][8] = { {1,0,1,0,0,0,0,0},
					  {1,0,1,0,1,1,0,0},
					  {1,1,0,1,0,0,1,0},
					  {0,1,1,1,0,0,0,0},
					  {1,1,0,0,0,1,1,0},
					  {0,1,0,1,0,0,1,0},
					  {0,0,0,0,1,0,1,0},
					  {1,1,0,1,1,1,0,1} };
					  */
byte T_28_242[8] = {0x71, 0x06, 0x82, 0x14, 0x70, 0xd2, 0xac, 0xa0};

/*
int T_242_28[8][8] = { {0,0,1,0,0,1,0,0},
					  {1,1,1,0,1,1,1,0},
					  {1,0,1,0,0,1,0,0},
					  {0,1,0,1,1,0,1,0},
					  {1,0,1,1,0,0,1,0},
					  {0,1,1,1,0,0,1,0},
					  {1,0,1,1,0,0,0,0},
					  {0,1,0,1,0,0,0,1} };
					  */

byte T_242_28[8] = { 0x11, 0xb0, 0xb2, 0x72, 0xba, 0x34, 0x9e, 0xb4 };
/*
int T_28_24[8][8] = { {1,0,1,0,0,0,0,0},
					  {0,0,0,0,1,1,0,0},
					  {0,1,1,1,0,0,1,0},
					  {1,0,1,0,1,1,1,0},
					  {0,0,0,1,0,1,0,0},
					  {1,0,0,1,0,1,1,0},
					  {0,0,0,1,0,0,1,0},
					  {1,1,1,0,0,0,0,1} };

int T_24_28[8][8] = { {1,1,0,1,1,1,0,0}, 
					  {0,1,1,1,1,1,1,0}, 
					  {0,1,0,1,1,1,0,0}, 
					  {1,1,0,1,0,0,1,0}, 
					  {1,0,0,1,1,0,1,0}, 
					  {1,1,0,1,1,0,1,0}, 
					  {1,1,0,1,0,0,0,0}, 
					  {1,1,1,1,1,1,1,1} };
					  */
byte inv_x_GF24[16] = { 0x00,0x01,0x09,0x0e,0x0d,0x0b,0x07,0x06,0x0f,0x02,0x0c,0x05,0x0a,0x04,0x03,0x08 };

byte _T_8_4(byte x) {
	byte temp;
	byte result;
	temp.hex = T_28_242[0].hex & x.hex;
	result.bit0 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = T_28_242[1].hex & x.hex;
	result.bit1 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = T_28_242[2].hex & x.hex;
	result.bit2 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = T_28_242[3].hex & x.hex;
	result.bit3 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = T_28_242[4].hex & x.hex;
	result.bit4 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = T_28_242[5].hex & x.hex;
	result.bit5 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = T_28_242[6].hex & x.hex;
	result.bit6 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = T_28_242[7].hex & x.hex;
	result.bit7 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	return result;
}

byte _T_4_8(byte x) {
	byte temp;
	byte result;
	temp.hex = T_242_28[0].hex & x.hex;
	result.bit0 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = T_242_28[1].hex & x.hex;
	result.bit1 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = T_242_28[2].hex & x.hex;
	result.bit2 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = T_242_28[3].hex & x.hex;
	result.bit3 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = T_242_28[4].hex & x.hex;
	result.bit4 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = T_242_28[5].hex & x.hex;
	result.bit5 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = T_242_28[6].hex & x.hex;
	result.bit6 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	temp.hex = T_242_28[7].hex & x.hex;
	result.bit7 = temp.bit0 ^ temp.bit1 ^ temp.bit2 ^ temp.bit3 ^ temp.bit4 ^ temp.bit5 ^ temp.bit6 ^ temp.bit7;
	return result;
}

byte GF24_XTIME(byte x) {
	//cal x*0x02
	//x = (0,0,0,0,x3,x2,x1,x0)
	//mx = 10011
	byte result;
	result.hex = x.hex << 1;
	result.bit4 = 0;
	result.bit1 = x.bit3 ^ x.bit0;
	result.bit0 = x.bit3;
	return result;
}
/*
byte GF24_mul_bo(byte g, byte h) {
	byte c0, c1;
	byte gh;
	gh.hex = 0x00;
	c0.hex = g.bit0 ^ g.bit3;
	c1.hex = g.bit2 ^ g.bit3;
	gh.bit0 = (g.bit0 & h.bit0) ^ (g.bit3 & h.bit1) ^ (g.bit2 & h.bit2) ^ (g.bit1 & h.bit3);
	gh.bit1 = (g.bit1 & h.bit0) ^ (c0.bit0 & h.bit1) ^ (c1.bit0 & h.bit2) ^ ((g.bit1 ^ g.bit2) & h.bit3);
	gh.bit2 = (g.bit2 & h.bit0) ^ (g.bit1 & h.bit1) ^ (c0.bit0 & h.bit2) ^ (c1.bit0 ^ h.bit3);
	gh.bit3 = (g.bit3 & h.bit0) ^ (g.bit2 & h.bit1) ^ (g.bit1 & h.bit2) ^ (c0.bit0 ^ h.bit3);
	return gh;
}
*/

byte GF24_mul(byte g, byte h) {
	byte result;
	result.hex = 0x00;
	for (int i = 0; i < 4; i++) {
		if (h.hex & 0x01) {
			result.hex ^= g.hex;
		}
		g = GF24_XTIME(g);
		h.hex >>= 1;
	}
	return result;
}

byte GF24_squ(byte g) {
	byte result;
	result.hex = 0x00;
	result.bit0 = g.bit0 ^ g.bit2;
	result.bit1 = g.bit2;
	result.bit2 = g.bit1 ^ g.bit3;
	result.bit3 = g.bit3;
	return result;
}

byte GF28_mul_by_GF24(byte g, byte h) {
	byte v, gh;
	byte g_high, g_low, h_high, h_low;
	v.hex = 0x0e;
	gh.hex = 0x00;

	g = _T_8_4(g);
	h = _T_8_4(h);

	g_high.hex = g.high;
	g_low.hex = g.low;
	h_high.hex = h.high;
	h_low.hex = h.low;

	byte gh_hh = GF24_mul(g_high, h_high);
	gh.high = GF24_mul(g_high, h_low).hex ^ GF24_mul(g_low, h_high).hex ^ gh_hh.hex;
	gh.low = GF24_mul(g_low, h_low).hex ^ GF24_mul(gh_hh, v).hex;
	
	gh = _T_4_8(gh);
	return gh;
}

byte GF28_inv_by_GF24(byte g) {
	byte v, h;
	byte g_high, g_low, g_add;
	v.hex = 0x0e;
	h.hex = 0x00;

	g = _T_8_4(g);
	
	g_high.hex = g.high;
	g_low.hex = g.low;
	g_add.hex = g.high ^ g.low;

	uint8_t index = GF24_mul(GF24_squ(g_high), v).hex ^ GF24_mul(g_high, g_low).hex ^ GF24_squ(g_low).hex;
	byte inv = inv_x_GF24[index];
	h.high = GF24_mul(g_high, inv).hex;
	h.low = GF24_mul(g_add, inv).hex;
	
	h = _T_4_8(h);
	return h;
}
/*
int main() {
	byte t;
	byte t1;
	byte t2;
	byte t3;
	byte t4;
	byte t5;
	t.hex = 0xc2;
	t = _T_8_4(t);
	t = _T_4_8(t);
	t1.hex = 0xea;
	t4.hex = 0x0d;
	t5.hex = 0x04;
	//for (int i = 0; i < 1000000; i++) {
		t3 = GF28_inv_by_GF24(t1);
	//}
	
	printf("0x%02x\n", t3.hex);
	//system("pause");
	//printf("0x%02x\n", t2.hex);
	//printf("0x%02x\n", t3.hex);
	
}


*/