
// https://codejam.withgoogle.com/codejam/contest/8294486/dashboard

const int MAXN = 1000 + 3;

int D,N;
int K[MAXN];
int S[MAXN];
ll readInput() {
    sii(D,N);
    FOR(n,1,N+1) 
        sii(K[n],S[n]);
    return 0;
}

double sol() {
    double t = -1.0;
    // Find the slowest horse
    FOR(n,1,N+1) 
        t = max(t, ((double)D - K[n]) / S[n]);
    return (double)D / t;
}

double solve() {
    return sol();
}
