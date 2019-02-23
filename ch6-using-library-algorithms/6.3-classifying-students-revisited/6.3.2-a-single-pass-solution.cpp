#include "../../ch5-using-sequential-containers-and-analyzing-string/ch5.5-separating-students-using-iterators-list/grade.h"
#include <algorithm>

using std::stable_partition;
using std::vector;

vector<Student_info> extract_fails_partition(vector<Student_info>& students) {
  typedef vector<Student_info>::iterator iter;
  iter sep = stable_partition(students.begin(), students.end(), pgrade);

  vector<Student_info> fails(sep, students.end());
  students.erase(sep, students.end());

  return fails;
}
