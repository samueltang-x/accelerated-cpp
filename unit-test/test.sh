[ -f ./executeTests ] && rm -v ./executeTests
cmake CMakeLists.txt
make
./executeTests
