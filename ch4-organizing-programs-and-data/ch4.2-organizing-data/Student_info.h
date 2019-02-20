#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <string>
#include <vector>

struct Student_info {
  std::string name;
  double midterm, final;
  std::vector<double> homework;
};

#endif
