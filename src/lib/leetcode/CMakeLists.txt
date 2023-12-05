add_library(leetcode_lib
  two_sum.cc
  multi_thread.cc
)
install(FILES 
  two_sum.h
  multi_thread.h
  DESTINATION include/leetcode_lib
)

install(TARGETS leetcode_lib DESTINATION lib)

target_link_libraries(leetcode_lib
  PRIVATE -static-libgcc
  PRIVATE -static-libstdc++
)

