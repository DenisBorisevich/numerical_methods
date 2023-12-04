#include "functions.h"

using namespace std;

double simpson_method(const double& A, const double& B, const unsigned long& n) {
	double h = (B - A) / n; //шаг
	unsigned int m = n / 2;
	double f1 = 0;
	double f2 = 0;
	for (int k = 1; k < m; ++k) {
		f1 += function(A + h * (k * 2 - 1));
		f2 += function(A + h * k * 2);
	}
	f1 += function(A + h * (m * 2 - 1));
	return h * (function(A) + 4 * f1 + 2 * f2 + function(B)) / 3;
}

double calculate_simpson(const double& A, const double& B, const double& epsilon) {
	long n = 10;
	double inter1 = 0;
	double inter2 = simpson_method(A, B, n);
	int i = 1;
	while (abs(inter1 - inter2) > 3 * epsilon) {
		n *= 2;
		inter1 = inter2;
		inter2 = simpson_method(A, B, n);
		i++;
	}
	cout << i << "\n";
	return inter2;
}