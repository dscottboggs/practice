#include "difference_of_squares.h"
int squares::square_of_sum(int value) {
  int output{0};
  for (int i = 0; i <= value; i++)
    output += i;
  return output * output;
}
int squares::sum_of_squares(int value) {
  int output{0};
  for (int i = 0; i <= value; i++)
    output += i * i;
  return output;
}
int squares::difference(int value) {
  return square_of_sum(value) - sum_of_squares(value);
}