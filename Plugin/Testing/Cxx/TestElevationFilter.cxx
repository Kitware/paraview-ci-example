#include <vtkMyElevationFilter.h>

#include <vtkNew.h>
#include <vtkSphere.h>
#include <vtkTestUtilities.h>



int TestRegression(int argc, char** argv, std::string& baseline)
{
    vtkNew<vtkSphere> sphere;
    vtkNew<vtkMyElevationFilter> filter;

    filter->setInputData(sphere);
    filter->Update();

    return vtkTestUtilities::RegressionTest(argc, argv, filter->GetOutput(), baseline);

}


int TestElevationFilter(int argc, char** argv)
{
    return TestRegression(argc, argv, "Data/example.vtkhdf") ? EXIT_SUCCESS : EXIT_FAILURE;
}
