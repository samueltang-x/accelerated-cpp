#include "Grad.h"

#include <algorithm>
#include <fstream>
#include <ios>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

using std::cout;
using std::domain_error;
using std::endl;
using std::ifstream;
using std::max;
using std::setprecision;
using std::streamsize;
using std::sort;
using std::string;
using std::vector;

int main() {
  vector<Core*> students;
  Core* record;
  char ch;
  string::size_type maxlen = 0;

  ifstream is("students_grade.txt");

  while(is >> ch) {
    if (ch == 'U')
      record = new Core;
    else
      record = new Grad;
    record->read(is);
    maxlen = max(maxlen, record->name().size());
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare_Core_ptrs);

  for (vector<Core*>::size_type i = 0; i != students.size(); ++i) {
    cout << students[i]->name()
      << string(maxlen + 1 - students[i]->name().size(), ' ');

    try {
      double final_grade = students[i]->grade();
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
        << setprecision(prec) << endl;
    } catch (domain_error e) {
      cout << e.what() << endl;
    }
    delete students[i];
  }
  return 0;
}
