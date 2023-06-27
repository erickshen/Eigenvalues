double MatrixNorm(double* x, int m);
void MatrixOutput(int l, int m, int n, double* x);
int MatrixInputFile(int m, double* x, char* t);
void BIS(double b, double a, int n , double accuracy, double* massive, double* Row);
double ErrorNormFirst(double* massive, double* Row, int n);
double ErrorNormSecond(double* massive, double* Row, int n);
double FunctionInput(int k, int n, int i, int j);
double mach_eps(void);
//int check(double* massive, int n);
