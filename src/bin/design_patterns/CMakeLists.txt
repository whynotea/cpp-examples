add_executable(design_patterns main.cc)
install(TARGETS design_patterns DESTINATION bin)

target_include_directories(design_patterns
  PUBLIC "${PROJECT_SOURCE_DIR}/src/lib"
  PUBLIC ${PROJECT_BINARY_DIR}
)
target_link_libraries(design_patterns
  PRIVATE -static-libgcc
  PRIVATE -static-libstdc++
  design-patterns
)

