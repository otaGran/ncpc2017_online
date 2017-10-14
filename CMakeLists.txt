cmake_minimum_required(VERSION 3.8)
project(ncpc2017_online)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES  "Problem_A.cpp"  Problem_B.cpp Problem_F.cpp)
add_executable(ncpc2017_online ${SOURCE_FILES})
add_executable(Problem_A "Problem_A.cpp")
add_executable(Problem_B Problem_B.cpp)