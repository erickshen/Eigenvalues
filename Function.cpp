#include <iostream>
#include <cmath>
double FunctionInput(int k, int n, int i, int j)
{
    if(k == 1)
         return (double) (n - std::max(i+1, j+1) + 1);
    else if(k == 2)
        {
		if(i==j)
			return 2;
		else if(i-j == 1 || i - j == -1)
			return -1;
		else return 0;
	}
		
    else if(k == 3)
        {
	if(i == j && j < n-1 && i < n-1)
		return 1;
	else if(j == n-1)
		return i+1;
	else if(i == n-1)
		return j+1;
	else return 0;

	}
    else if(k == 4)
        return (double) 1.0/(i+j+1);

    else
        return -1;

}

