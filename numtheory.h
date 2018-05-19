/**
 * @file numtheory.h
 * @author Scott Simmons
 * @date 3/1/2014
 * @version 1.0
 */

#ifndef __NUMTHEORY_H
#define __NUMTHEORY_H

#include <gmpxx.h>

mpz_class gcd(mpz_class n, mpz_class m) {
  mpz_class d;
  mpz_gcd(d.get_mpz_t(), n.get_mpz_t(), m.get_mpz_t());
  return d;
}

template <typename Item>
Item gcd(Item n, Item m) { return (m == 0 ) ? n : gcd(m, n % m); }
// same as:
//template <typename Item>
//Item constexpr gcd(Item n, Item m) {
//  if (n % m == 0) { return m; }
//  else return gcd(m, n % m);
//}

mpz_class factorial(unsigned long n) {
  mpz_class d;
  mpz_fac_ui(d.get_mpz_t(), n);
  return d;
}

/*
template <typename Item>
inline Item factorial(Item n) {
  Item prod = 1;
  for (int i = 2; i != n+1; ++i) prod *= i;
  return prod;
}
*/

template <typename Item>
inline Item raiseTo(Item base, unsigned exponent) {
  if (exponent == 0) return 1;
  if (exponent == 1) return base;
  if (exponent % 2 == 0) {
    Item ressqrt = raiseTo(base,exponent/2);
    return ressqrt*ressqrt;
  }
  if (exponent % 3 == 0) {
    Item rescubrt = raiseTo(base,exponent/3);
    return rescubrt*rescubrt*rescubrt;
  }
  else return base * raiseTo(base, --exponent);
}

/* Computes a^n modulo m efficiently */
template <typename Item>
inline Item powmod( Item a, Item n, Item m) {
  a %= m;
  Item prod = 1;
  while (n > 0) {
    if (n & 1) prod = prod * a % m;
    a = a * a % m;
    n >>= 1;
  }
  return prod;
}


// Checks for primality with fairly high accuracy see implementation file
// for details.
template <typename Item>
int isprime( Item n );

#include "numtheory.template"

#endif //__NUMTHEORY_H
