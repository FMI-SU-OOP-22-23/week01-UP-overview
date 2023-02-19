#include "catch2/catch_all.hpp"
#include "solution.h"

using namespace std;


TEST_CASE( "Factorials are computed", "[factorial]" ) {
    CHECK( factorial( 1) == 1 );
    CHECK( factorial( 2) == 2 );
    CHECK( factorial( 3) == 6 );
    CHECK( factorial(10) == 3628800 );
}

TEST_CASE( "Sort is working", "[my sort]" ) {
    int a[5] = {5,3,2,1,4};
    mySort(a, 5);
    for (int i = 1; i<= 5; i++) {
        CHECK( a[i-1]  == i );
    }
}

TEST_CASE( "Feel free to write here your test cases..." ) {

}