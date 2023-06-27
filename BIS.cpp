#include <cmath>
#include <iostream>
using namespace std;
double MatrixNorm(double* x, int m);
double mach_eps(void)
{
double eps = 1.0;

	while (1.0 + eps/ 2.0 > 1.0)
	{
		eps /= 2.0;
	}
	return eps;
}
void MetodVrascheniy(double* A, int n) //To be applied to symmetric matrices only
{
    double eps = mach_eps();
    double cost, sint, norm;
    double t;
    for(int r = 0; r < n-2; r++)
    {
        for(int i = r+2; i < n; i++)
        {
                    norm = sqrt(A[i*n+r]*A[i*n+r] + A[(r+1)*n+r]*A[(r+1)*n+r]);
                    if(norm < eps)
                    {
                 
                        continue;
                    }
                    else
                    {
                        
                        cost = A[(r+1)*n+r]/norm;
                        sint = -A[i*n+r]/norm;

                        for(int j = 0; j < n; j++)
                        {
                            t = A[(r+1)*n+j];
                            A[(r+1)*n+j] = A[(r+1)*n+j]*cost - A[i*n + j]*sint;
                            A[i*n + j] = t*sint + A[i*n+j]*cost;
                        }
                        for(int j = 0; j < n; j++)
                        {
                            t = A[j*n + (r+1)];
                            A[j*n + (r+1)] = A[j*n + (r+1)]*cost - sint*A[j*n + i];
                            A[j*n+ i] = t*sint + A[j*n+i]*cost;
                        }


                    }
            }
        }
}


int ChisloPeremenZnakaLU(double* A, int n, double accuracy, double x)
{


    for(int i = 0; i < n; i++)
        A[i*n + i] = A[i*n + i] - x;

    double L1 = 1, L2;
    double eps = mach_eps();
    int counter = 0;
    L2 = A[0];
    if(sqrt(L2*L2) < 10*eps)
     {
         L2 = L2 + min(eps*100, accuracy);
     }
    else if(L2 < -eps)
        counter++;
    for(int i = 1; i < n; i++)
    {

        L1 = L2;
        L2 = A[i*n + i] - A[i*n + i-1]*A[(i-1)*n+i]/L1;
        if(sqrt(L2*L2) < 10*eps)
            {
                    L2 += min(eps*100, accuracy);
            }
        else if(L2 < -eps)
            counter++;
    }
        for(int i = 0; i < n; i++)
            A[i*n + i] = A[i*n + i] + x;
	
    return counter;

}

void BIS(double b, double a, int n , double accuracy, double* massive, double* Row)
{		
double c;
MetodVrascheniy(massive, n);
for(int k = 0; k < n; )
        { 
            while(b - a > accuracy)
            { 
                c = (b+a)/2.0; 
                if(ChisloPeremenZnakaLU(massive, n, accuracy, c) < k+1)
                    a = c;
                else
                    b = c;

		
            }
            for(int i = k; i < k + ChisloPeremenZnakaLU(massive, n, accuracy, b) - ChisloPeremenZnakaLU(massive, n, accuracy, a); i++) 
                Row[i] = c;
            k = k + ChisloPeremenZnakaLU(massive, n, accuracy, b) - ChisloPeremenZnakaLU(massive, n, accuracy, a);
            a = c + min(accuracy, 1e-10);
            b = MatrixNorm(massive, n);

        }
}

