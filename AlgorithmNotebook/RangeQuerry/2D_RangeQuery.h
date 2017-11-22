
/*--------------------------------------------------- SUM query ------------------------------------------------*/
// Precomputation Time - O(N x M)
// Query Time - O(1)

// Index 1 - size N*M: precompute_sum(N,M)
int mat[MAXN][MAXN];

int T[MAXN][MAXN];
void precompute_sum(int n, int m) {
    memset(T,0,sizeof(T));
    for (int i=1; i<=n; i++)
        T[1][i] = mat[1][i];
 
    for (int i=2; i<=m; i++)
        for (int j=1; j<=n; j++)
            T[i][j] = mat[i][j] + T[i-1][j];
   
    for (int i=1; i<=m; i++)
        for (int j=2; j<=n; j++)
            T[i][j] += T[i][j-1];
}

int query_sum(int i1,int j1, int i2, int j2) {
    int res = T[i2][j2];

    if (i1 > 1)
       res -= T[i1-1][j2];
 
    if (j1 > 1)
       res -= T[i2][j1-1];
 
    if (i1 > 1 && j1 > 1)
       res += T[i1-1][j1-1];

    return res;
}

// Index 0 - size N*M: precompute_sum(N,M)
int mat[MAXN][MAXN];

int T[MAXN][MAXN];
void precompute_sum(int n, int m) {
    memset(T,0,sizeof(T));
    for (int i=0; i<n; i++)
        T[0][i] = mat[0][i];
 
    for (int i=1; i<m; i++)
        for (int j=0; j<n; j++)
            T[i][j] = mat[i][j] + T[i-1][j];
   
    for (int i=0; i<m; i++)
        for (int j=1; j<n; j++)
            T[i][j] += T[i][j-1];
}

int query_sum(int i1,int j1, int i2, int j2) {
    int res = T[i2][j2];

    if (i1 > 0)
       res -= T[i1-1][j2];
 
    if (j1 > 0)
       res -= T[i2][j1-1];
 
    if (i1 > 0 && j1 > 0)
       res += T[i1-1][j1-1];

    return res;
}

/*--------------------------------------------------- MIN query ------------------------------------------------*/
// Sparse table
// Precomputation Time - O( N x M x log(N) x log(M))
// Query Time - O(log(N) x log(M))

// index 1: size N*M: precompute_min(N+1,M+1);
int mat[MAXN][MAXN];

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

int query_min(int i1, int j1, int i2, int j2){
    i1--, j1--,i2--,j2--;
    int k = log2(i2 - i1 + 1);
    int l = log2(j2 - j1 + 1);
    int ans = min(rangeMinQuerry[i1][j1][k][l], rangeMinQuerry[i2 - (1<<k) + 1][j1][k][l]);
    ans = min(ans, rangeMinQuerry[i1][j2 - (1<<l) + 1][k][l]);
    ans = min(ans, rangeMinQuerry[i2 - (1<<k) + 1][j2 - (1<<l) + 1][k][l]);
    return ans;
}


// index 0: size N*M: precompute_min(N,M);
int mat[MAXN][MAXN];

int rangeMinQuerry[MAXN][MAXN][MAXN][MAXN];
void precompute_min(int n, int m){
    for (int i = 0 ; (1<<i) <= n; i += 1){
        for(int j = 0 ; (1<<j) <= m ; j += 1){
            for (int x = 0 ; x + (1<<i) -1 < n; x+= 1){
                for (int y = 0 ;  y + (1<<j) -1 < m; y+= 1){
                    if (i == 0 and j == 0)
                        rangeMinQuerry[x][y][i][j] = mat[x][y]; // store x, y
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

int query_min(int i1, int j1, int i2, int j2){
    int k = log2(i2 - i1 + 1);
    int l = log2(j2 - j1 + 1);
    int ans = min(rangeMinQuerry[i1][j1][k][l], rangeMinQuerry[i2 - (1<<k) + 1][j1][k][l]);
    ans = min(ans, rangeMinQuerry[i1][j2 - (1<<l) + 1][k][l]);
    ans = min(ans, rangeMinQuerry[i2 - (1<<k) + 1][j2 - (1<<l) + 1][k][l]);
    return ans;
}

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
