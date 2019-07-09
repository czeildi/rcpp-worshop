'76 R as the interface to core algorithms

6 + 1 John Chambers book

Extending R 2016

Interfaces to other software are part of R

call to ther languages in the end always looks like

```r
SEXP .Call(SEXP a, SEXP b, ...)
```

- SEXP: S expression pointer
- Rcpp: conversion back and forth
- C++: universal, general, many tools
- Rcpp Sugar -> vectorised C++: expressive
- access to external libraries
- speed gains mainly for loops, function calls

first users: MCMC folks

~50% of packages using compiled code on CRAN use Rcpp

C++ and R share the same random number generator

compiled languages
- compilation step: might have to provide place of resources, such as header files
- linking step

R vs C++

- cannot change type of variable
- scalars, not vectors by default
- copies vs no copies of vectors

In C++ you can have two functions with same name if they have different types. In R you cannot do that so that you cannot write 2 exported Rcpp functions this way.

In R luckily with only have 27 different types :)
