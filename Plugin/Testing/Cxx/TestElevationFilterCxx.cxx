
#include <vtkNew.h>
#include <vtkSphereSource.h>
#include <vtkTestUtilities.h>

#include "vtkMyElevationFilter.h"

#include <iostream>

int TestRegression(int argc, char** argv, const std::string& baseline)
{
    vtkNew<vtkSphereSource> sphere;
    sphere->SetRadius(2.0);
    sphere->SetCenter(1.0, 0., 0.);

    vtkNew<vtkMyElevationFilter> filter;

    filter->SetInputConnection(sphere->GetOutputPort());
    filter->Update();

    return vtkTestUtilities::RegressionTest(argc, argv, filter->GetOutput(), baseline);
}


int TestElevationFilterCxx(int argc, char* argv[])
{
    for(int i = 0; i < argc; i++){
        std::cout << "Arg #"<< i << ": \"" << argv[i] << '"' << std::endl;
    }

    return TestRegression(argc, argv, "/Data/BaselineData/TestElevationFilterCxx.vtkhdf") ? EXIT_SUCCESS : EXIT_FAILURE;
}
