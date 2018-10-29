
// http://codeforces.com/problemset/problem/166/E

const int MAXN = 1e7 + 3;

int n;
ll readInput() {
    si(n);
    return 0;
}

const int MOD = 1e9 + 7;
inline long long mod(long long x, long long m) {
    return ((x%m)+m) % m;
}
inline long long add(long long a, long long b) {
    if(a<0)
        a = (a%MOD) + MOD;
    if(b<0)
        b = (b%MOD) + MOD;
    return ((a%MOD) + (b%MOD)) % MOD;
}
inline long long mul(long long a,long long b) {
    if(a<0)
        a = (a%MOD) + MOD;
    if(b<0)
        b = (b%MOD) + MOD;
    return ((a%MOD) * (b%MOD)) % MOD;
}


/* -------------------------------------------- Solution 1 - O(n)------------------------------------------ */
int dp[MAXN][2];
int sol1() {
    // 0 = A,B,C
    // 1 = D
    dp[1][0] = 1; 
    dp[1][1] = 0;
    FOR(i,2,n+1) {
        dp[i][0] = mod(2*dp[i-1][0] + dp[i-1][1], MOD);
        dp[i][1] = mod(3*dp[i-1][0], MOD);
    }
    return dp[n][1];
}


/* -------------------------------------------- Solution 2 - O(log(n))------------------------------------------ */
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

int sol2() {
    vvi X = { {2, 1},
              {3, 0} };
    vvi dp_0 = { {1},
                 {0} };
    return matrixMul(matrixPow(X, n-1), dp_0)[1][0];
}


/* -------------------------------------------- Print ------------------------------------------ */
void solve(unsigned long long t) {
    printf("Case #%llu: %lld\n", t, sol2());
    
}
