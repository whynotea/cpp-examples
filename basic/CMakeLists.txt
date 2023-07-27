cmake_minimum_required(VERSION 3.27.0)
project(basic VERSION 0.0.1)

include(CTest)
enable_testing()

add_executable(basic main.cpp)
install(TARGETS basic DESTINATION bin)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
