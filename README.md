# accelerated-cpp
persional practice repo for study CPP based on book Accelerated C++

## Unit Test
### Install Unit Test Environment (Google Test Framework)
    $ sudo apt install libgtest-dev
    $ sudo apt install cmake
    $ g++ -v &> /dev/null || sudo apt install g++
    $ cd /usr/src/gtest
    $ sudo cmake CMakeLists.txt
    $ sudo make
    $ sudo cp -v *.a /usr/lib

### Run UT Case
    $ ./unit-test/test.sh
