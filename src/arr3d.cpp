#include <RcppArmadillo.h>
// #include <gperftools/profiler.h>

using namespace Rcpp;
// using namespace arma;

// #include <Rcpp.h>
// using namespace std;

// // [[Rcpp::export]]
// arma::vec getEigenValues(arma::mat M) {
//     ProfilerStart("./eigen-prof.log");
//     return arma::eig_sym(M);
//     ProfilerStop();
// }

// [[Rcpp::export]]
NumericVector arrayC(NumericVector input, IntegerVector dim) {
    input.attr("dim") = dim;
    // Rcout << "The value is " << input(_, 1) << std::endl;
    return input;
}


// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::export]]
void arr3d(arma::cube forcing_3d, NumericMatrix soil_par_mat,
           List forcing_veg_list) {
    int i = 0;
    NumericMatrix forcing = wrap(forcing_3d.slice(i));
    NumericVector soil_par = soil_par_mat(i, _);
    NumericMatrix forcing_veg = forcing_veg_list[i];
    // Normal Matrix dimensions
    // unsigned int xdim = arr.n_rows;
    // unsigned int ydim = arr.n_cols;
    // unsigned int tdim = arr.n_slices;
    // arma::mat
    // auto mat = ;
    // NumericMatrix temp = as<NumericMatrix>(wrap(mat)); // works
    // NumericMatrix temp = wrap(arr.slice(1));

    // input.attr("dim") = dim;
    // Rcout << "The value is " <<  temp(0, 0) << std::endl;
    Rcout << forcing << std::endl;
    Rcout << soil_par << std::endl;
    Rcout << forcing_veg << std::endl;
    // return wrap(mat);
}
