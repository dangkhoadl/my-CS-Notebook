
// https://codejam.withgoogle.com/codejam/contest/7254486/dashboard#s=p2&a=2

const int MAXN = 100 + 3;
const int MAXM = MAXN*(MAXN-1)/2 + 3;
const int MAXP = 200 + 3; // large P: 1e9

int N,M,P;
int U[MAXM], V[MAXM], D[MAXM];
ll readInput() {
    siii(N,M,P);
    FOR(m,1,M+1) {
        siii(U[m],V[m],D[m]);
    }
    return 0;
}

int S[MAXN];
int dist[MAXN][MAXN];
void floydWarshall() {
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j) {
                if(i == j)
                    dist[i][j] = 0;
                else if(dist[i][k] >= inf || dist[k][j] >= inf)
                    dist[i][j] = min(dist[i][j], inf);
                else
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
}


/********************** Naive O(N*N*P) *************************************/
double dp[MAXP][MAXN];
double naive() {
    ms(dp, 0);
    FOR(k,1,P+1) FOR(l,1,N+1){
        dp[k][l] = S[l];
        FOR(i,1,N+1) if(i!=l)
            dp[k][l] += dp[k-1][i];
        dp[k][l] /= (N-1);
    }
    return dp[P][1];
}

/********************** matrix expo O(N*N*log(P)) *************************************/
vector<vector<double>> matrixMul(const vector<vector<double>> &A, const vector<vector<double>> &B) {
    assert(A.size() > 0 and B.size() > 0 and A[0].size() == B.size());
    vector<vector<double>> C(A.size(), vector<double>(B[0].size(), 0));
    for(int i=0; i<A.size(); ++i)
        for(int k=0; k<B.size(); ++k)
            for(int j=0; j<B[0].size();++j) {
                C[i][j] += (A[i][k] * B[k][j]); 
            }
    return C;
}
vector<vector<double>> matrixPow(const vector<vector<double>> &A, int k) {
    assert(A.size() > 0 and A.size() == A[0].size() and k >= 0);
    if(k == 0) {
        vector<vector<double>> C(A.size(), vector<double>(A.size(), 0));
        for(int i=0; i < A.size(); ++i)
            C[i][i] = 1;
        return C;
    }
    if(k == 1) {
        return A;
    }

    vector<vector<double>> C = matrixPow(A, k/2);
    C = matrixMul(C, C);
    if(k & 1)
        return matrixMul(C,A);
    return C;
}
double fast() {
    // F0
    vector<vector<double>> F0(N+1, vector<double>(1, 0.0));
    F0[0][0] = 1.0;

    // A
    vector<vector<double>> A(N+1, vector<double>(N+1, 0.0));
    A[0][0] = 1.0;
    FOR(n,1,N+1)
        A[n][0] = (double)S[n] / (N-1);
    FOR(n,1,N+1) FOR(i,1,N+1) {
        if(i == n)
            A[n][i] = 0.0;
        else
            A[n][i] = 1.0/(N-1);
    }

    // Fk = (A^P) * F0
    vector<vector<double>> A_p = matrixPow(A, P);
    vector<vector<double>> Fk = matrixMul(A_p, F0);
    return Fk[1][0];
}


double sol() {
    ms(dist, 0x7f);

    // Build map
    FOR(m,1,M+1)
        dist[U[m]][V[m]] = dist[V[m]][U[m]] = D[m];

    // all-pair shortest distances
    floydWarshall();

    // sum-distances
    ms(S, 0);
    FOR(n,1,N+1) FOR(i,1,N+1)
        S[n] += dist[n][i];

    // Solve
    return fast();
}


void solve(unsigned long long t) {
    printf("Case #%llu: %.6f\n", t, sol());
}
