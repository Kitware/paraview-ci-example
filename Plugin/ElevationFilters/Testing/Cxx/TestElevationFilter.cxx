
#include <vtkNew.h>
#include <vtkSphereSource.h>
#include <vtkTestUtilities.h>

#include "vtkMyElevationFilter.h"

#include <iostream>

int TestElevationFilter(int argc, char* argv[])
{

    vtkNew<vtkSphereSource> sphere;
    sphere->SetRadius(2.0);
    sphere->SetCenter(1.0, 0., 0.);
    sphere->SetPhiResolution(4);
    sphere->SetThetaResolution(4);

    vtkNew<vtkMyElevationFilter> filter;

    filter->SetInputConnection(sphere->GetOutputPort());
    filter->Update();

    return !vtkTestUtilities::RegressionTest(argc, argv, filter->GetOutput(), "/Data/BaselineData/TestElevationFilter.vtkhdf");
}
