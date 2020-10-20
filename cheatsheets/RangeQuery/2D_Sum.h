
/*--------------------- SUM query -------------------------*/
// Precomputation Time - O(N x M)
// Query Time - O(1)


/*-----------------------------------------------------------*/
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


/*----------------------------------------------------------*/
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
