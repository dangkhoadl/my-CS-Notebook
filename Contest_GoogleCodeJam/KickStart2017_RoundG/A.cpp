
// https://codejam.withgoogle.com/codejam/contest/3254486/dashboard#s=p0&a=0

const int MAXN = 1e5 + 3;

int A,N,P;
ll readInput() {
    sii(A,N); si(P);
    
    return 0;
}

inline long long power(long long a, long long n, long long MOD) {
    assert(n>0);
    assert(a>=0);
    if(a == 0)
        return 0;
    if(n == 0)
        return 1;
    if(n == 1)
        return a%MOD;

    long long pow_half = power(a, n/2, MOD);
    long long pow_half_sq = (pow_half  * pow_half) % MOD;
    if(n & 1)
        return (pow_half_sq * a) % MOD;
    return pow_half_sq;
}

int sol() {
    if(N == 0)
        return 0;
    if(N == 1)
        return A%P;

    int A_ = A%P;
    FOR(n,2,N+1) 
        A_ = power(A_,n,P);
    return A_;
}

void solve(unsigned long long t) {
    printf("Case #%llu: %lld\n", t, sol());
}
