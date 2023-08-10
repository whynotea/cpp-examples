add_executable(basic_gui main.cc)
install(TARGETS basic_gui DESTINATION bin)

target_include_directories(basic_gui
  PUBLIC ${PROJECT_SOURCE_DIR}/external/glfw/include
)
target_link_libraries(basic_gui
  PRIVATE glfw
  PRIVATE GL
  PRIVATE GLEW
  PRIVATE GLU
  PRIVATE -static-libgcc
  PRIVATE -static-libstdc++
)
