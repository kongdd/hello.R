# devtools::load_all()
library(Rcpp)

Sys.setenv("PKG_LIBS"="-lprofiler")
sourceCpp('src/arr3d.cpp')

a <- matrix(rnorm(300^2), 300, 300)
getEigenValues(a)

