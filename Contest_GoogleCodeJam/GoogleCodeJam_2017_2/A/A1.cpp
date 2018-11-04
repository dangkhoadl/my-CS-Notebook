
const int MAXN = 100 + 3;

int N, P;
int G[MAXN];
int readInput() {
    sii(N,P);
    FOR(i,1,N+1) si(G[i]);

    return 0;
}

int dp[MAXN][MAXN][MAXN][4];
bool visited[MAXN][MAXN][MAXN][4];
int get(int p1, int p2, int p3, int r) {
    int &res = dp[p1][p2][p3][r];
    bool &vis = visited[p1][p2][p3][r];
    if(vis)
        return res;
    vis = true;

    int p1_, p2_, p3_, r_;

    // Choose p1
    if(p1 > 0) {
        p1_ = p1 - 1;
        p2_ = p2;
        p3_ = p3;
        r_ = (r+1)%P;
        res = max(res, get(p1_,p2_,p3_,r_) + \
            (r==0 ? 1 : 0));
    }

    // Choose p2
    if(p2 > 0) {
        p1_ = p1;
        p2_ = p2 - 1;
        p3_ = p3;
        r_ = (r+2)%P;
        res = max(res, get(p1_,p2_,p3_,r_) + \
            (r==0 ? 1 : 0));
    }

    // Choose p3
    if(p3 > 0) {
        p1_ = p1;
        p2_ = p2;
        p3_ = p3 - 1;
        r_ = (r+3)%P;
        res = max(res, get(p1_,p2_,p3_,r_) + \
            (r==0 ? 1 : 0));
    }

    return res;
}
int solveDP(int p1, int p2, int p3) {
    ms(dp, 0);
    ms(visited, false);

    // Base cases
    FOR(r,0,P) {
        dp[0][0][0][r] = 0;
        visited[0][0][0][r] = true;
    }

    return get(p1,p2,p3,0);
}
int sol() {
    int p0=0,p1=0,p2=0,p3=0;
    FOR(i,1,N+1) {
        if(G[i] % P == 0) ++p0;
        else if(G[i] % P == 1) ++p1;
        else if(G[i] % P == 2) ++p2;
        else if(G[i] % P == 3) ++p3;
    }
    return p0 + solveDP(p1,p2,p3);
}

/* -------------------------------------------------------------------------*/
void solve(unsigned long long t) {
    printf("Case #%llu: %lld\n", t, sol()); 
}
