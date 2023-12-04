#pragma once
#include <iostream>
#include <vector>



double function(const double& x);

double function(const double& x, const double& y);



double trapezoid_method(const double& A, const double& B, const unsigned long& n);

double calculate_trapezoid(const double& A, const double& B, const double& epsilon);


double simpson_method(const double& A, const double& B, const unsigned long& n);

double calculate_simpson(const double& A, const double& B, const double& epsilon);


double double_simpson_method(const double& A, const double& B, const double& C, const double& D, const unsigned long& n);

double calculate_double_simpson(const double& A, const double& B, const double& C, const double& D, const double& epsilon);
