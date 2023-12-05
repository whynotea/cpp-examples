add_executable(leetcode main.cc)
install(TARGETS leetcode DESTINATION bin)

target_include_directories(leetcode
  PUBLIC "${PROJECT_SOURCE_DIR}/src/lib"
  PUBLIC ${PROJECT_BINARY_DIR}
)
target_link_libraries(leetcode
  PRIVATE -static-libgcc
  PRIVATE -static-libstdc++
  leetcode_lib
)

