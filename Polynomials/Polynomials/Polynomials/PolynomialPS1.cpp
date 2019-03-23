#include "Polynomial.h"

double Polynomial::operator()(double aX) const
{
	double Result = 0.0;

	for (int i = 0; i <= fDegree; i++)
	{
		double Term;
		Term = fCoeffs[i] * pow(aX, i);
		Result = Result + Term;
	}

	return Result;
}

Polynomial Polynomial::computeIndefiniteIntegral() const
{
	Polynomial Result;

	Result.fDegree = fDegree + 1;
	Result.fCoeffs[0] = 0; //Sets the first coefficient value to 0 
	for (int i = 0; i <= fDegree; i++)
	{
		Result.fCoeffs[i+1] = fCoeffs[i] / (i+1);
	}

	return Result;
}

double Polynomial::calculateDefiniteIntegral(double aXLow, double aXHigh) const
{
	double Result = 0.0;

	Polynomial integral = computeIndefiniteIntegral();
	return integral(aXHigh) - integral(aXLow);
}