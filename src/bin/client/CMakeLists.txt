add_executable(client main.cc)
install(TARGETS client DESTINATION bin)

target_include_directories(client
  PUBLIC "${PROJECT_SOURCE_DIR}/src/lib"
  PUBLIC ${PROJECT_BINARY_DIR}
)
target_link_libraries(client
  PRIVATE -static-libgcc
  PRIVATE -static-libstdc++
)

