
// https://codejam.withgoogle.com/codejam/contest/11304486/dashboard#s=p0

const int MAXN = 1e4 + 3;
int N;
int K[MAXN];
ll readInput() {
    si(N);
    FOR(n,1,N+1)
        si(K[n]);
    return 0;
}

const int MOD = 1e9 + 7;
inline long long add(long long a, long long b) {
    return ((a%MOD) + (b%MOD)) % MOD;
}
inline long long sub(long long a,long long b) {
    return ((a%MOD) - (b%MOD) + MOD) % MOD;
}
inline long long mul(long long a,long long b) {
    return ((a%MOD) * (b%MOD)) % MOD;
}

int twopow[MAXN];
int twopowSum[MAXN];
void init() {
    ms(twopow,0);
    twopow[0] = 1;
    FOR(i,1,MAXN+1)
        twopow[i] = mul(2,twopow[i-1]);

    ms(twopowSum, 0);
    int sum_ = twopowSum[0] = 1;
    FOR(i,1,MAXN+1) {
        sum_ = add(sum_, twopow[i]);
        twopowSum[i] = sum_;
    }
}

int sol() {
    init();
    int sum_ = mul(twopowSum[N-2],K[N]);
    int a = N-3;
    int b = 1;
    FORD(i,N-1,1) {
        sum_ = add(sum_, mul(K[i], add(sub(twopowSum[a],twopow[b]), 1)));
        --a;
        ++b;
    }
    sum_ = add(sum_,mul(K[1], sub(1,twopow[N-1])));
    return sum_;
}
void solve(unsigned long long t) {
    printf("Case #%llu: %lld\n", t, sol());
}

