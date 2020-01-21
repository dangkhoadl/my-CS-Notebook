
// https://code.google.com/codejam/contest/12254486/dashboard#s=p1

const int MAXN = 3000 + 3;

int R,C,K;
char mat[MAXN][MAXN];
ll readInput() {
    ms(mat, 'O');
    si(R); si(C); si(K);
    REP(K) {
        int r,c;
        sii(r,c);
        mat[r][c] = 'X';
    }
    return 0;
}

int dp[MAXN][MAXN];
int sol() {
    ms(dp,0x7f);
    FOR(r,0,R) 
        dp[r][0] = mat[r][0] == 'X' ? 0 : 1;
    FOR(c,0,C) 
        dp[0][c] = mat[0][c] == 'X' ? 0 : 1;
    FOR(r,1,R) FOR(c,1,C) {
        if(mat[r][c] == 'X') {
            dp[r][c] = 0;
            continue;
        }
        dp[r][c] = min(dp[r][c], dp[r-1][c] + 1);
        dp[r][c] = min(dp[r][c], dp[r][c-1] + 1);
        dp[r][c] = min(dp[r][c], dp[r-1][c-1] + 1);
    }

    int cnt = 0;
    FOR(r,0,R) FOR(c,0,C) 
        cnt += dp[r][c];
    return cnt;
}
void solve(unsigned long long t) {
    printf("Case #%llu: %lld\n", t, sol());
}
