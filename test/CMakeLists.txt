enable_testing()

add_executable(data_handling_test data_handling.cpp $<TARGET_OBJECTS:connected_components_labeling>)
add_executable(algorithms_test algorithms.cpp $<TARGET_OBJECTS:connected_components_labeling>)

link_libraries(data_handling_test connected_component_labeling ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} )
link_libraries(algorithms_test connected_component_labeling ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} )

add_test(algorithms algorithms_test)
add_test(data_handling data_handling_test)
