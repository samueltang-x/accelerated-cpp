#include "../../ch5-using-sequential-containers-and-analyzing-string/ch5.5-separating-students-using-iterators-list/grade.h"
#include <algorithm>
#include <iterator>

using std::back_inserter;
using std::remove_copy_if;
using std::remove_if;
using std::vector;

vector<Student_info> extract_fails(vector<Student_info>& students) {
  vector<Student_info> fails;
  remove_copy_if(students.begin(), students.end(), back_inserter(fails), pgrade);
  students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());

  return fails;
}
