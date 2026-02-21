The Fabius function is a function that is:

- Infinitely differentiable ($C^\infty$)
- Nowhere analytic
- Strictly increasing on $[0,1]$
- Defined by a self-similar functional equation

It is uniquely determined by:

- $F(0)=0$
- $F'(x)=2F(2x)$ for $x\ge 0$
- $F(x)+F(1-x)=1$ for $0\le x\le 1$

Despite being smooth everywhere, its Taylor series at any point does not converge to the function. 

The Fabius function is typically calculated from recursion or other slow methods.
This implementation features in c/c++ a segmented Chebyshev polynomial interpolation implemented in extended precision.

Specifications:
- long double (16 byte storage)
- uses boundary convention $F(x)=1$ for $x\ge 1$ and $F(x)=0$ for $x\le 0$
- contains also the first and second derivative / integral, specified in fabius.h
- 128 segments, 10th order, global error <2e-23 (not accounting for truncations)

The Fabius function is a part of the Zymplectic project
