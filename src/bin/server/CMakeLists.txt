add_executable(server main.cc)
install(TARGETS server DESTINATION bin)

target_include_directories(server
  PUBLIC "${PROJECT_SOURCE_DIR}/src/lib"
  PUBLIC ${PROJECT_BINARY_DIR}
)
target_link_libraries(server
  PRIVATE -static-libgcc
  PRIVATE -static-libstdc++
)

