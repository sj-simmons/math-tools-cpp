/**
 * @file  Rational.h
 * @brief A template rational number class
 * @author Scott Simmons
 * @date 3/1/2014
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * Rational number template class with typename Item
 *
 *   Rational numbers are defined by specifying their numerator and denominator;
 *   e.g.,
 *
 *   using coeff_type = int;
 *   Rational<coeff_type> r(2,3);
 *
 *   Rational<coeff_type> r(7);   // coerced to 7/1
 */

#ifndef __RATIONAL_H
#define __RATIONAL_H

template <typename Item>
class Rational {
public:
  Rational(Item n = 0, Item d = 1); // constructor
  void set(Item n, Item d);
  Item num() const { return n_; }
  Item den() const { return d_; }
  Rational operator+(const Rational& r2) const
                { return Rational(n_*r2.d_+r2.n_*d_, d_*r2.d_); }
  Rational operator*(const Rational& r2) const
                             { return Rational(n_*r2.n_, d_*r2.d_); }
  Rational operator-() const { return Rational(-n_, d_); }
  Rational operator-(const Rational& r2) const
                             { return *this + ( -r2 ); }
  Rational operator/(const Rational& r2) const;

  //  fix these by putting coercing stuff to rational elsewhere??
  bool operator==(const Rational& r2) const {
    return ( n_ == r2.n_ && d_ == r2.d_);
  }
  bool operator<(const Rational& r2) const {
    return ( n_*r2.d_ < r2.n_*d_ );
  }
  bool operator>(const Rational& r2) const {
    return ( n_*r2.d_ > r2.n_*d_ );
  }
  bool operator==(const Item& r2) const {
    return (*this == Rational(r2));
  }
  bool operator!=(const Item& r2) const {
    return  not (*this == Rational(r2));
  }
  bool operator<(const Item& r2) const {
    return ( *this < Rational(r2));
  }
  bool operator>(const Item& r2) const {
    return ( *this > Rational(r2));
  }

  Rational& operator=(const int& r2)
        {  //assignment operator that coerces integers like 1 and 0
          set(r2,1);
          return *this;
        }
  Rational& operator+=(const Rational& r2)
        { *this = this->operator+(r2); return *this; }
private:
  Item n_, d_;
};

template <typename Item>
std::ostream& operator<<(std::ostream &os, Rational<Item> const& r);

#include "Rational.template"

#endif //__RATIONAL_H
