//test_rat.cpp

#include <iostream>
#include <cmath>
#include "Rational.h"
#include "gmpxx.h"
using namespace std;

int main() {
  cout << "Testing gcd: ";
  mpz_class  m, n;
  m="-123123124124";
  n="13214";
  cout << " checking modulo " <<  m % n << endl;
  cout << " checking gcd " <<  gcd(m, n) << endl;

  Rational<int>  rrrr(3);
  cout << " checking coersion " << rrrr << endl;

  using coeff_type = mpz_class;
  //using coeff_type = long long;
  cout << "testing default constructor" << endl;
  Rational<coeff_type> rrr;
  cout << "   it constructs: "<< rrr << endl << endl;
  cout << "testing arrays of rationals " << endl;
  Rational<coeff_type> arr[5] = { {1,2},{5,6} };
  for (int i = 0; i != 5; ++i) {
    cout << arr[i] << " ";
  }
  cout << "\n" << endl;

  Rational<int> r1(2,-3);
  Rational<int> r2(2,4);
  cout << "r1 " << r1 << " r2 " << r2 << endl;
  r1 += r2;
  cout << "r1 += r2"<< r1  << endl;
  cout << r1 << " + " << r2 << " = " << r1+r2 << endl;
  cout << r1 << " * " << r2 << " = " << r1*r2 << endl;
  cout << r1 << " - " << r2 << " = " << r1-r2 << endl;
  cout << r1 << " / " << r2 << " = " << r1/r2 << endl;
  //Rational<int> r3(3,1);
  Rational<int> r3;
  cout << "Rational(3,1) num=" << r3.num() << " den= " << r3.den() << " get " << r3 << endl;
  cout << -r3  << endl;
  Rational<int> r4(0,1);
  cout << "Rational(0,1) num=" << r4.num() << " den= " << r4.den() << " get " << r4 << endl;
  Rational<int> r5(0,-1);
  cout << "Rational(0,-1) num=" << r5.num() << " den= " << r5.den() << " get " << r5 << endl;
  int a, b;
  cout << "Enter numbers or q: ";
  cin >> a >> b ;
  Rational<int> r6(a,b);
  cout << r6 << endl;
  r6.set(1,2);
  cout << r6 << endl;
  cout << (r6 != 0) << endl;
  cout << r5 << " " << (r5 != 0) << endl;
  cout << Rational<int>(17,1)*r2 << endl;

  return 0;
}
