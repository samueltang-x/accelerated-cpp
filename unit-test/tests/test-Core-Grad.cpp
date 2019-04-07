#include "../../ch13-using-inheritance-and-dynamic-binding/Grad.h"
#include "../tools/files.h"

#include <algorithm>
#include <fstream>
#include <ios>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::max;
using std::setprecision;
using std::streamsize;
using std::sort;
using std::string;
using std::vector;

bool test_Core_Grade() {
  vector<Core*> students;
  Core* record;
  char ch;
  string::size_type maxlen = 0;

  ifstream data_file("data/students_grade.txt");
  ofstream report_file("report/students_grade.txt");

  while(data_file >> ch) {
    if (ch == 'U')
      record = new Core;
    else
      record = new Grad;
    record->read(data_file);
    maxlen = max(maxlen, record->name().size());
    students.push_back(record);
  }
  data_file.close();

  sort(students.begin(), students.end(), compare_Core_ptrs);

  for (vector<Core*>::size_type i = 0; i != students.size(); ++i) {
    report_file << students[i]->name()
      << string(maxlen + 1 - students[i]->name().size(), ' ');

    try {
      double final_grade = students[i]->grade();
      streamsize prec = report_file.precision();
      report_file << setprecision(3) << final_grade
        << setprecision(prec) << endl;
    } catch (domain_error e) {
      report_file << e.what() << endl;
    }
    delete students[i];
  }

  report_file.close();

  return areSameContentFiles("report/students_grade.txt", "expect/students_grade.txt");
}
