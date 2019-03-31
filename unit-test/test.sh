#!/bin/bash

function test() {
  local fullPath=$(realpath $0)
  local curDir=$(dirname ${fullPath})
  local reportDir='report'

  cd $curDir
  [ -f ./executeTests ] && rm ./executeTests
  cmake CMakeLists.txt
  make

  [ -d $reportDir ] || mkdir -v $reportDir
  ./executeTests
  cd - > /dev/null
}

test
