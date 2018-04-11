
// https://codejam.withgoogle.com/codejam/contest/11304486/dashboard#s=p2

const int MAXN = 100 + 3;

int N,M,K;
char a[MAXN][MAXN];
ll readInput() {
    si(N); si(M); si(K);
    FOR(n,1,N+1)
        ss(a[n],1);
    return 0;
}

int cnt[MAXN];
void preCalc() {
    ms(cnt,0);
    cnt[0] = 0;
    int step = 1;
    FOR(i,1,MAXN) {
        cnt[i] = cnt[i-1] + step;
        step += 2;
    }
}

inline bool inRange(int x, int a, int b) {
    return a <= x && x < b; 
}
bool ok(int n, int m) {
    if(!inRange(n,1,N+1) || !inRange(m,1,M+1))
        return false;
    if(a[n][m] == '.')
        return false;
    return true;
}

int dp1[MAXN][MAXN];
vi hei[MAXN][MAXN];
bool visited[MAXN][MAXN][MAXN][MAXN];
int dp2[MAXN][MAXN][MAXN][MAXN];
int sol() {
    ms(dp1, 0x7f);
    FOR(m,1,M+1) 
        dp1[N][m] = a[N][m] == '#' ? 1 : 0;
    FOR(n,1,N+1) {
        dp1[n][1] = a[n][1] == '#' ? 1 : 0;
        dp1[n][M] = a[n][M] == '#' ? 1 : 0;
    }
    FORD(n,N-1,0) FOR(m,2,M) {
        if(a[n][m] == '.') {
            dp1[n][m] = 0;
            continue;
        }
        dp1[n][m] = min(dp1[n+1][m] + 1, dp1[n][m]);
        dp1[n][m] = min(dp1[n+1][m-1] + 1, dp1[n][m]);
        dp1[n][m] = min(dp1[n+1][m+1] + 1, dp1[n][m]);
    }


    FOR(n,1,N+1) FOR(m,1,M+1) 
        hei[n][m].clear();
    FOR(n,1,N+1) FOR(m,1,M+1) FOR(i,1,dp1[n][m]+1)
        hei[n][m].pb(i);


    preCalc();
    int res = 0;
    ms(visited,false);
    ms(dp2,0);
    queue<pair<pii,pii>> q;
    FOR(n,1,N+1) FOR(m,1,M+1) FOR(i,0,sz(hei[n][m])) {
        if(!ok(n,m))
            continue;
        visited[n][m][hei[n][m][i]][1] = true;
        q.push({{n,m}, {hei[n][m][i],1}});
        dp2[n][m][hei[n][m][i]][1] = cnt[hei[n][m][i]];
    }
    while(!q.empty()) {
        int r = q.front().fi.fi;
        int c = q.front().fi.se;
        int h = q.front().se.fi;
        int k = q.front().se.se;
        int v = dp2[r][c][h][k];
        q.pop();

        if(!ok(r,c))
            continue;

        if(k == K)
            res = max(res, v);

        int r_,h_,k_,v_;
        r_ = r + h;
        k_ = k + 1;
        if(k_ > K)
            continue;
        FOR(c_,c-h+1,c+h) {
            if(!ok(r_,c_))
                continue;
            FOR(i,0,sz(hei[r_][c_])) {
                h_ = hei[r_][c_][i];
                v_ = cnt[h_] + v;
                if(!visited[r_][c_][h_][k_]) {
                    visited[r_][c_][h_][k_] = true;
                    q.push({{r_,c_},{h_,k_}});
                }
                dp2[r_][c_][h_][k_] = max(dp2[r_][c_][h_][k_], v_);
            }
        }
    }
    return res;
}

void solve(unsigned long long t) {
    printf("Case #%llu: %lld\n", t, sol());
}
