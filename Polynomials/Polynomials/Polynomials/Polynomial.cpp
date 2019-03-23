#include "Polynomial.h"

Polynomial::Polynomial() 
{
	fDegree = 0;
	for (int i = 0; i < MAX_DEGREE; i++)
	{
		fCoeffs[i] = 0.0;
	}
}

// binary operator* to multiply two polynomials
// arguments are read-only, signified by const
// the operator* returns a fresh polynomial with degree i+j
Polynomial Polynomial::operator*(const Polynomial& aRight) const
{
	Polynomial Result;

	Result.fDegree = fDegree + aRight.fDegree;

	for (int i = 0; i <= fDegree; i++) 
	{
		for (int j = 0; i <= aRight.fDegree; j++)
		{
			Result.fCoeffs[i + j] += fCoeffs[i] * aRight.fCoeffs[j];
		}
	}

	return Result;
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
	bool AddPlus = false;
	for (int i = 0; i <= aObject.fDegree; i++)
	{
		if (aObject.fCoeffs[i] != 0)
		{
			if (AddPlus == true)
			{
				aOStream << " + ";
			}
			aOStream << aObject.fCoeffs[i] << "x^" << i;
			AddPlus = true;
		}
	}

	return aOStream;
}