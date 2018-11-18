
int dp[][];
int get(int i, int j) {
    int &res = dp[i][j];

    if(res != inf)
        return res;

    //////////////////////////////////////
    int i_, j_;

    // Case 1
    i_ = i + ...;
    j_ = j + ...;
    if(i_ in range [0,I] && j_ in range [0,J])
        res = min(res, get(i_, j_) + ...);

    // Case 2
    i_ = i - ...;
    j_ = j - ...;
    if(i_ in range [0,I] && j_ in range [0,J])
        res = min(res, get(i_, j_) + ...);

    // Case if
    if() {
        i_ = i + ...;
        j_ = j + ...;
        if(i_ in range [0,I] && j_ in range [0,J])
            res = min(res, get(i_, j_) + ...);
    }

    // Case For
    FOR() {
        i_ = i + ...;
        j_ = j + ...;
        if(i_ in range [0,I] && j_ in range [0,J])
            res = min(res, get(i_, j_) + ...);
    }

    /////////////////////////////////////
    return res;
}
int solveDP() {
    // Init
    ms(dp, 0x7f);

    // Base cases
    FOR(i,1,N+1) FOR(j,1,N+1) {
        dp[i][j] = 0;
    }

    // Top case
    return get(m , n) + ...;
}
