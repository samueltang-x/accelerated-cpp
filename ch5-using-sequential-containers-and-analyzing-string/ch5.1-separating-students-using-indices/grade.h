#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "Student_info.h"
#include <vector>

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double, double, double);

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
double grade(double, double, const std::vector<double>&);

double grade(const Student_info&);

// predicate to determine whether a student failed
double fgrade(const Student_info&);

std::vector<Student_info> extract_fails(std::vector<Student_info>&);

#endif
