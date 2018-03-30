

int dp[MAXN][MAXN];
bool visited[MAXN][MAXN];
int get(int i, int j) {
    int &res = dp[i][j];
    bool &vis = visited[i][j];
    if(vis)
        return res;
    vis = true;


    //////////////////////////////////////
    int i1,j1, i2,j2;

    // Case 1
    i1 = ;
    j1 = ;
    i2 = ;
    j2 = ;
    res = max(res, get(i1,j1) + get(i2,j2));

    // Case 2
    i1 = ;
    j1 = ;
    i2 = ;
    j2 = ;
    res = max(res, get(i1,j1) - get(i2,j2));

    // For
    FOR() {
        i1 = ;
        j1 = ;
        i2 = ;
        j2 = ;
        res = max(res,  get(i1,j1) + get(i2,j2));
    }

    return res;
}
int solveDP() {
    ms(dp, 0);
    ms(visited, false);

    // Base cases
    FOR(i,1,N+1) FOR(j,1,N+1) {
        dp[i][j] = 0;
        visited[i][j] = true;
    }

    return get(N,N);    // Top case
}
