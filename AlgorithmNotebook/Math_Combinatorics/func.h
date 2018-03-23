
/*------------------------------------- Factorial ---------------------------------------------------------------*/
inline double factorial(int x) {
    if (x == 0 || x == 1)
        return 1;

    double res = 1;
    for (int i = 2; i < x + 1; ++i)
        res *= i;
    return res;
}

/*------------------------------------- Combination ---------------------------------------------------------------*/
inline double combination(int n, int k) {
    return factorial(n) / factorial(k) / factorial(n - k);
}

double Com[MAXN][MAXN];
double nCk(int n, int k) {
    assert(n>=k);
    return Com[k][n];
}
void buildCombination(int n, int k) {
    Com[0][0] = 1.0;
    for (int i = 0; i < n + 1; ++i) {
        Com[0][i] = 1.0;
        Com[i][i] = 1.0;
    }

    for (int i = 1; i < k + 1; ++i)
        for (int j = 1; j < n + 1; ++j)
            Com[i][j] = Com[i - 1][j - 1] + Com[i][j - 1];
}

/*------------------------------------- Permutation ---------------------------------------------------------------*/
inline double permutation(int n, int k) {
    return factorial(n) / factorial(n - k);
}

inline double permutation(int n, int k) {
    if (k == 0)
        return 1;
    double res = 1;
    for (int i = n - k + 1; i < n + 1; ++i)
        res *= i;
    return res;
}
