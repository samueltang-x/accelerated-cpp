#ifndef Student_info_h
#define Student_info_h

#include <iostream>
#include <string>
#include <vector>

struct Student_info {
  std::string name;
  double midterm, final;
  std::vector<double> homework;

  std::istream& read(std::istream&);
  double grade() const;
}

#endif
