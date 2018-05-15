
#include <algorithm>
#include <cmath>

// See Numerical Recipes in C++, 3rd Edition, page 612. 
void four1(double* data, const unsigned long n, const int isign)
{
    unsigned long nn, mmax, m, j, istep, i;
    double wtemp, wr, wpr, wpi, wi, theta;
    double tempr, tempi;
 
    if ( n < 2 || n & (n-1) ) throw ("n must be power of 2 in four1");
    // reverse-binary reindexing
    nn = n << 1;
    j = 1;
    for ( i = 1; i < nn; i += 2 ) {             
        if ( j > i ) {
            std::swap( data[j-1], data[i-1] ); // exchange two cplx numbers 
            std::swap( data[j], data[i] );
        }
        m = n;
        while ( m >= 2 && j > m ) {
            j -= m;
            m >>= 1;
        }
        j += m;
    }
 
    // here begins the Danielson-Lanczos section
    mmax=2;
    while ( nn > mmax) {        //Outer loop executed log2(n) times.
        istep = mmax<<1;
        theta = isign * (6.28318530717959/mmax); 
        wtemp = sin(0.5*theta);                  
        wpr = -2.0*wtemp*wtemp;
        wpi = sin(theta);
        wr = 1.0;
        wi = 0.0;
        for ( m=1; m < mmax; m += 2 ) {
            for ( i=m; i <= nn; i += istep ) {
                j = i + mmax;    // the Danielson-Lanczos formula:
                tempr = wr * data[j-1] - wi * data[j];
                tempi = wr * data[j] + wi * data[j-1];
                data[j-1] = data[i-1] - tempr;
                data[j] = data[i] - tempi;
                data[i-1] += tempr;
                data[i] += tempi;
            }
            wtemp=wr;
            wr += wr*wpr - wi*wpi;
            wi += wi*wpr + wtemp*wpi;
        }
        mmax=istep;
    }
}
