#include <Rcpp.h>
#include <unistd.h>
using namespace Rcpp;

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//

// [[Rcpp::export]]
// ~ roxygen @export tag
NumericVector timesTwo(NumericVector x) {
  return x * 2;
}


// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically
// run after the compilation.
//

/*** R
timesTwo(c(42, 12))
*/


// [[Rcpp::export]]
int fib(int n) {
    if (n < 2) return(n);
    return(fib(n - 1) + fib(n - 2));
}

/*** R
fib(35)
*/

// [[Rcpp::export]]
NumericVector mysleep() {
    sleep(2); // #include <unistd.h> is needed for this
    return 1.23;
}

/*** R
mysleep()
*/
