#include "Polynomial.h"

Polynomial::Polynomial() 
{

}

// binary operator* to multiply two polynomials
// arguments are read-only, signified by const
// the operator* returns a fresh polynomial with degree i+j
Polynomial Polynomial::operator*(const Polynomial& aRight) const
{
	Polynomial result;

	return result;
}

// input operator for polynomials
std::istream& operator>>(std::istream& aIStream, Polynomial& aObject)
{
	char line[256];
	char *ptr;

	aIStream.getline(line, 256);
	sscanf(line, "%d", &aObject.fDegree);

	aIStream.getline(line, 256);
	ptr = strtok(line, " ");
	int counter = 0;
	while (ptr != NULL && counter < MAX_DEGREE+1)
	{
		sscanf(ptr, "%lf", &aObject.fCoeffs[counter]);
		counter++;
		ptr = strtok(NULL, " ");
	}

	return aIStream;
}

// output operator for polynomials
std::ostream& operator<<(std::ostream& aOStream, const Polynomial& aObject)
{
	return aOStream;
}