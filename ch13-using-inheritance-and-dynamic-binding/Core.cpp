#include "Core.h"
#include "../ch9-defining-new-types/9.3-protection/grade.h"
#include "../ch6-using-library-algorithms/6.2-comparing-grading-schemas/read.h"

using std::istream;
using std::string;

string Core::name() const { return n; }

double Core::grade() const {
  return ::grade(midterm, final, homework);
}

istream& Core::read_common(istream& is) {
  is >> n >> midterm >> final;
  return is;
}

istream& Core::read(istream& is) {
  read_common(is);
  read_hw(is, homework);
  return is;
}

bool compare(const Core& c1, const Core& c2) {
  return c1.name() < c2.name();
}

bool compare_grade(const Core& c1, const Core& c2) {
  return c1.grade() < c2.grade();
}

bool compare_Core_ptrs(const Core* cp1, const Core* cp2) {
  return compare(*cp1, *cp2);
}
