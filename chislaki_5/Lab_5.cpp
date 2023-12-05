#include "functions.h"
#include <iostream>
#include <windows.h>

using namespace std;

const double& epsilon = 1e-5;

double function(const double& x)
{
	return 3x / sqrt(1 + x^3);
}

int main() {
	setlocale(LC_ALL, "rus");
	cout.precision(10);


	cout << "Метод трапеций " << endl;
	cout << calculate_trapezoid(0, 1.075, epsilon) << endl;
	cout << endl;
	
	cout << "Метод Симпсона " << endl;
	cout << calculate_simpson(0, 1.075, epsilon) << endl;
	cout << endl;
	
}

