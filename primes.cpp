/**
 *  @file primes.cpp
 *   counts the number of primes <= a specified number 
 */

#include <iostream>
#include <cmath>
using namespace std;

#include "numtheory.h"

int main ()
{
  unsigned long long i, n, count = 0;
    n  =  10000000;
    for (i=2; i!=n+1; ++i) {
      if (isprime(i))  ++count;
    }
    cout << "The number primes <= " << n << " is " << count << endl;

    return 0;
}
