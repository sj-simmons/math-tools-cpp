/**
 * @file bernoulli.cpp
 * @author Scott Simmons
 * @date 3/1/2014
 * @version 1.0
 */ 

#include <iostream>
#include "Polynomial.h"
#include "Rational.h"
#include "gmpxx.h"
using namespace std;

int main () {
  int n= 100;
  using coeff_type = mpz_class; 

  Polynomial<Rational<coeff_type>> p(n+1), one(1), berniPoly(1);

  Rational<coeff_type> a[n+1];
  a[0].set(0,1); 

  for (int i=2; i!=n+2; ++i) {
    a[i-1].set(pow(-1,i),factorial(static_cast<unsigned long>(i)));
  }

  p.set_coeffs(a);

  one[0].set(1,1);
  berniPoly[0].set(1,1);

  // refine this by taking out the i
  for (int i=1; i!=n+1; ++i) {
    berniPoly = berniPoly *  p + one ;
    berniPoly.truncate(n);
  }
  
  //cout << berniPoly << endl; 
  
  cout << "\nB_"<<n<<" = " <<
     Rational<coeff_type>(pow(-1,n)*
                         factorial(static_cast<unsigned long>(n)))*berniPoly[n] 
     << "\n" << endl;

  return 0;
}
