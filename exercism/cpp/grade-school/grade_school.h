#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H
#include <map>
namespace grade_school {
class school {
private:
  std::map<int, std::vector<std::string>> classes;

public:
  school(){};
  bool empty() { return true; }
  void add(std::string student_name, int grade) {
    classes[grade].push_back(student_name);
  }
};
} // namespace grade_school
#endif // GRADE_SCHOOL_H