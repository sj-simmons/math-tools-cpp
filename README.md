# math-tools-cpp
Math utilities in C++

---

#### Notes
  * Together, [Polynomial.h](Polynomial.h) and [Polynomial.template](Polynomial.template) are a dynamic-memory polynomial
    template class with optional fft-based multiplication.  See the header file for documentation.

  * [bernoulli.cpp](bernoulli.cpp) computes Bernoulli numbers via their generating
    series, so via polynomial multiplication.   This is not the most efficient way to compute those numbers.  In a
    Data Structures and Algorithms course taught in Shanghai, we mainly used this code to compare the speed of 
    various implementations of polynomial multiplication.

    Type `make bernoulli; ./bernoulli` to compile and run [bernuolli.cpp](bernoulli.cpp).

    Note: for this application our polynomials have rational coefficients, implemented here in [Rational.h](Rational.h)
    and [Rational.template](Rational.template).

