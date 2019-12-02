#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bribe_mapping {
  int person;
  short count;
}

short* count_for_person(bribe_mapping *bribes, int size, int person) {
  for (size_t i = 0; i < size; i++) {
    if ((*bribes[i].person) == person) {
      return &bribes[i].count
    } else if ( (*bribes[i].person) == 0 ){
      return bribes[i] = &bribe_mapping{person, 0};
    }
  }
}

void minimum_bribes(int size, int* queue){
  int swaps = 0;
  bool swapped = false;
  bool keep_sorting = true;
  int temp_store;
  bribe_mapping* bribes = (bribe_mapping*) calloc(size, bribe_mapping);

  for (size_t q_pos = 0; q_pos < (size - 1); q_pos++) {
    if( keep_sorting ) {
      for (size_t sort_pos = 0; sort_pos < (size - 1); sort_pos++) {
        if( queue[sort_pos] > queue[sort_pos + 1] ) {
          short* count = count_for_person(bribes, size, queue[sort_pos]-1);
          (count*)++;
          if ( (*count) > 2 ) {
            puts("Too chaotic");
            return;
          }
        }
      }
    }
  }
}
