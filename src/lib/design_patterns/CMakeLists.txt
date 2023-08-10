add_subdirectory(factory_method)

add_library(design-patterns STATIC CMakeLists.txt)
install(TARGETS design-patterns DESTINATION lib)

target_link_libraries(design-patterns PUBLIC factory_method)
