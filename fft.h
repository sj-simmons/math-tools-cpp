// fft.h
#ifndef _FFT_H
#define _FFT_H

/* The classical implementation of the in-place Cooley-Tukey algorithm.
 *
 * Here n, which has to be a power of 2, is the number of complex data
 * points. The array data actually has length 2n:  data[0] is the real
 * part of the first complex number; data[1] is its complex part, data[3]
 * is the real part of the second complex number, data[4] is its complex
 * part, and so on.
 *
 * If isign is 1, four1 uses an fft algorithm to replace the actual
 * parameter array (that has formal parameter called data, below) with
 * that arrays DFT.  If isign is -1, it is replace with the inverse DFT.
 */
void four1(double* data, const unsigned long n, const int isign);

#endif
