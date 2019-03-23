#include <iostream>

#include "Polynomial.h"

using namespace std;

int main()
{
	Polynomial A;
	cout << "Specify polynomial" << endl;
	cin >> A;
	cout << "A = " << A << endl;

	double x;
	cout << "Specify the value of x:" << endl;
	cin >> x;

	cout << "A(x) = " << A(x) << endl;

	cout << "Indefinite integral of A = " << A.computeIndefiniteIntegral() << endl;

	cout << "Definite integral of A(xlow=0, xhigh=12.0) = " << A.calculateDefiniteIntegral(0, 12.0) << endl;

	return 0;
}