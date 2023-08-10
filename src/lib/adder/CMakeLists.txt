add_library(adder adder.cc)

install(TARGETS adder DESTINATION lib)
install(FILES adder.h DESTINATION include/adder)
