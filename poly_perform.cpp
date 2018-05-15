//poly_perform.cpp

#include <iostream>
#include <time.h>
#include "Polynomial.h"

using namespace std;

int main () {
  
  using coeff_type = int; 
  
  cout << "testing default constructor:  " << endl;
  Polynomial<coeff_type> ppp;
  cout << "   default constructor constructs: " << ppp << " of degree "<< 
                                 ppp.degree() << endl << endl;
  Polynomial<coeff_type> p(8), p1(5);
  coeff_type  p_coeffs[8]={1,-1,1,-1,1,-1,1,2};  
  p.set_coeffs(p_coeffs);
  coeff_type  p1_coeffs[5]={1,-1};  
  p1.set_coeffs(p1_coeffs);
//  cout << pow(p,4) << "\n";
  cout << "p = " << p << ", p1 = " << p1 << "\n";
//  cout << p*p1 << "\n";
  cout << "testing addition p-p1  " << p-p1 << endl;
  cout << "testing addition p1+p  " << p1+p << endl;
  
  Polynomial<coeff_type> pz(0);
 // pz[0] = 0;
  cout << " 0 poly " << pz << endl;
  cout << "degree of 0 " << pz.degree() << endl;
  cout << " 0 + 0 " << pz + pz << endl;
  cout << "testing addition p1+0  " << p1+pz << endl;
  cout << "testing addition 0+p1  " << pz+p1 << endl;
  cout << "truncating p n=6" << endl;
  p.truncate(6);
  cout << "new p " << p << endl;

  cout << "raising " << p << " to the 300 power: \n elapsed time is ";
  clock_t t;
  t = clock();
  //cout <<"\n" << pow(p,300) << endl;
  pow(p,300);
  t = clock() - t; 
  cout << ((float)t)/CLOCKS_PER_SEC << " seconds" << endl;

/*
  cout << "now raising p to the 300 power using fftpow: \n elapsed time is ";
  clock_t t2;
  t2 = clock();
  fftpow(p,300);
  t2 = clock() - t2; 
  cout << ((float)t2)/CLOCKS_PER_SEC << " seconds" << endl;
*/

  return 0;
}
