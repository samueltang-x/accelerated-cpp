#include "Student_info.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <ios>
#include <stdexcept>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::domain_error;
using std::endl;
using std::ifstream;
using std::max;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;

int main() {
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  // read and store the data
  ifstream inFile;
  inFile.open("./data/students-data.txt");
  if (!inFile)
    cerr << "Failed to open data file: ./data/students-data.txt." << endl;

  while (record.read(inFile)) {
    maxlen = max(maxlen, record.name().size());
    students.push_back(record);
  }

  // alphabetize the student records
  sort(students.begin(), students.end(), compare);

  // write the names and grades
  for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
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
