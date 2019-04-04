#include "Grad.h"
#include "../ch6-using-library-algorithms/6.2-comparing-grading-schemas/read.h"

#include "algorithm"

using std::min;

using std::istream;

istream& Grad::read(istream& is) {
  read_common(is);
  is >> thesis;
  read_hw(is, homework);
  return is;
}

double Grad::grade() const {
  return min(thesis, Core::grade());
}
