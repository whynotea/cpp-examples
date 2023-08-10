add_executable(
  factory_method_test
  factory_method_test.cc
)

target_include_directories(factory_method_test
  PUBLIC "${PROJECT_SOURCE_DIR}/src/lib"
)
target_link_libraries(
  factory_method_test
  GTest::gtest_main
  design-patterns
)

gtest_discover_tests(factory_method_test)
