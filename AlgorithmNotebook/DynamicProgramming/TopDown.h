

int dp[MAXN][MAXN];
bool visited[MAXN][MAXN];
int solveDP(int i, int j) {
    // Return processed cases
    if(visited[i][j])
        return dp[i][j];
    
    visited[i][j] = true;

    // Case 1
    dp[i1][j1] = visited[i1][j1] ? dp[i1][j1] : solveDP(i1,j1);
    dp[i2][j2] = visited[i2][j2] ? dp[i2][j2] : solveDP(i2,j2);
    dp[i][j] = max(dp[i][j], dp[i1][j1] + dp[i2][j2]);

    // Case 2
    dp[i1][j1] = visited[i1][j1] ? dp[i1][j1] : solveDP(i1,j1);
    dp[i2][j2] = visited[i2][j2] ? dp[i2][j2] : solveDP(i2,j2);
    dp[i][j] = max(dp[i][j], dp[i1][j1] + dp[i2][j2]);

    // For
    FOR() {
        dp[i1][j1] = visited[i1][j1] ? dp[i1][j1] : solveDP(i1,j1);
        dp[i2][j2] = visited[i2][j2] ? dp[i2][j2] : solveDP(i2,j2);
        dp[i][j] = max(dp[i][j], dp[i1][j1] + dp[i2][j2]);
    }

    return dp[i][j];
}
int driver() {
    ms(dp, 0);
    ms(visited, false);

    // Base cases
    FOR(i,1,N+1) FOR(j,1,N+1) {
        dp[i][j] = 0;
        visited[i][j] = true;
    }

    return solveDP(N,N);    // Top case
}
