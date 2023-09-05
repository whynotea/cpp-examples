add_executable(concepts main.cc)
install(TARGETS concepts DESTINATION bin)

target_include_directories(basic
  PUBLIC ${PROJECT_BINARY_DIR}
)
target_link_libraries(basic
  PRIVATE -static-libgcc
  PRIVATE -static-libstdc++
)
