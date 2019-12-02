#include "stdbool.h"
#include "stdio.h"

void voidfunc() {

}

int main(int argc, char const *argv[]) {
  if (-1) puts("-1 was truthy");
  if ("") puts("the empty string was truthy");
  int var[0];
  if (var) puts("an empty array was truthy");
  // puts(undefined_value);
  // if (voidfunc()) puts("void return was true");
  return 0;
}
