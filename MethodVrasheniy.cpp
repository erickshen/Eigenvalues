#include <cmath>
void MetodVrascheniy(double* A, int n)
{
    double eps = mach_eps();
    double cost, sint, norm;
    double t;
    for(int r = 0; r < n-2; r++)
    {
        for(int i = r+2; i < n; i++)
        {
                    norm = sqrt(A[i*n+r]*A[i*n+r] + A[(r+1)*n+r]*A[(r+1)*n+r]);
                    cout << norm << endl;
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