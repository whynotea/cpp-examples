add_executable(containers main.cc)
install(TARGETS containers DESTINATION bin)

target_include_directories(containers
  PUBLIC "${PROJECT_SOURCE_DIR}/src/lib"
  PUBLIC ${PROJECT_BINARY_DIR}
)
target_link_libraries(containers
  PRIVATE -static-libgcc
  PRIVATE -static-libstdc++
)

