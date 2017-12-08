
// https://codejam.withgoogle.com/codejam/contest/5314486/dashboard

const int MAXN = 100 + 3;
const int MAXP = 4 + 1;

int N, P;
int G[MAXN];
ll readInput() {
    sii(N,P);
    FOR(n,1,N+1)
        si(G[n]);
    return 0;
}

/* ---------------------------------------- SOL 1 ---------------------------------*/
int dp[MAXN][MAXN][MAXN][MAXP];
bool visited[MAXN][MAXN][MAXN][MAXP];

int get(int p1, int p2, int p3, int r) {
    int &res = dp[p1][p2][p3][r];
    bool &vis = visited[p1][p2][p3][r];

    if(vis)
        return res;
    vis = true;

    int p1_,p2_,p3_,r_;

    if(p1 > 0) {
        p1_ = p1 - 1;
        p2_ = p2;
        p3_ = p3;
        r_ = (r + 1) % P;
        res = max(res, get(p1_, p2_, p3_, r_) + (r == 0 ? 1 : 0));
    }

    if(p2 > 0) {
        p1_ = p1;
        p2_ = p2 - 1;
        p3_ = p3;
        r_ = (r + 2) % P;
        res = max(res, get(p1_, p2_, p3_, r_) + (r == 0 ? 1 : 0));
    }

    if(p3 > 0) {
        p1_ = p1;
        p2_ = p2;
        p3_ = p3 - 1;
        r_ = (r + 3) % P;
        res = max(res, get(p1_, p2_, p3_, r_) + (r == 0 ? 1 : 0));
    }
    return res;
}
int sol1() {
    ms(dp, 0);
    ms(visited, false);

    FOR(r,0,P) {
        dp[0][0][0][r] = 0;
        visited[0][0][0][r] = true;
    }

    int p[MAXP] = {0,0,0,0};
    FOR(n,1,N+1) {
        ++p[G[n] % P];
    }
    return get(p[1],p[2],p[3],0) + p[0];
}

/* ---------------------------------------- SOL 2 ---------------------------------*/
map<pair<vi,int>, int> DP;
map<pair<vi,int>, bool> VISITED;
int getV(const vi &p, int r) {
    int &res = DP[{p,r}];
    bool &vis = VISITED[{p,r}];

    if(vis)
        return res;
    vis = true;

    vi p_;
    int r_;

    FOR(i,1,P) {
        if(p[i] > 0) {
            p_ = p;
            --p_[i];
            r_ = (r + i) % P;

            res = max(res, getV(p_, r_) + (r == 0 ? 1 : 0));
        }
    }
    return res;
}

int sol2() {
    DP.clear();
    VISITED.clear();

    vi z(P,0);
    FOR(r,0,P) {
        DP[{ z, r }] = 0;
        VISITED[ { z, r } ] = true;
    }

    vi p(P,0);
    FOR(n,1,N+1) {
        ++p[G[n] % P];
    }

    return getV(p, 0) + p[0];
}

/* -------------------------------------------------------------------------*/
void solve(unsigned long long t) {
    printf("Case #%llu: %lld\n", t, sol1()); 
}
