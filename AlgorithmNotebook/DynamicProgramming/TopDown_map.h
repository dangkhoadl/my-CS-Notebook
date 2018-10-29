

map<pair<vi,int>, int> dp;
map<pair<vi,int>, bool> visited;
int get(const vi &p, int r) {
    int &res = dp[{p,r}];
    bool &vis = visited[{p,r}];

    if(vis)
        return res;
    vis = true;

    vi r1;
    int r1;

    // Case 1
    p1 =
    r1 = 

    p2 =
    r2 =

    res = get(p1, r1) + get(p2, r2);

    // Case 2
    p1 =
    r1 = 

    p2 =
    r2 =

    res = get(p1, r1) + get(p2, r2);

    // Case FOR
    FOR(i) {
        p1 =
        r1 = 

        p2 =
        r2 =

        res = get(p1, r1) + get(p2, r2);
        
    }
    return res;
}

int solDP() {
    dp.clear();
    visited.clear();

    // Base cases
    vi z(P,0);
    FOR(r,0,P) {
        dp[{ z, r }] = 0;
        visited[ { z, r } ] = true;
    }

    // Top case
    vi p(P,0);
    FOR(n,1,N+1) {
        ++p[n];
    }

    return get(p, 0);
}
