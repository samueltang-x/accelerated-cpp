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
