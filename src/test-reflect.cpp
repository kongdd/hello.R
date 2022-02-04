#include <iostream>
#include "Reflect.h"
#include <Rcpp.h>

using namespace std;
using namespace Reflect;

template <class T>
std::vector<std::string> get_field_names(bool verbose = true){
    const int n = T::Class::TotalFields;
    auto fields = T::Class::Fields;

    // std::string *names = new std::string[n];
    std::vector<std::string> names(n);
    for (size_t i = 0; i < n; i++) {
        if (verbose) std::cout << fields[i].name << std::endl;
        names[i] = fields[i].name;
    }
    return names;
    // return Rcpp::wrap(names);
}

/**
 * @references
 * 1. https://stackoverflow.com/questions/41453/how-can-i-add-reflection-to-a-c-application
 * 2. https://github.com/TheNitesWhoSay/RareCpp
 * 3. https://stackoverflow.com/questions/7527356/return-string-array-in-c-function
 */

class FuelTank {
   public:
    float capacity;
    float currentLevel;
    float tickMarks[2];

    REFLECT(FuelTank, capacity, currentLevel, tickMarks)
};

/** @reference
 * 1. std::vector<std::string> to Rcpp::CharacterVector, 
 *    http://www2.stat.duke.edu/~cr173/Sta790_Sp19/slides/Lec09.html
 */

// [[Rcpp::export]]
Rcpp::CharacterVector guess_filedNames() {
    // vector<string>
    auto names = get_field_names<FuelTank>();
    // Rcpp::CharacterVector names2 = 
    return Rcpp::CharacterVector(names.begin(), names.end());
    // Rcpp::as<Rcpp::CharacterVector>(names);
    // get_field_names<FuelTank>();
    // auto n = names.size();
    // return 1;
}
