if (TARGET ParaView::paraview)
  # Note that there is an alternative baseline for ParaView 5.14 and above
  set (TestXML_USES_DIRECT_DATA ON)
  paraview_add_client_tests(
    LOAD_PLUGIN ElevationFilter
    PLUGIN_PATH $<TARGET_FILE_DIR:ElevationFilter>
    BASELINE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Data/Baseline
    TEST_SCRIPTS TestXML.xml)
endif()

if (PARAVIEW_USE_PYTHON)
  file(GENERATE
       OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/TestPython.py
       INPUT ${CMAKE_CURRENT_SOURCE_DIR}/TestPython.py.in)
  set(_vtk_build_TEST_FILE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
  paraview_add_test_python(
    NO_RT DIRECT_DATA
    TestPython.py)
endif()

set(_vtk_build_TEST_OUTPUT_DATA_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

if (NOT vtk_testing_cxx_disabled AND NOT ParaView_VERSION VERSION_LESS "6.2.0")
  set(_vtk_build_test "ElevationFilters")

  vtk_module_test_data(
    ${CMAKE_CURRENT_SOURCE_DIR}/Data/BaselineData/TestElevationFilterCxx.vtkhdf
  )
  add_subdirectory(Cxx)
endif ()
