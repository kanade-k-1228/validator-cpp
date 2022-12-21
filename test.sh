g++ -std=c++2a test.cpp validator.cpp -o test
./test [0:4,5,8,13] 0
./test [0:4,5,8,13] 1
./test [0:4,5,8,13] 2
./test [0:4,5,8,13] 3
./test [0:4,5,8,13] 4
./test [0:4,5,8,13] 5
./test [0:4,5,8,13] 6
./test [0:4,5,8,13] 7
./test [0:4,5,8,13] 8
./test [0:4,5,8,13] 9
./test [0=false,1=true] false
./test [0=false,1=true] true
./test [0=false,1=true] 0
./test [0=false,1=true] 1
./test "[ 0 : 2 , 0 = null , 0x10 ]" 16
./test "[ 0 : 2 , 0 = null , 0x10 ]" 0x10
./test "[ 0 : 2 , 0 = null , 0x10 ]" null
