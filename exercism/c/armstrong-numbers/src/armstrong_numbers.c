#include "armstrong_numbers.h"
#include <math.h>
#include <stdlib.h>

bool
isArmstrongNumber(int number)
{
  int given = number; // save for later
  int result = 0;
  char numDigits = floor(log10(number)) + 1;
  while (number) {
    result += pow(number % 10, numDigits);
    number /= 10;
  }
  return result == given;
}
