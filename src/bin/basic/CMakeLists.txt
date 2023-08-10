add_executable(basic main.cc)
install(TARGETS basic DESTINATION bin)

# Optional Adder library
option(USE_ADDER "A basic library example" ON)

if(USE_ADDER)
  list(APPEND BASIC_EXTRA_INCLUDE_DIRS PUBLIC "${PROJECT_SOURCE_DIR}/src/lib/adder")
  list(APPEND BASIC_EXTRA_LINK_LIBS PRIVATE adder)
endif()

target_include_directories(basic
  PUBLIC ${PROJECT_BINARY_DIR}
  ${BASIC_EXTRA_INCLUDE_DIRS}
)
target_link_libraries(basic
  ${BASIC_EXTRA_LINK_LIBS}
  PRIVATE fmt::fmt
  PRIVATE -static-libgcc
  PRIVATE -static-libstdc++
)
