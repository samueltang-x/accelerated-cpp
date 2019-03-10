#include "../ch6-using-library-algorithms/6.1.1-another-way-to-split.h"
#include "../ch9-defining-new-types/9.3-protection/Student_info.h"
#include "Vec.h"
#include "test-Vec.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

using std::cerr;
using std::cout;
using std::domain_error;
using std::endl;
using std::getline;
using std::ifstream;
using std::ios;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;

int test_vec() {
  Vec<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  // read and store the data
  ifstream inFile("data/students-data.txt"); 
  if (!inFile) {
    cerr << "Failed to open input file: data/students-data.txt" << endl;
    return 1;
  }

  while (record.read(inFile)) {
    maxlen = max(maxlen, record.name().size());
    students.push_back(record);
  }

  // alphabetize the student records
  sort(students.begin(), students.end(), compare);

  // write the names and grades
  for (Vec<Student_info>::size_type i = 0; i != students.size(); ++i) {
    cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');

    try {
      double final_grade = students[i].grade();
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
        << setprecision(prec) << endl;
    } catch (domain_error e) {
      cout << e.what() << endl;
    }
  }
  return 0;
}
