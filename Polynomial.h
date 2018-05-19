/**
 * @file Polynomial.h
 * @author Scott Simmons
 * @date 3/1/2014
 * @version 1.0
 *
 * @brief A polynomial template class.
 *
 * @section DESCRIPTION
 *
 * Polynomial class with dynamic memory (template class with typename Item)
 *
 *   Polynomials are defined  by passing an actual parameter of an integer
 *   that specifies the number of coefficients. The method set_coeffs() is
 *   used to specify the coefficients; e.g.,
 *
 *   using coeff_type = int;                using coeff_type = long;
 *   Polynomial<coeff_type> p(8);    or     Polynomial<coeff_type> *q(8);
 *   Item a[8] = {1,-2,2,1};                Item b[8] {1,2,-1,1,1,1,1,1};
 *   p.set_coeffs(a);                       q -> set_coeffs(b);
 *
 *   The bracket operator[] is implemented so that, e.g., p[1] returns -2
 *   and (*q)[2] or q -> operator[2] return -1.
 *
 *   Carefully, a polynomial can also be defined as follows (if for ex-
 *   ample one is concerned about the overhead of the arrays a or b above).
 *
 *   using coeff_type = int;
 *   Polynomial<coeff_type> z(10);
 *   for (int i=0; i < 10; ++i)
 *     z[i]=i+1;
 *
 *   Important: the first line, Polynomial z(10), does NOT initialize
 *   the coefficients; so, when defining a Polynomial this way, set ALL
 *   of the coefficients manually.
 *
 *   Note: If one uses the set_coeffs method, any trailing zeros will be
 *   stripped away and the degree will be set correctly.  If one does not
 *   use set_coeffs, trailing zeros may remain.
 *
 *   For example,
 *
 *   Polynomial<coeff_type> z(1); z[0] = 0;
 *
 *   does not define correctly the Polynomial 0.  A quick way to do that
 *   is
 *
 *   Polynomial<coeff_type> z(0);
 *
 *   or, using the default constructor,
 *
 *   Polynomial<coeff_type> z;     or     Polynomial<coeff_type> z {};
 *
 *   Although in most applications it shouldn't be necessary, one may
 *   manually (as opposed to using operations on the level of Polynomials)
 *   change the value of some or all of the coefficients (up to and includ-
 *   ing that of the term of highest degree) of a previously initialized
 *   Polynomial using the bracket operator.
 *
 * CONSTRUCTOR
 *
 *   Polynomial(int numcoeffs);
 *     Set degree_ to numcoeffs-1 and dynamically allocate an array of
 *     Items of size numcoeffs if numcoeffs is greater than 0.  The
 *     Item coeffs_ points to the array.  If numcoeffs is 0, coeffs_
 *     is set to NULL.
 *
 * PRIVATE INSTANCE VARIABLES
 *
 *   Item *coeffs_;
 *     Pointer to an array of size degree_+1 holding the coefficients or
 *     NULL in the case of the zero Polynomial.  Upon instantiation, the
 *     array is size numcoeffs. Calling set_coeffs (see below) results in
 *     it being downsized to size degree_+1 if warranted.
 *
 *     In both instances above, the array pointed to by *coeffs_ original-
 *     ly holds 8 Items.  However, in the first instance above, the array
 *     is downsized by set_coeffs() to hold 4 Items.
 *
 *   int degree_;
 *     The mathematical degree of the Polynomial. The Polynomial 0 has
 *     degree -1.
 *
 * PUBLIC METHODS (in addition to the destructor, the copy constructor,
 *                 and the assignment operator)
 *
 *   void set_coeffs(Item coeffs[])
 *     Initially, copy coeffs to the dynamically allocated array coeffs_
 *     that was created by the constructor.  Then call set_degree_().
 *     Then, if necessary, downsize coeffs_ to hold exactly degree_+1
 *     Items or, in the case of the zero polynomial, set coeffs_ to NULL.
 *
 *   int degree()
 *     Return degree_ the mathematical degree; i.e., the highest power of
 *     x with a nonzero coefficient.
 *
 *   void truncate(int n)
 *     Take the Polynomial modulo x^(n+1), downsizing appropriately.
 *
 *   Polynomial fftmult(Polynomial p2);
 *     Return the product of polynomials computed using the FFT.
 *     Note: typename Item must be double.
 *
 * OVERLOADED OPERATORS
 *    +  component-wise polynomial addition
 *    -  component-wise polynomial subtraction
 *    -  negation
 *    *  multiplication (non FFT-based)
 *   <<  ostream
 *   []  bracket operator
 *   +=
 *
 *   Note:
 *     The overloaded multiplication operator * does not use an FFT-
 *     based algorithm; its algorithm is O(n^2) but with a relatively
 *     small constant compared to the obvious n^2 algorithm.
 *
 *     (See chapter 17, section 17.2, the section on vector convolutions
 *     in the text Algorithms and Theory of Computation Handbook (1999)
 *     for the initial formulation leading to the algorithm used in the
 *     implementation of the overloaded multiplication operator below.)
 *
 * FUNCTIONS
 *
 *   Polynomial<Item> pow(Polynomial<Item> p, int n)
 *     Return p raised to the positive integral power n computed
 *     recursively using overloaded multiplication *.
 *
 *   Polynomial<Item> fftpow(Polynomial<Item> p, int n)
 *     Return p raised to the positive integral power n computed
 *     recursively using fftmult.
 *
 * PRIVATE METHODS
 *
 *   void copy(const Polynomial &p)
 *     Utility method used by the copy constructor and the assign-
 *     ment operator.
 *
 *   set_degree_();
 *     Set degree_ to the mathematical degree of the Polynomial.
 *
 *   void downsize_();
 *     Downsize the array coeffs_ points to so that it holds degree_+1
 *     number of Items or de- allocate the array if degree_ is -1.
 *
 * Copyright 2014 Scott Simmons
 */

#ifndef __POLYNOMIAL_H
#define __POLYNOMIAL_H
#include <ostream>

template <typename Item>
class Polynomial
{
public:
  Polynomial(int numcoeffs = 0); // constructor
  Polynomial(const Polynomial &source); // copy constructor
  ~Polynomial(); // destructor

  Item& operator[](int pos) const;
  Polynomial& operator=(const Polynomial &source);
  Polynomial& operator+=(const Polynomial &source);
  void set_coeffs(Item coeffs[]);
  int degree() const {return degree_;}
  void truncate(int n);
  Polynomial operator+(const Polynomial &p2) const;
  Polynomial operator-(const Polynomial &p2) const;
  Polynomial operator-() const;
  Polynomial operator*(const Polynomial &p2) const;
  Polynomial fftmult(const Polynomial &p2) const;
private:
  void copy(const Polynomial &p);
  void set_degree_();
  void downsize_();
  Item *coeffs_;
  int degree_;
};

template <typename Item>
Polynomial<Item> pow(const Polynomial<Item> &p, unsigned n);

template <typename Item>
Polynomial<Item> fftpow(const Polynomial<Item> &p, unsigned n);

template <typename Item>
std::ostream& operator<<(std::ostream &os, const Polynomial<Item> &p);

template <typename Item>
inline Item& Polynomial<Item>::operator[](int pos) const
{
  return coeffs_[pos];
}

#include "Polynomial.template"

#endif //__POLYNOMIAL_H
