cmake_minimum_required(VERSION 3.27.0)
set(CMAKE_TOOLCHAIN_FILE /usr/local/vcpkg/scripts/buildsystems/vcpkg.cmake)

project(cpp-examples VERSION 0.0.1)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CTest)
enable_testing()

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
  option(GIT_SUBMODULE "Check submodules during build" ON)
  if(GIT_SUBMODULE)
    message(STATUS "Submodule update")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE GIT_SUBMOD_RESULT)
    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
      message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
    endif()
  endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
  message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

find_package(GLEW REQUIRED)
find_package(fmt CONFIG REQUIRED)

configure_file(src/config/version.h.in version.h)

# Optional Adder library
option(USE_ADDER "A basic library example" ON)

if(USE_ADDER)
  add_subdirectory(src/lib/adder)
  list(APPEND BASIC_EXTRA_INCLUDE_DIRS PUBLIC "src/lib/adder")
  list(APPEND BASIC_EXTRA_LINK_LIBS PRIVATE adder)
endif()

add_subdirectory(src/bin/basic)
add_subdirectory(src/bin/basic-gui)
add_subdirectory(external/glfw)

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

target_include_directories(basic-gui
  PUBLIC external/glfw/include
)
target_link_libraries(basic-gui
  PRIVATE glfw
  PRIVATE GL
  PRIVATE GLEW
  PRIVATE GLU
  PRIVATE -static-libgcc
  PRIVATE -static-libstdc++
)

install(FILES "${PROJECT_BINARY_DIR}/version.h" DESTINATION include)

set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE)
include(CPack)
