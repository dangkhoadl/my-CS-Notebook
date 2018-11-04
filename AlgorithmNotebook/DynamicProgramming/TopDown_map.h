

map<pair<vi,int>, int> dp;
map<pair<vi,int>, bool> visited;
int get(const pair<vi,int> &p) {
    int &res = dp[p];
    bool &vis = visited[p];

    if(vis)
        return res;
    vis = true;


    //////////////////////////////////////
    pair<vi,int> p_;

    // Case 1
    p_ = p + ...;
    res = max(res, get(p) + ...);

    // Case 2
    p_ = p - ...;
    res = max(res, get(p) + ...);

    // Case if
    if() {
        p_ = p - ...;
        res = max(res, get(p) + ...);
    }

    // Case For
    FOR() {
        p_ = p + ...;
        res = max(res, get(p) + ...);
    }

    /////////////////////////////////////
    return res;
}

int solDP() {
    // Clear
    dp.clear();
    visited.clear();

    // Base cases
    FOR(r,0,P) {
        dp[ {{0,0,0},r} ] = 0;
        visited[ {{0,0,0},r} ] = true;
    }

    // Top case
    pair<vi,int> p = {{,,,}, }

    return get(p) + ...;
}
