cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeTests
  tests/test-tool-files.cpp
  tools/files.cpp
  ../ch5-using-sequential-containers-and-analyzing-string/ch5.5-separating-students-using-iterators-list/Student_info.h
  ../ch5-using-sequential-containers-and-analyzing-string/ch5.5-separating-students-using-iterators-list/grade.cpp
  ../ch5-using-sequential-containers-and-analyzing-string/ch5.5-separating-students-using-iterators-list/median.cpp
  ../ch8-writing-generic-functions/src/median-of-unknown-type.cpp
  ../ch9-defining-new-types/9.3-protection/Student_info.cpp
  ../ch10-managing-memory-and-low-level-data-structures/letter-grade.cpp
  ../ch11-defining-abstract-data-types/test-Vec.cpp
  ../ch6-using-library-algorithms/6.2-comparing-grading-schemas/read.cpp
  ../ch13-using-inheritance-and-dynamic-binding/Core.cpp
  ../ch13-using-inheritance-and-dynamic-binding/Grad.cpp
  tests/test-Str.cpp
  tests/test-Core-Grad.cpp
  unit-test.cpp
  )
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)
