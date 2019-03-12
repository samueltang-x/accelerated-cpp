#!/bin/bash

function test() {
  local fullPath=$(realpath $0)
  local curDir=$(dirname ${fullPath})

  cd $curDir
  [ -f ./executeTests ] && rm ./executeTests
  cmake CMakeLists.txt
  make
  ./executeTests
  cd - > /dev/null
}

test
