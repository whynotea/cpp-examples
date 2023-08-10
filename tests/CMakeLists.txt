find_package(GTest CONFIG REQUIRED)
#target_link_libraries(GTest::gtest INTERFACE gtest_main)

add_executable(
  hello_test
  hello_test.cc
)

#add_executable(design_patterns_test design_patterns_test.cc)
#
target_link_libraries(
  hello_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)

add_test(NAME script_test
  COMMAND "${CMAKE_CURRENT_LIST_DIR}/script_test.sh"
  WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}"
)
