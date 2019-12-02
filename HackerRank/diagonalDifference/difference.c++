#include <iostream>
#include <vector>

int right_diagonal_sum(unsigned int num, std::vector<std::vector <int> > arrays) {
  int sum = 0;
  for (int i=0; i<num; i++){
    sum += arrays[i][i];
  }
  return sum;
}

int left_diagonal_sum(unsigned int num, std::vector<std::vector <int> > arrays) {
  int sum = 0;
  unsigned int row = 0;
  unsigned int col = num;
  while (row < num) {
    sum += arrays[row][col];
    row ++;
    col --;
  }
  return sum;
}

int diagonal_difference(unsigned int num, std::vector<std::vector <int> > arrays) {
  return abs(right_diagonal_sum(num, arrays) - left_diagonal_sum(num, arrays));
}

int main(int argc, char const *argv[]) {
  unsigned int num;
  std::cin >> num;
  std::vector<std::vector<int> > arr;
  for (int row = 0; row < num; row++) {
    for (int col = 0; col < num; col++){
      std::cin >> arr[row][col];
    }
  }
  std::cout << diagonal_difference(num, arr) << '\n';
  return 0;
}
