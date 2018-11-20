
// bfs Bottom UP: i_, j_ abitrary

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
        if(i_ in range [0,I] && j_ in range [0,J]) {
            if(dp[i_][j_] > cur + ...) { // Min Optimization
                dp[i_][j_] = cur + ...;
                Q.push( {i_, j_} );
            }
        }
        
        // Update 2
        i_ = i - ...;
        j_ = j - ...;
        if(i_ in range [0,I] && j_ in range [0,J]) {
            if(dp[i_][j_] > cur + ...) { // Min Optimization
                dp[i_][j_] = cur + ...;
                Q.push( {i_, j_} );
            }
        }

        // Case if
        if() {
            i_ = i - ...;
            j_ = j + ...;
            if(i_ in range [0,I] && j_ in range [0,J]) {
                if(dp[i_][j_] > cur + ...) { // Min Optimization
                    dp[i_][j_] = cur + ...;
                    Q.push( {i_, j_} );
                }
            }
        }

        // Case For
        FOR() {
            i_ = i + ...;
            j_ = j - ...;
            if(i_ in range [0,I] && j_ in range [0,J]) {
                if(dp[i_][j_] > cur + ...) { // Min Optimization
                    dp[i_][j_] = cur + ...;
                    Q.push( {i_, j_} );
                }
            }
        }
    }

    // Choose wisely
    int res = inf;
    FOR(i,0,I) 
        res = min(res, dp[i][J])
    return res;
}
