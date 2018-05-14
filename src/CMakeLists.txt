add_library(connected_components_labeling OBJECT data_handling.cpp one_pass.cpp two_pass.cpp)

add_executable(adjacent_cells_challenge $<TARGET_OBJECTS:connected_components_labeling>
        main.cpp)
target_compile_features(adjacent_cells_challenge PUBLIC cxx_std_11)
target_link_libraries(adjacent_cells_challenge Boost::program_options)
