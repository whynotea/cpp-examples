add_executable(design_patterns main.cc 
  factory_method/creator.cc
  factory_method/concrete_creator_1.cc
  factory_method/concrete_creator_2.cc
  factory_method/concrete_product_1.cc
  factory_method/concrete_product_2.cc
)
install(TARGETS design_patterns DESTINATION bin)
