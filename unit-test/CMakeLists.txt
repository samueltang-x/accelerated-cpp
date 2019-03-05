cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeTests
  unit-test.cpp
  ../ch5-using-sequential-containers-and-analyzing-string/ch5.5-separating-students-using-iterators-list/Student_info.h
  ../ch5-using-sequential-containers-and-analyzing-string/ch5.5-separating-students-using-iterators-list/grade.cpp
  ../ch5-using-sequential-containers-and-analyzing-string/ch5.5-separating-students-using-iterators-list/median.cpp
  ../ch8-writing-generic-functions/src/median-of-unknown-type.cpp
  ../ch10-managing-memory-and-low-level-data-structures/letter-grade.cpp
  )
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)
