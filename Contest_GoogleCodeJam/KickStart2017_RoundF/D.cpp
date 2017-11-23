
// https://codejam.withgoogle.com/codejam/contest/7254486/dashboard#s=p3&a=3

const int MAXN = 10000 + 3;

int N;
ll readInput() {
    si(N);
    return 0;
}


int dp[MAXN];
bool visited[MAXN];
int solDP(int n) {
    if(visited[n])
        return dp[n];

    visited[n] = true;

    FOR(i,1, safe_sqrt(n)+1) {
        dp[n-(i*i)] = visited[n-(i*i)] ? dp[n-(i*i)] : solDP(n-(i*i));
        dp[n] = min(dp[n], dp[n-(i*i)] + 1);
    }
    return dp[n];
}
int driver(int n) {
    ms(dp, 0x7f);
    ms(visited, false);

    // Base cases
    dp[0] = 0; visited[0] = true;

    return solDP(n);
}

int sol() {
    return driver(N);
}

void solve(unsigned long long t) {
    printf("Case #%llu: %lld\n", t, sol());
}
