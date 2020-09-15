#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	input: unsigned char, unsigned char
	output: unsigned char
	function: add or minus in GF(2^8)
*/
unsigned char GF28_add_minus(unsigned char ax, unsigned char bx)
{
	return ax ^ bx;
}

/*
	input: unsigned char
	output: unsigned char
	function: calculate x*f(x)
*/
unsigned char XTIME(unsigned char x)
{
	return ((x << 1) ^ ((x & 0x80) ? 0x1b : 0x00));
}

/*
	input: unsigned char, unsigned char
	output: unsigned char
	function: multiply in GF(2^8)
*/
unsigned char GF28_mul(unsigned char ax, unsigned char bx)
{
	unsigned char temp[8] = { ax };
	unsigned char temp_multiply = 0x00;
	int i = 0;
	for (i = 1; i < 8; i++) {
		temp[i] = XTIME(temp[i - 1]);
	}
	temp_multiply = (bx & 0x01) * ax;
	for (i = 1; i <= 7; i++) {
		temp_multiply ^= (((bx >> i) & 0x01)*temp[i]);
	}
	return temp_multiply;
}

/*
	function: calculate qx and rx in ax = qx * mx + rx
*/
unsigned char *GF28_q_mod(unsigned char ax, unsigned char mx)
{
	int k = 0;
	char *m = (char *)malloc(9);
	char *r = (char *)malloc(9);
	unsigned char *result = (unsigned char *)malloc(2*sizeof(unsigned char));
	// ax = qx*mx + rx
	unsigned char rx = ax; // r
	unsigned char qx = 0x00; // q
	unsigned char bx = mx;
	// change them into str to cal length
	_itoa_s(rx, r, 9, 2);
	_itoa_s(mx, m, 9, 2);
	while (strlen(r) >= strlen(m) && rx != 0x00) {
		k = strlen(r) - strlen(m);
		bx = GF28_mul(mx, (1 << k));
		rx = GF28_add_minus(rx, bx);
		qx = GF28_add_minus(qx, (1 << k));
		_itoa_s(rx, r, 9, 2);
	}
	*result = qx;
	*(result + 1) = rx;
	free(m);
	free(r);
	return result;
}

unsigned char GF28_inv(unsigned char ax)
{
	
	int mx = 0b100011011;
	int k = 0;
	unsigned char qx = 0x01;
	unsigned char rx = 0x00;
	char *m = (char *)malloc(10);
	char *a = (char *)malloc(9);
	_itoa_s(mx, m, 10, 2);
	_itoa_s(ax, a, 9, 2);
	// calculate mx/ax and mx % ax first
	k = strlen(m) - strlen(a);
	qx = qx << k;
	mx = GF28_add_minus(mx, ax << k);
	qx = GF28_add_minus(qx, *GF28_q_mod(mx, ax));
	rx = *(GF28_q_mod(mx, ax) + 1);
	// end calculate

	free(m);
	free(a);

	unsigned char s[3] = { 0x00,0x01,0x00 };
	unsigned char t[3] = { 0x00,0x00,0x01 };
	unsigned char r[3] = { mx,ax,rx };
	unsigned char q[3] = { 0x00,0x00,qx };
	unsigned char tempS, tempT, tempR, tempQ = 0x00;
	while (1) {
		if (r[2] == 0x00) break;
		tempQ = *GF28_q_mod(r[1], r[2]);
		tempR = *(GF28_q_mod(r[1], r[2]) + 1);
		tempS = GF28_add_minus(s[1], GF28_mul(q[2], s[2]));
		tempT = GF28_add_minus(t[1], GF28_mul(q[2], t[2]));
		s[0] = s[1]; s[1] = s[2]; s[2] = tempS;
		r[0] = r[1]; r[1] = r[2]; r[2] = tempR;
		q[0] = q[1]; q[1] = q[2]; q[2] = tempQ;
		t[0] = t[1]; t[1] = t[2]; t[2] = tempT;
	}
	return t[2];
}

// ax * bx^-1
unsigned char GF28_div(unsigned char ax, unsigned char bx) {
	return GF28_mul(ax, GF28_inv(bx));
}

/*
// for test
int main()
{
	unsigned char a = 0b00100101; // 0b00101001
	unsigned char b = 0b00011011; // 0b11010111
	unsigned char *c;
	char *q_bin = (char *)malloc(9);
	char *r_bin = (char *)malloc(9);
	c = GF28_q_mod(a, b);
	unsigned char i = GF28_inv(a);
	unsigned char q = *c;
	unsigned char r = *(c + 1);
	unsigned char m = GF28_div(a, b);
	char *qx = (char *)malloc(9);
	char *rx = (char *)malloc(9);
	char *ix = (char *)malloc(9);
	char *mx = (char *)malloc(9);
	_itoa_s(q, qx, 9, 2);
	_itoa_s(r, rx, 9, 2);
	_itoa_s(i, ix, 9, 2);
	_itoa_s(m, mx, 9, 2);
	printf("q = %s\n", qx);
	printf("r = %s\n", rx);
	printf("i = %s\n", ix);
	printf("m = %s", mx);
	return 0;
}
*/