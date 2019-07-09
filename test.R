Rcpp::evalCpp("2 + 2")

set.seed(42)
Rcpp::evalCpp("Rcpp::rnorm(2)")

Rcpp::cppFunction("
  int exampleCpp11() {
      auto x = 10;
      return x;
  }", plugins = c("cpp11"))

exampleCpp11()

library(Rcpp)

cppFunction("int f(int a, int b) {return(a + b);}")

f(21, 23)
f(21, 23.2)
f(21, NA)

f

Rcpp::sourceCpp('cpp_example.cpp')
