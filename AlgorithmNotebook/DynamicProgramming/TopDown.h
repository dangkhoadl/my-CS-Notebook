

int dp[MAXN][MAXN];
bool visited[MAXN][MAXN];
int get(int i, int j) {
    int &res = dp[i][j];
    bool &vis = visited[i][j];

    if(vis)
        return res;
    vis = true;


    //////////////////////////////////////
    int i_, j_;

    // Case 1
    i_ = i + ...;
    j_ = j + ...;
    res = max(res, get(i_, j_) + ...);

    // Case 2
    i_ = i - ...;
    j_ = j - ...;
    res = max(res, get(i_, j_) + ...);

    // Case if
    if() {
        i_ = i + ...;
        j_ = j + ...;
        res = max(res, get(i_, j_) + ...);
    }

    // Case For
    FOR() {
        i_ = i + ...;
        j_ = j + ...;
        res = max(res, get(i_, j_) + ...);
    }

    /////////////////////////////////////
    return res;
}
int solveDP() {
    // Clear
    ms(dp, 0);
    ms(visited, false);

    // Base cases
    FOR(i,1,N+1) FOR(j,1,N+1) {
        dp[i][j] = 0;
        visited[i][j] = true;
    }

    // Top case
    return get( , ) + ...;
}


/*******************************************************************************************************************/
int dp[MAXN][MAXN];
bool visited[MAXN][MAXN];
int get(int i, int j) {
    int &res = dp[i][j];
    bool &vis = visited[i][j];

    if(vis)
        return res;
    vis = true;


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
    // Clear
    ms(dp, 0);
    ms(visited, false);

    // Base cases
    FOR(i,1,N+1) FOR(j,1,N+1) {
        dp[i][j] = 0;
        visited[i][j] = true;
    }

    // Top case
    return get( , ) + get( , ) - ...;
}
