

int dp[MAXN][MAXN];
bool visited[MAXN][MAXN];
int get(int i, int j) {
    // Return processed cases
    if(visited[i][j])
        return dp[i][j];
    
    visited[i][j] = true;

    int i1,j1, i2,j2;

    // Case 1
    i1 = ;
    j1 = ;
    i2 = ;
    j2 = ;
    dp[i][j] = max(dp[i][j], get(i1,j1) + get(i2,j2));

    // Case 2
    i1 = ;
    j1 = ;
    i2 = ;
    j2 = ;
    dp[i][j] = max(dp[i][j], get(i1,j1) - get(i2,j2));

    // For
    FOR() {
        i1 = ;
        j1 = ;
        i2 = ;
        j2 = ;
        dp[i][j] = max(dp[i][j],  get(i1,j1) + get(i2,j2));
    }

    return dp[i][j];
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
