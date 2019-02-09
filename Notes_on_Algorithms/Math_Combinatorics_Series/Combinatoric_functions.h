
/*--------------------- Factorial ------------------------*/
double F[MAXN];
void buildFactorial(int n) {
    F[0] = 1.0;
    double res = 1.0;
    for(int i = 1; i <= n; ++i)
        F[i] = F[i-1]*i;
}
inline double factorial(int x) {
    assert(x>=0);
    return F[x];
}

/*--------------------------- Permutation --------------------*/
inline double nPk(int n, int k) {
    assert(k>=0);
    assert(n>=k);
    return F[n] / F[n-k];
}

inline double nPk(int n, int k) {
    assert(k>=0);
    assert(n>=k);
    if (k == 0)
        return 1;
    double res = 1.0;
    for (int i = n - k + 1; i <= n; ++i)
        res *= (double)i;
    return res;
}
/*-------------------------- Combination ------------------*/
double Com[MAXN][MAXN];
void buildCombination(int n) {
    Com[0][0] = 1.0;
    for (int i = 0; i < n + 1; ++i) {
        Com[0][i] = 1.0;
        Com[i][i] = 1.0;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < n + 1; ++j)
            Com[i][j] = Com[i - 1][j - 1] + Com[i][j - 1];
}
double nCk(int n, int k) {
    assert(k>=0);
    assert(n>=k);
    return Com[k][n];
}
