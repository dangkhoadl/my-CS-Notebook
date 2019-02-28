
// bfs Bottom UP: i_, j_ abitrary

// data
int a[MAXN], b[MAXN];

int dp[][];
int solveDP() {
    // Init
    ms(dp, 0x7f);
    queue<pair<int,int>> Q;

    // Base cases
    dp[0][0] = 0;
    Q.push({0,0});

    // bfs
    while(!Q.empty()) {
        int i = Q.front().first;
        int j = Q.front().second;
        Q.pop();

        int cur = dp[i][j];
        if(cur == inf)
            continue;

        //////////////////////////////////////
        int i_, j_;

        // Update 1
        i_ = i + ...;
        j_ = j + ...;
        if(i in range [0,I-1] && j in range [0,J-1] &&
                condition a[i] && condition b[j]) {

            // Min Optimization
            if(dp[i_][j_] > cur + ...) {
                dp[i_][j_] = cur + ...;
                Q.push( {i_, j_} );
            }
        }
        
        // Update 2
        i_ = i - ...;
        j_ = j - ...;
        if(i in range [0,I-1] && j in range [0,J-1] &&
                condition a[i] && condition b[j]) {

            // Min Optimization
            if(dp[i_][j_] > cur + ...) {
                dp[i_][j_] = cur + ...;
                Q.push( {i_, j_} );
            }
        }
    }

    // Choose wisely
    int res = inf;
    FOR(i,0,I) 
        res = min(res, dp[i][J])
    return res;
}
