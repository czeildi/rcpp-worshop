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
fib(15)
*/

// [[Rcpp::export]]
NumericVector mysleep() {
    sleep(2); // #include <unistd.h> is needed for this
    return 1.23;
}

/*** R
mysleep()
*/

// [[Rcpp::export]]
NumericVector mymax(NumericVector a) {
    return(a[0]);
}

// it does not through an error if you access non-existent element...
/*** R
mymax(numeric(0))
*/

// [[Rcpp::export]]
IntegerVector mysum(IntegerVector b) {
    Rcpp::IntegerVector res(1);
    // sum from Rcpp sugar returns integer, not an integervector, so have to use
    // this way
    res[0] = Rcpp::sum(b);
    return res;
}

/*** R
mysum(c(3, 4, 5))
*/

// [[Rcpp::export]]
int mysum2(IntegerVector b) {
    int res = Rcpp::sum(b);
    return res;
}

/*** R
mysum2(c(3, 4, 5))
*/

// [[Rcpp::export]]
IntegerVector cumsum(IntegerVector b) {
    IntegerVector res = Rcpp::cumsum(b);
    return res;
}

/*** R
cumsum(c(3, 4, 5))
*/

// [[Rcpp::export]]
int missing(IntegerVector b) {
    return R_NaInt;
}

/*** R
missing(c(3, 4, 5))
*/

// does not work
// IntegerVector missing2(IntegerVector b) {
//     return R_NaInt;
// }
//
// /*** R
// missing2(c(3, 4, 5))
// */

// cumsum only works with NumericVector, not with std::vector<double>
// you can use native C++ vectors as well
// [[Rcpp::export]]
std::vector<int> cumsum2(std::vector<int> b) {
    int s = b.size();
    std::vector<int> res(s);
    for (int i = 0; i < s; i++) {
        if (i == 0) {
            res[i] = b[i];
        } else {
            res[i] = res[i - 1] + b[i];
        }
    }
    return res;
}

/*** R
cumsum2(c(3, 4, 5))
*/

// function with side effect
// [[Rcpp::export]]
void setSecond(Rcpp::NumericVector v) {
    v[1] = 42;
}

/*** R
v <- c(1, 2, 3)
setSecond(v)
v
# type conversion -> copy -> modify by reference does not work
w <- c(1L, 2L, 3L)
setSecond(w)
w
*/
