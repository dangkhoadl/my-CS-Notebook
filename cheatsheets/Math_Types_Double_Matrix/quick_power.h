
// Calc O(logn): x^n 


/* --------------------- Recursive --------------------- */
bool areSame(double a, double b) {
    return fabs(a - b) < numeric_limits<double>::epsilon();
}
double qPow(double x, long long n) {
    // Base cases
    if(n == 0)
        return 1.0;
    if(areSame(x,0.0))
        return 0.0;
    if(areSame(x,1.0))
        return x;
    if(n == 1)
        return x;

    // Case n<0
    if(n < 0)
        return qPow(1.0/x, -n);

    // Divide and Conquer
    double half = qPow(x, n/2);
    if(n%2 == 0)
        return half*half;
    return x*half*half;
}


/* --------------------- Iterative ------------------ */
bool areSame(double a, double b) {
    return fabs(a - b) < numeric_limits<double>::epsilon();
}
double qPow(double x, long long n) {
    // Case n<0
    if(n < 0) {
        n = -n;
        x = 1.0 / x;
    }

    // Base cases
    if(n == 0)
        return 1.0;
    if(areSame(x,0.0))
        return 0.0;
    if(areSame(x,1.0))
        return x;
    if(n == 1)
        return x;

    // Divide and Conquer
    double res = 1.0;
    while(n > 0) {
        if(n%2 == 1)
            res *= x;
        x = (x*x);
        n /= 2;
    }
    return res;
}
