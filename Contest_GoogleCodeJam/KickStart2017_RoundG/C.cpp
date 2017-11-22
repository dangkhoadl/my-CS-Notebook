
// https://codejam.withgoogle.com/codejam/contest/3254486/dashboard#s=p2

const int MAXN = 40 + 3;

int N,M;
int mat[MAXN][MAXN];
ll readInput() {
    sii(N,M);
    FOR(n,1,N+1) FOR(m,1,M+1) {
        si(mat[n][m]);
    }
    return 0;
}


int rangeMinQuerry[MAXN][MAXN][MAXN][MAXN];
void precompute_min(int n, int m){
    for (int i = 0 ; (1<<i) <= n; i += 1){
        for(int j = 0 ; (1<<j) <= m ; j += 1){
            for (int x = 0 ; x + (1<<i) -1 < n; x+= 1){
                for (int y = 0 ;  y + (1<<j) -1 < m; y+= 1){
                    if (i == 0 and j == 0)
                        rangeMinQuerry[x][y][i][j] = mat[x+1][y+1]; // store x, y
                    else if (i == 0)
                        rangeMinQuerry[x][y][i][j] = min(rangeMinQuerry[x][y][i][j-1], rangeMinQuerry[x][y+(1<<(j-1))][i][j-1]);
                    else if (j == 0) 
                        rangeMinQuerry[x][y][i][j] = min(rangeMinQuerry[x][y][i-1][j], rangeMinQuerry[x+ (1<<(i-1))][y][i-1][j]);
                    else {
                        rangeMinQuerry[x][y][i][j] = min(rangeMinQuerry[x][y][i-1][j-1], rangeMinQuerry[x + (1<<(i-1))][y][i-1][j-1]);
                        rangeMinQuerry[x][y][i][j] = min(rangeMinQuerry[x][y][i][j], rangeMinQuerry[x][y+(1<<(j-1))][i-1][j-1]);
                        rangeMinQuerry[x][y][i][j] = min(rangeMinQuerry[x][y][i][j], rangeMinQuerry[x + (1<<(i-1))][y+(1<<(j-1))][i-1][j-1]);
                    }
                }
            }
        }
    }
}

int query_min(int i1, int j1, int i2, int j2) {
    i1--, j1--,i2--,j2--;
    int k = log2(i2 - i1 + 1);
    int l = log2(j2 - j1 + 1);
    int ans = min(rangeMinQuerry[i1][j1][k][l], rangeMinQuerry[i2 - (1<<k) + 1][j1][k][l]);
    ans = min(ans, rangeMinQuerry[i1][j2 - (1<<l) + 1][k][l]);
    ans = min(ans, rangeMinQuerry[i2 - (1<<k) + 1][j2 - (1<<l) + 1][k][l]);
    return ans;
}


int dp[MAXN][MAXN][MAXN][MAXN];
bool visited[MAXN][MAXN][MAXN][MAXN];
int cut(int i1, int j1, int i2, int j2) {
    // Return processed cases
    if(visited[i1][j1][i2][j2])
        return dp[i1][j1][i2][j2];
    
    visited[i1][j1][i2][j2] = true;

    int currentCoin = query_min(i1,j1,i2,j2);

    // Cut Horizontally
    FOR(m,i1,i2) {
        dp[i1][j1][m][j2] = visited[i1][j1][m][j2] ? dp[i1][j1][m][j2] : cut(i1,j1,m,j2);
        dp[m+1][j1][i2][j2] = visited[m+1][j1][i2][j2] ? dp[m+1][j1][i2][j2] : cut(m+1,j1,i2,j2);

        dp[i1][j1][i2][j2] = max(dp[i1][j1][i2][j2], dp[i1][j1][m][j2] + dp[m+1][j1][i2][j2] + currentCoin);
    }

    // Cut Vertically
    FOR(m,j1,j2) {
        dp[i1][j1][i2][m] = visited[i1][j1][i2][m] ? dp[i1][j1][i2][m] : cut(i1,j1,i2,m);
        dp[i1][m+1][i2][j2] = visited[i1][m+1][i2][j2] ? dp[i1][m+1][i2][j2] : cut(i1,m+1,i2,j2);

        dp[i1][j1][i2][j2] = max(dp[i1][j1][i2][j2], dp[i1][j1][i2][m] + dp[i1][m+1][i2][j2] + currentCoin);
    }

    return dp[i1][j1][i2][j2];
}

int sol() {
    precompute_min(N+1,M+1);

    ms(dp, 0);
    ms(visited, false);

    // Base cases
    FOR(i,1,N+1) FOR(j,1,N+1) {
        dp[i][j][i][j] = 0;
        visited[i][j][i][j] = true;
    }

    return cut(1,1,N,M);
}

void solve(unsigned long long t) {
    printf("Case #%llu: %lld\n", t, sol());
}
