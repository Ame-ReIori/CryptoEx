#pragma once
#ifndef __calOnGF28_H_
#define __calOnGF28_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

unsigned char GF28_add_minus(unsigned char ax, unsigned char bx);

unsigned char GF28_div(unsigned char ax, unsigned char bx);

unsigned char GF28_inv(unsigned char ax);

unsigned char GF28_mul(unsigned char ax, unsigned char bx);

unsigned char GF28_q_mod(unsigned char ax, unsigned char mx);

unsigned char XTIME(unsigned char ax);
#endif // !__calOnGF28_H_
