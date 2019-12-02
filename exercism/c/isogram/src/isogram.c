#include "isogram.h"

bool
sorted_add(char* data, char c);

bool
is_isogram(const char phrase[])
{
  if (!phrase)
    return false;
  unsigned int index = 0;
  char thisChar;
  char found_letters[] = malloc(64);
  while (thisChar = phrase[index]) {

    index++;
  }
  free(found_letters);
}
