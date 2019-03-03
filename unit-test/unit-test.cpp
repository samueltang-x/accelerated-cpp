#include <gtest/gtest.h>
#include "../ch6-using-library-algorithms/6.3-classifying-students-revisited/6.3.1-a-two-pass-solution.cpp"
#include "../ch6-using-library-algorithms/6.3-classifying-students-revisited/6.3.2-a-single-pass-solution.cpp"
#include "../ch8-writing-generic-functions/src/median-of-unknown-type.cpp"

using std::vector;

bool students_equal(const vector<Student_info>& v1, const vector<Student_info>& v2) {
  typedef vector<Student_info>::size_type vec_sz;
  if (v1.size() != v2.size())
    return false;

  for (vec_sz i = 0; i != v1.size(); ++i) {
    if (!(v1[i].name == v2[i].name))
      return false;
  }

  return true;
}

// 6.3.1-a-two-pass-solution.cpp
TEST(ClassifyingStudents, extractFails) {
  vector<Student_info> students, epass, efail;
  Student_info s;
  s.name = "Smith";
  s.midterm = 93;
  s.final = 91;
  s.homework = {47, 90, 92, 73, 100, 87};
  students.push_back(s);
  epass.push_back(s);

  s.name = "Carpenter";
  s.midterm = 75;
  s.final = 90;
  s.homework = {87, 92, 93, 60, 0, 98};
  students.push_back(s);
  epass.push_back(s);

  s.name = "Jan";
  s.midterm = 55;
  s.final = 20;
  s.homework = {37, 42, 43, 20, 10, 28};
  students.push_back(s);
  efail.push_back(s);

  vector<Student_info> afail;
  afail = extract_fails(students);

  EXPECT_TRUE(students_equal(students, epass));
  EXPECT_TRUE(students_equal(afail, efail));
}

// 6.3.2-a-single-pass-solution.cpp
TEST(ClassifyingStudents, extractFails_partition) {
  vector<Student_info> students, epass, efail;
  Student_info s;
  s.name = "Smith";
  s.midterm = 93;
  s.final = 91;
  s.homework = {47, 90, 92, 73, 100, 87};
  students.push_back(s);
  epass.push_back(s);

  s.name = "Carpenter";
  s.midterm = 75;
  s.final = 90;
  s.homework = {87, 92, 93, 60, 0, 98};
  students.push_back(s);
  epass.push_back(s);

  s.name = "Jan";
  s.midterm = 55;
  s.final = 20;
  s.homework = {37, 42, 43, 20, 10, 28};
  students.push_back(s);
  efail.push_back(s);

  vector<Student_info> afail;
  afail = extract_fails_partition(students);

  EXPECT_TRUE(students_equal(students, epass));
  EXPECT_TRUE(students_equal(afail, efail));
}

// 8.1.1 Medians of unknown type
TEST(medianGenericFunction, medianOfInt) {
  vector<int> vec_int = {84, 28, 74, 94, 21, 13, 9, 56};
  EXPECT_EQ(median(vec_int), 42);
}

TEST(medianGenericFunction, medianOfDouble) {
  vector<double> vec_double = {84.92, 28.84, 74.2739, 94.01, 21.83, 13.0, 9.73, 56.29};
  EXPECT_EQ(median(vec_double), 42.565);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
