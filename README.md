# Fabius function
The Fabius function is a function that is:

- Infinitely differentiable ($C^\infty$)
- Nowhere analytic
- Strictly increasing on $[0,1]$
- Defined by a self-similar functional equation

It is uniquely determined by:

- $F(0)=0$
- $F\prime(x) = 2F(2x)$ for $x\ge 0$
- $F(x)+F(1-x)=1$ for $0\le x\le 1$

The boundaries may be defined as $F(x)=1$ for $x\ge 1$ and $F(x)=0$ for $x\le 0$

Despite being smooth everywhere, its Taylor series at any point does not converge to the function. 

The Fabius function is typically calculated from recursion or other slow methods.
This implementation features in c/c++ a segmented Chebyshev polynomial interpolation implemented in extended precision.

<img width="768" height="768" alt="fabius function" src="https://github.com/user-attachments/assets/5d5d950c-8cc7-468a-b66d-639fd7b15dd7" />

The Fabius function is a part of the [Zymplectic project](https://github.com/Zymplectic/Zymplectic-Project) (image rendered in Zymplectic software)

# Contents
- **fabius.h** and **fabiuslite.h** include the fabius function **fab(x)**, its first and second derivatives **fabd(x)**, **fabdd(x)** and integrals **fabi(x)**, **fabii(x)**
- 128 segments, 10th order
- table obtained using 1024 control points per segment with global error <1.7e-23
- :exclamation: truncation errors may be doubled by some flags enabled by -ffast-math

## fabius.h
- long double (16 byte storage), extended precision
- global error <1.7e-23 dominates for $x<0.07$
- truncation error, error/fab(x) = LDBL_EPSILON (1.08e-19) dominates for $0.07 < x < 0.5$
- :exclamation: extended precision may be lost for certain settings/compilers

## fabiuslite.h
- double (8 byte storage)
- global error <1.7e-23 dominates for $x<0.02$
- truncation error, error/fab(x) = DBL_EPSILON (2.22e-16) dominates for $0.02 < x < 0.5$

# Additional remarks / notes for further research
- tables of 11th order and 256 segments generate global error <1.5e-27
- the coefficients governed by the dyadic structure allows direct calculation of some coefficients. Perhaps one may directly calculate coefficients for arbitrary orders
