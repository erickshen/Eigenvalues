#include <iostream> 
#include <cmath>

double ErrorNormFirst(double* massive, double* Row, int n)
{
double trace = 0;
double eigenvaluessum = 0;
for(int i = 0; i < n; i++)
	{
		eigenvaluessum += Row[i];
		trace += massive[i*n +i];
	}

return sqrt((eigenvaluessum-trace)*(eigenvaluessum-trace));
}
double ErrorNormSecond(double* massive, double* Row, int n)
{
	double MatrixNorm = 0;
	double Eigenvaluesnorm = 0;
	for(int i = 0; i < n*n; i++)
		MatrixNorm += massive[i]*massive[i];
	for(int i = 0; i < n; i++)
		Eigenvaluesnorm += Row[i]*Row[i];

	MatrixNorm = sqrt(MatrixNorm);
	Eigenvaluesnorm = sqrt(Eigenvaluesnorm);
return sqrt((MatrixNorm-Eigenvaluesnorm)*(MatrixNorm-Eigenvaluesnorm));
}
