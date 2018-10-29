

/*--------------------------------------------------- MAX query ------------------------------------------------*/
// Sparse table
// Precomputation Time - O( N x M x log(N) x log(M))
// Query Time - O(log(N) x log(M))

// index 1: size N*M: precompute_max(N+1,M+1);
int mat[MAXN][MAXN];

int rangeMaxQuerry[MAXN][MAXN][MAXN][MAXN];
void precompute_max(int n, int m){
    for (int i = 0 ; (1<<i) <= n; i += 1){
        for(int j = 0 ; (1<<j) <= m ; j += 1){
            for (int x = 0 ; x + (1<<i) -1 < n; x+= 1){
                for (int y = 0 ;  y + (1<<j) -1 < m; y+= 1){
                    if (i == 0 and j == 0)
                        rangeMaxQuerry[x][y][i][j] = mat[x+1][y+1]; // store x, y
                    else if (i == 0)
                        rangeMaxQuerry[x][y][i][j] = max(rangeMaxQuerry[x][y][i][j-1], rangeMaxQuerry[x][y+(1<<(j-1))][i][j-1]);
                    else if (j == 0) 
                        rangeMaxQuerry[x][y][i][j] = max(rangeMaxQuerry[x][y][i-1][j], rangeMaxQuerry[x+ (1<<(i-1))][y][i-1][j]);
                    else {
                        rangeMaxQuerry[x][y][i][j] = max(rangeMaxQuerry[x][y][i-1][j-1], rangeMaxQuerry[x + (1<<(i-1))][y][i-1][j-1]);
                        rangeMaxQuerry[x][y][i][j] = max(rangeMaxQuerry[x][y][i][j], rangeMaxQuerry[x][y+(1<<(j-1))][i-1][j-1]);
                        rangeMaxQuerry[x][y][i][j] = max(rangeMaxQuerry[x][y][i][j], rangeMaxQuerry[x + (1<<(i-1))][y+(1<<(j-1))][i-1][j-1]);
                    }
                }
            }
        }
    }
}

int query_max(int i1, int j1, int i2, int j2){
    i1--, j1--,i2--,j2--;
    int k = log2(i2 - i1 + 1);
    int l = log2(j2 - j1 + 1);
    int ans = max(rangeMaxQuerry[i1][j1][k][l], rangeMaxQuerry[i2 - (1<<k) + 1][j1][k][l]);
    ans = max(ans, rangeMaxQuerry[i1][j2 - (1<<l) + 1][k][l]);
    ans = max(ans, rangeMaxQuerry[i2 - (1<<k) + 1][j2 - (1<<l) + 1][k][l]);
    return ans;
}


// index 0: size N*M: precompute_max(N,M);
int mat[MAXN][MAXN];

int rangeMaxQuerry[MAXN][MAXN][MAXN][MAXN];
void precompute_max(int n, int m){
    for (int i = 0 ; (1<<i) <= n; i += 1){
        for(int j = 0 ; (1<<j) <= m ; j += 1){
            for (int x = 0 ; x + (1<<i) -1 < n; x+= 1){
                for (int y = 0 ;  y + (1<<j) -1 < m; y+= 1){
                    if (i == 0 and j == 0)
                        rangeMaxQuerry[x][y][i][j] = mat[x][y]; // store x, y
                    else if (i == 0)
                        rangeMaxQuerry[x][y][i][j] = max(rangeMaxQuerry[x][y][i][j-1], rangeMaxQuerry[x][y+(1<<(j-1))][i][j-1]);
                    else if (j == 0) 
                        rangeMaxQuerry[x][y][i][j] = max(rangeMaxQuerry[x][y][i-1][j], rangeMaxQuerry[x+ (1<<(i-1))][y][i-1][j]);
                    else {
                        rangeMaxQuerry[x][y][i][j] = max(rangeMaxQuerry[x][y][i-1][j-1], rangeMaxQuerry[x + (1<<(i-1))][y][i-1][j-1]);
                        rangeMaxQuerry[x][y][i][j] = max(rangeMaxQuerry[x][y][i][j], rangeMaxQuerry[x][y+(1<<(j-1))][i-1][j-1]);
                        rangeMaxQuerry[x][y][i][j] = max(rangeMaxQuerry[x][y][i][j], rangeMaxQuerry[x + (1<<(i-1))][y+(1<<(j-1))][i-1][j-1]);
                    }
                }
            }
        }
    }
}

int query_max(int i1, int j1, int i2, int j2){
    int k = log2(i2 - i1 + 1);
    int l = log2(j2 - j1 + 1);
    int ans = max(rangeMaxQuerry[i1][j1][k][l], rangeMaxQuerry[i2 - (1<<k) + 1][j1][k][l]);
    ans = max(ans, rangeMaxQuerry[i1][j2 - (1<<l) + 1][k][l]);
    ans = max(ans, rangeMaxQuerry[i2 - (1<<k) + 1][j2 - (1<<l) + 1][k][l]);
    return ans;
}
