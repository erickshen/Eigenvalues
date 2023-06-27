#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include "Definitions.h"
using namespace std;
int main(int argc, char* argv[])
{
std::cout.setf(std::ios::scientific);
if(argc < 5)
	{ cout << "Wrong number of arguments"; return -1;}
        clock_t time;
        int result;
        char* Filename;
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
        double accuracy = atof(argv[3]);
	int k = atoi(argv[4]);
	double eps = mach_eps();
		if(m > n || m < 0 || n <= 0)
		{cout << "Incorrect arguments" << endl; return -1;}
		if(accuracy < 10*eps)
		{cout << "too accurate" << endl; return -1;}

        double* Row = new double[n];
        double* massive = new double[n*n];
	if(k == 0)
		Filename = argv[5];

    if(k == 0)
    {
    int a = MatrixInputFile(n*n, massive, Filename);
        if(a == -1)
            {cout << "Incorrect arguments" << endl;
		return -1;
    }}

    if(k > 0 && k <5)
        for(int i = 0; i <= n*n-1; i++)
             massive[i] = FunctionInput(k, n, i/n, i%n);
	if(k < 0 || k > 4)
		{ cout << "Wrong arguments" << endl; return -1;}
	cout << "The matrix is of the form: " << endl;

	MatrixOutput(m, m, n,massive);
	//if(check(massive, n) == -1)
		//{ 
		//cout << "\nthe matrix is not symmetric" << endl;
		//return -1;
		//}

       time = clock();
	BIS(MatrixNorm(massive, n), -MatrixNorm(massive, n), n, accuracy, massive, Row);
	time = clock()-time;
	double time_taken = (double)time/100000.0;

cout << "Eigenvalues are: " << endl;
MatrixOutput(1, m, n, Row);

cout << "\n" << "Time taken: " << time_taken << endl;
cout << "First error norm equals to " << ErrorNormFirst(massive, Row, n) << endl; 
cout << "Second error norm equals to " << ErrorNormSecond(massive, Row, n) << endl; 




	

    return 0;
}






