#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "Student_info.h"
#include <vector>

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double, double, double);

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
double grade(double, double, const std::vector<double>&);

#endif
