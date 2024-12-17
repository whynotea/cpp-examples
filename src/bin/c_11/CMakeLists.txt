add_executable(c_11 main.cc basic_class.cc arrays.cc message.cc fix_msg.cc connection.cc server.cc client.cc scratch.cc)
install(TARGETS c_11 DESTINATION bin)

target_include_directories(c_11 PUBLIC ${PROJECT_BINARY_DIR}
)
target_link_libraries(c_11
  ${BASIC_EXTRA_LINK_LIBS}
  PRIVATE fmt::fmt
  PRIVATE -static-libgcc
  PRIVATE -static-libstdc++
)
