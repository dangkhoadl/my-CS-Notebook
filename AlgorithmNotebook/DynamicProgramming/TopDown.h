
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
    res = min(res, get(i_, j_) + ...);

    // Case 2
    i_ = i - ...;
    j_ = j - ...;
    res = min(res, get(i_, j_) + ...);

    // Case if
    if() {
        i_ = i + ...;
        j_ = j + ...;
        res = min(res, get(i_, j_) + ...);
    }

    // Case For
    FOR() {
        i_ = i + ...;
        j_ = j + ...;
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


/*******************************************************************************************************************/
int dp[MAXN][MAXN];
int get(int i, int j) {
    int &res = dp[i][j];

    if(res != ninf)
        return res;


    //////////////////////////////////////
    int i1_, j1_;
    int i2_, j2_;

    // Case 1
    i1_ = i + ...;
    j1_ = j - ...;
    i2_ = i + ...;
    j2_ = j - ...;
    res = max(res, get(i_, j_) + get(i_, j_) + ...);

    // Case 2
    i1_ = i - ...;
    j1_ = j - ...;
    i2_ = i + ...;
    j2_ = j + ...;
    res = max(res, get(i_, j_) - get(i_, j_) + ...);

    // Case if
    if() {
        i1_ = i + ...;
        j1_ = j + ...;
        i2_ = i + ...;
        j2_ = j + ...;
        res = max(res, get(i_, j_) - get(i_, j_) + ...);
    }

    // Case For
    FOR() {
        i1_ = i - ...;
        j1_ = j - ...;
        i2_ = i - ...;
        j2_ = j - ...;
        res = max(res, get(i_, j_) - get(i_, j_) - ...);
    }

    /////////////////////////////////////
    return res;
}
int solveDP() {
    // Init
    ms(dp, -0x7f);

    // Base cases
    FOR(i,1,N+1) FOR(j,1,N+1) {
        dp[i][j] = 0;
    }

    // Top case
    return get( , ) + get( , ) - ...;
}
