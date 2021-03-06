#ifndef GUARD_grade_h
#define GUARD_grade_h

#include "Student_info.h"
#include <list>
#include <vector>

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double, double, double);

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
double grade(double, double, const std::vector<double>&);

double grade(const Student_info&);

// predicate to determine whether a student failed
bool fgrade(const Student_info&);
bool pgrade(const Student_info&);

std::list<Student_info> extract_fails(std::list<Student_info>&);

#endif
