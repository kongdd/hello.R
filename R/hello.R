#' @export
hello <- function(x, t = NULL, a = 1, ...) UseMethod("hello", x)

#' @export
hello.default <- function(x, t = NULL, ...) {
    browser()
    print("hello.default")
}

#' @export
hello.list <- function(x, ...) {
    print("hello.list")
    # print(list())
}
