#define CATCH_DEFAULT_MAIN // or perhaps something else?
#include "catch.hpp"
#include <vector>
#include "difference.o"

using namespace std;

class ValueForTests {
  public:
    // Values:
    // type               name
    vector< vector<int> > arrays;
    int                   leftSum;
    int                   rightSum;
    int                   diff;

    // Constructor
    ValueForTests (
      vector< vector < int > > arrays, int leftSum, int rightSum, int diff
    ): leftSum(leftSum), rightSum(rightSum), diff(diff) {
      this->arrays = arrays;
    }
};
vector<vector <int> > vec0 = {
   { 11,  2,   4},
   {  4,  5,   6},
   { 12,  8, -12}
 };
vector<vector <int> > vec1 = {
  { 15,  7, 90,  2},
  {356, -5, -2,  0},
  {50,  50, 50, 50},
  {-50,  0,  0, 60}
};
vector<ValueForTests> values = {
  new ValueForTests( vec0, 4, 19, 15),
  new ValueForTests(vec1, 0, 0, 0)
};

//int main(int argc, char const *argv[]) {
for (unsigned int i; i < values.size(); i++){
    TEST_CASE( sprintf("Vector #%d.", i+1),"[vector]"){
        SECTION("Left Diagonal"){
            REQUIRE(
                left_diagonal_sum(values[i].arrays) == values[i].leftSum
            );
        }
        SECTION("Right Diagonal"){
            REQUIRE(
                right_diagonal_sum(values[i].arrays) == values[i].rightSum
            );
        }
        SECTION("Absolute value of the difference between the two sums"){
            REQUIRE(
                diagonalDifference(values[i].arrays) == values[i].diff
            );
        }
    }
}
//     return 0;
// }
