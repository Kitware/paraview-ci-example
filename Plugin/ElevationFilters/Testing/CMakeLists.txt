if (ParaView_VERSION VERSION_GREATER_EQUAL "6.2.0")
  # Required, sets . as the input directory, it is passed as an argv argument during the VTK tests.
  set(_vtk_build_TEST_OUTPUT_DATA_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
  vtk_module_test_data(
    Data/BaselineData/TestElevationFilter.vtkhdf
  )
  add_subdirectory(Cxx)
endif ()
