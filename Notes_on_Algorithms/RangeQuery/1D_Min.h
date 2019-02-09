

/*--------------------------------- Min query -----------------------*/
// Sparse table: Build O(n*log(n)), query O(1)


/*-----------------------------------------------------------------------*/
//Array indexed 0: [0,n)
int a[MAXN];
int n;

int indexx[MAXN][25];
void build() {
    //initialize index for the intervals with length 1
    for (int i=0; i < n; ++i)
        indexx[i][0] = i;

    //compute values from smaller to bigger intervals
    for (int j=1; 1 << j <= n; ++j)
        for (int i=0; i + (1 << j) - 1 < n; ++i) {
            if (a[indexx[i][j - 1]] < a[indexx[i + (1 << (j - 1))][j - 1]])
                indexx[i][j] = indexx[i][j - 1];
            else
                indexx[i][j] = indexx[i + (1 << (j - 1))][j - 1];
        }
}

int minQuery(int i, int j) {        // Return index: indexx[i][k] and indexx[j - (1<<k) + 1][k]
    int k = log2(j - i + 1);

    if(a[indexx[i][k]] <= a[indexx[j - (1<<k) + 1][k]])
        return a[indexx[i][k]];
    return a[indexx[j - (1<<k) + 1][k]];
}


/*-----------------------------------------------------------------------*/
//Array indexed 1: [1,n]
int a[MAXN];
int n;

int indexx[MAXN][25];
void build() {
    //initialize index for the intervals with length 1
    for (int i=0; i < n; ++i)
        indexx[i][0] = i;

    //compute values from smaller to bigger intervals
    for (int j=1; 1 << j <= n; ++j)
        for (int i=0; i + (1 << j) - 1 < n; ++i) {
            if (a[indexx[i][j - 1] + 1] < a[indexx[i + (1 << (j - 1))][j - 1] + 1])
                indexx[i][j] = indexx[i][j - 1];
            else
                indexx[i][j] = indexx[i + (1 << (j - 1))][j - 1];
        }
}

int minQuery(int i, int j) {        // Return index: indexx[i][k] and indexx[j - (1<<k) + 1][k]
    --i; --j;
    int k = log2(j - i + 1);
    if(a[indexx[i][k] + 1] <= a[indexx[j - (1<<k) + 1][k] + 1])
        return a[indexx[i][k] + 1];
    return a[indexx[j - (1<<k) + 1][k] + 1];
}
