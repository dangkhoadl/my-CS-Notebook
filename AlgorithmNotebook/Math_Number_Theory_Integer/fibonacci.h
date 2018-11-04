
long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

long long fibo(long long n) {
    if(n <= 1)
        return n;
    if(n == 2)
        return 1;

    int f_1 = 1, f_2 = 0, f = 0;
    for (int i = 2; i <= n; ++i) {
        f = f_1 + f_2;
        f_2 = f_1;
        f_1 = f;
    }
    return f;
}

// F(0) + F(1) + F(2) + ... + F(n) = F(n+2) - 1



/* ----------------------------------------- Calc Fibo log(n) ----------------------------------------- */
const int MOD = 1e9+7;
inline long long add(long long a, long long b) {
    if(a<0)
        a = (a%MOD) + MOD;
    if(b<0)
        b = (b%MOD) + MOD;
    return ((a%MOD) + (b%MOD)) % MOD;
}
inline long long sub(long long a,long long b) {
    if(a<0)
        a = (a%MOD) + MOD;
    if(b<0)
        b = (b%MOD) + MOD;
    return ((a%MOD) - (b%MOD) + MOD) % MOD;
}
inline long long mul(long long a,long long b) {
    if(a<0)
        a = (a%MOD) + MOD;
    if(b<0)
        b = (b%MOD) + MOD;
    return ((a%MOD) * (b%MOD)) % MOD;
}

// O(n^3)
vector<vector<int>> matrixMul(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    assert(A.size() > 0 and B.size() > 0 and A[0].size() == B.size());
    vector<vector<int>> C(A.size(), vector<int>(B[0].size(), 0));
    for(int i=0; i<A.size(); ++i)
        for(int k=0; k<B.size(); ++k)
            for(int j=0; j<B[0].size();++j) {
                C[i][j] = add(C[i][j], mul(A[i][k], B[k][j]));
            }
    return C;
}

// O(n^3 * log(k))
vector<vector<int>> matrixPow(const vector<vector<int>> &A, int k) {
    assert(A.size() > 0 and A.size() == A[0].size() and k >= 0);
    if(k == 0) {
        vector<vector<int>> C(A.size(), vector<int>(A.size(), 0));
        for(int i=0; i < A.size(); ++i)
            C[i][i] = 1;
        return C;
    }
    if(k == 1) {
        return A;
    }

    vector<vector<int>> C = matrixPow(A, k/2);
    C = matrixMul(C, C);
    if(k & 1)
        return matrixMul(C,A);
    return C;
}

// O(log(n))
inline int fibo(int n) {
    return matrixMul(matrixPow({{0,1}, {1,1}}, n), {{0}, {1}})[0][0];
}
