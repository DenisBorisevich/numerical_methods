#include "functions.h"

using namespace std;


double trapezoid_method(const double& A, const double& B, const unsigned long& n) {
	double h = (B - A) / n; //шаг
	double f = 0;
	for (int i = 1; i < n - 1; ++i) {
		f += function(A + h * i);
	}

	return h * (function(A) + 2 * f + function(B)) / 2;
}

double calculate_trapezoid(const double& A, const double& B, const double& epsilon) {
	long n = 10;
	double intr1 = 0;
	double intr2 = trapezoid_method( A, B, n);
	int i = 1;
	while (abs(intr1 - intr2) > 3 * epsilon) {
		n *= 2;
		intr1 = intr2;
		intr2 = trapezoid_method( A, B, n);
		i++;
	}
	cout << i << "\n";

	return intr2;
}