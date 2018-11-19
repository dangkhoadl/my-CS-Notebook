
// Loop Bottom Up: i_ >= i, j_ >= j

int dp[][];
int solveDP() {
    // Init
    ms(dp, 0x7f);

    // Base cases
    dp[0][0] = 0;

    // Loop
    FOR(i,0,I) FOR(j,0,J) {
        int cur = dp[i][j];

        if(cur == inf)
            continue;

        //////////////////////////////////////
        int i_, j_;

        // Update 1
        i_ = i + ...;
        j_ = j + ...;
        if(i_ in range [0,I] && j_ in range [0,J])
            dp[i_][j_] = min(dp[i_][j_], cur + ...);

        // Update 2
        i_ = i + ...;
        j_ = j + ...;
        if(i_ in range [0,I] && j_ in range [0,J])
            dp[i_][j_] = min(dp[i_][j_], cur + ...);

        // Case if
        if() {
            i_ = i + ...;
            j_ = j + ...;
            if(i_ in range [0,I] && j_ in range [0,J])
                dp[i_][j_] = min(dp[i_][j_], cur + ...);
        }

        // Case For
        FOR() {
            i_ = i + ...;
            j_ = j + ...;
            if(i_ in range [0,I] && j_ in range [0,J])
                dp[i_][j_] = min(dp[i_][j_], cur + ...);
        }
    }

    // Return value: The safest way is to loop through the whole table
    int res = inf;
    FOR(i,0,I) FOR(j,0,J)
        res = min(res, dp[i][j])
    return res;
}
