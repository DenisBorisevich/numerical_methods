#include "functions.h"




double double_simpson_method(const double& A, const double& B, const double& C, const double& D, const unsigned long& n) {
	double hx = (B - A) / (2 * n);
	double hy = (D - C) / (2 * n);

	double result = 0.0;

	for (int i = 0; i <= n - 1; ++i) {
		for (int j = 0; j <= n - 1; ++j) {
			result += function(A + (double(i) * 2) * hx, C + (double(j) * 2) * hy);
			result += 4 * function(A + (double(i) * 2 + 1) * hx, C + (double(j) * 2) * hy);
			result += function(A + (double(i) * 2 + 2) * hx, C + (double(j) * 2) * hy);
			result += 4 * function(A + (double(i) * 2) * hx, C + (double(j) * 2 + 1) * hy);
			result += 16 * function(A + (double(i) * 2 + 1) * hx, C + (double(j) * 2 + 1) * hy);
			result += 4 * function(A + (double(i) * 2 + 2) * hx, C + (double(j) * 2 + 1) * hy);
			result += function(A + (double(i) * 2) * hx, C + (double(j) * 2 + 2) * hy);
			result += 4 * function(A + (double(i) * 2 + 1) * hx, C + (double(j) * 2 + 2) * hy);
			result += function(A + (double(i) * 2 + 2) * hx, C + (double(j) * 2 + 2) * hy);
		}
	}
	return hx * hy * result / 9;
}

double calculate_double_simpson(const double& A, const double& B, const double& C, const double& D, const double& epsilon) {
	long n = 10;
	double inter1 = 0;
	double inter2 = double_simpson_method(A, B, C, D, n);

	while (abs(inter1 - inter2) > 15 * epsilon) {
		n *= 2;
		inter1 = inter2;
		inter2 = double_simpson_method(A, B, C, D, n);
	}

	return inter2;
}