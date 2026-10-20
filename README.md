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
- **fabius256_ld.h**, **fabius128_ld.h** and **fabius128_d.h** include the fabius function **fab(x)**, its first and second derivatives **fabd(x)**, **fabdd(x)** and integrals **fabi(x)**, **fabii(x)**
- **fabius.m** includes vectorized fabius(x,d) where d is the derivative order (negative for antiderivative)

## fabius256_ld.h (recommended)
- long double (16 byte storage), extended precision
- 256-table, degree-9, global error < 1.7e-23 dominates for $x<0.07$
- truncation error, error/fab(x) = LDBL_EPSILON (1.08e-19) dominates for $0.07 < x < 0.5$
- :exclamation: -ffast-math may degrade accuracy and invalidate the NaN guards for certain compilers

## fabius128_ld.h
- long double (16 byte storage), extended precision
- 128-table, degree-10, global error <1.7e-23 dominates for $x<0.07$
- truncation error, error/fab(x) = LDBL_EPSILON (1.08e-19) dominates for $0.07 < x < 0.5$
- :exclamation: extended precision and speed may degrade for certain settings/compilers
- :exclamation: Unhandled NaN, -ffast-math is unsafe

## fabius128_d.h
- double (8 byte storage)
- 128-table, degree-10, global error <1.7e-23 dominates for $x<0.02$
- truncation error, error/fab(x) = DBL_EPSILON (2.22e-16) dominates for $0.02 < x < 0.5$
- :exclamation: extended precision and speed may degrade for certain settings/compilers
- :exclamation: Unhandled NaN, -ffast-math is unsafe

## fabius.m and fabius_test.m
- MATLAB implementation identical to fabius128_d.h

# Additional remarks / notes for further research
- tables of 11th order and 256 segments generate global error <1.5e-27
- canonical extension outside the boundaries $0 < x < 1$ exists but is not implemented
