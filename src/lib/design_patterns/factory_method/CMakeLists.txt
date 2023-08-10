add_library(factory_method
  creator.cc
  concrete_creator_1.cc
  concrete_creator_2.cc
  concrete_product_1.cc
  concrete_product_2.cc
)
install(FILES 
  client_code.h
  concrete_creator_1.h
  concrete_creator_2.h
  concrete_product_1.h
  concrete_product_2.h
  creator.h
  product.h
  DESTINATION include/design_patterns/factory_method
)

target_include_directories(factory_method
  PUBLIC ${PROJECT_BINARY_DIR}
)
target_link_libraries(factory_method
  PRIVATE -static-libgcc
  PRIVATE -static-libstdc++
)

