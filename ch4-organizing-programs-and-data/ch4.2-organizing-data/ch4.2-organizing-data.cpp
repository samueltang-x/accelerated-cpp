#include "Student_info.h"
#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <istream>
#include <stdexcept>

using std::cout;
using std::cin;
using std::domain_error;
using std::endl;
using std::istream;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

// compute the median of a vector<double>
double median(vector<double> vec) {
  typedef vector<double>::size_type vec_sz;

  vec_sz size = vec.size();

  if (size == 0)
    throw domain_error("median of an empty vector");

  sort(vec.begin(), vec.end());

  vec_sz mid = size / 2;

  return size % 2 == 0 ? (vec[mid - 1] + vec[mid]) / 2 : vec[mid];
}

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework) {
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
double grade(double midterm, double final, const vector<double>& hw) {
  if (hw.size() == 0)
    throw domain_error("Student has done no homework");

  return grade(midterm, final, median(hw));
}

double grade(const Student_info& s) {
  return grade(s.midterm, s.final, s.homework);
}

// read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, vector<double>& hw) {
  if (in) {
    hw.clear(); // get rid of previous contents

    // read homework grades
    double x;
    while (in >> x)
      hw.push_back(x);

    // clear the stream so that input will work for the next student
    in.clear();
  }

  return in;
}

istream& read(istream& is, Student_info& s) {
  // read and store the student's name and midterm and final exam grades
  is >> s.name >> s.midterm >> s.final;

  read_hw(is, s.homework);  // read and store all the student's homework grades

  return is;
}

bool compare(const Student_info& x, const Student_info& y) {
  return x.name < y.name;
}

int main() {
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  cout << "Please enter student records, each one a line, for example:" << endl
    << "Smith 93 91 47 90 92 73 100 87" << endl
    << "Carpenter 75 90 87 92 93 60 0 98" << endl
    << "..." << endl
    << "Press CTRL + D to finish input:" << endl;
  // read and store all the students, and find the length of the longest name
  while (read(cin, record)) {
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }
  cout << endl;

  // alphabetize the records
  sort(students.begin(), students.end(), compare);

  typedef vector<Student_info>::size_type vec_sz;
  for (vec_sz i = 0; i != students.size(); ++i) {
    // write the name, padded on the right to maxlen + 1 characters
    cout << students[i].name
      << string(maxlen + 1 - students[i].name.size(), ' ');

    // compute and write the grade
    try {
      double final_grade = grade(students[i]);
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
        << setprecision(prec);
    } catch (domain_error e) {
      cout << e.what();
    }

    cout << endl;
  }

  return 0;
}
