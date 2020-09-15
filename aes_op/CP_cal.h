#pragma once
#ifndef _CPCAL_H
#define _CPCAL_H
#include<stdint.h>
#include<stdio.h>

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

byte _T_8_4(byte x);

byte _T_4_8(byte x);

byte GF28_inv_by_GF24(byte g);

byte GF28_mul_by_GF24(byte g, byte h);

byte DOUBLE(byte a) {
	byte result;
	byte xor;
	xor.hex = 0x00;
	xor.bit0 = xor.bit1 = xor.bit3 = xor.bit4 = a.bit7;
	result.hex = a.hex << 1;
	result.hex ^= xor.hex;
	return result;
}
#endif // !_CPCAL_H

