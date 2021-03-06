#include "grade.h"
#include "median.h"
#include <stdexcept>

using std::domain_error;
using std::vector;

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

// predicate to determine whether a student failed
double fgrade(const Student_info& s{
  return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students) {
  vector<Student_info> fail;
  vector<Student_info>::size_type i = 0;

  // invariant: elements[0, i) of students represent passing grades
  while (i != students.size()) {
    if (fgrade(students[i])) {
      fail.push_back(students[i]);
      students.erase(students.begin() + i);
    } else
      ++i;
  }

  return fail;
}
