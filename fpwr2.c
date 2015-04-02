/*
 * author: Marcio Porto
 * COMP 240-02 - HW2
 */

#include <stdio.h>
#include <assert.h>

/*
 * Computes a floating point representation of 2^x
 * Input = x
 * Output = unsigend value u 
 */
unsigned fpwr2(int x){
	/* Result exponent and fraction */
	unsigned exp, frac;
	unsigned u;
	if (x < -149) {
		/*Too small. Return 0.0 */
		exp = 0;
		frac = 0;
	}
	else if (x < -126){
		/* denormalized result */
		exp = 1;
		frac = 1 << (x + 149);
	}
	else if (x < 128){
		/*Normalized result. */
		exp = x + 127;
		frac = 0;
	}
	else {
		/*Too big. Return +oo */
		exp = 255;
		frac = 0	;
	}
	/* Pack exp and frac into 32 bits */
	u = exp << 23 | frac;
	/* Return as unsigned */
	return u;
}

/*
 * Helper function taken from fp_coding_ex.c
 * Returns a floating point representation of the input integer x
 */
float float_denorn_zero(int f) {
    /* Decompose bit representation into parts */
    unsigned sign = f>>31;
    unsigned exp =  f>>23 & 0xFF;
    unsigned frac = f     & 0x7FFFFF;
    
    if (exp == 0) {  // denormalized
      frac = 0;
    }
    
    printf(" Sign: %u\n Exp: %u\n Frac: %u\n", sign, exp, frac);
  
    return (sign << 31) | (exp << 23) | frac;
}

// Test cases that demonstrate correctness of the function
int main() {

    assert(float_denorn_zero(fpwr2(-150)) == 0x00000000);               // tests the if statement condition
    assert(float_denorn_zero(fpwr2(-127)) == 12582912.000000);          // tests the first else if condition
    assert(float_denorn_zero(fpwr2(127)) == 0x7f000000);                // tests the second else if condition
    assert(float_denorn_zero(fpwr2(150)) == 0x7f800000);                // tests the else condition
  
    return 0;

}