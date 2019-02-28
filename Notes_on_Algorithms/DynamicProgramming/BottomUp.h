
// Loop Bottom Up: i_ >= i, j_ >= j

// data
int a[MAXN], b[MAXN];

int dp[][];
int solveDP() {
    // Init
    ms(dp, 0x7f);
    dp[0][0] = 0;

    // Loop
    FOR(i,0,I+1) FOR(j,0,J+1) {
        int cur = dp[i][j];

        if(cur == inf)
            continue;

        //////////////////////////////////////
        int i_, j_;

        // Update 1
        i_ = i + ...;
        j_ = j + ...;
        if(i in range [0,I-1] && j in range [0,J-1] &&
                condition a[i] && condition b[j])
            dp[i_][j_] = min(dp[i_][j_], cur + ...);

        // Update 2
        i_ = i + ...;
        j_ = j + ...;
        if(i in range [0,I-1] && j in range [0,J-1] &&
                condition a[i] && condition b[j])
            dp[i_][j_] = min(dp[i_][j_], cur + ...);
    }

    // Choose wisely
    int res = inf;
    FOR(i,0,I) 
        res = min(res, dp[i][J])
    return res;
}
