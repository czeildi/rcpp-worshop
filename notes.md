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
