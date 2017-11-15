
int dp[][];
bool visited[][];
int solveDP() {
    ms(visited, false);
    ms(dp, ); //0x7f, -0x7f, -1, 0
    
    // Init state
    dp[0][0] = ;
    visited[0][0] = true;

    FOR(i) FOR(j) {
        if(!visited[i][j])
            continue;
        int i_, j_, dp_;

        // Case 1
        i_ = ;
        j_ = ;
        dp_ = ;
        if(i_ <=  and j_ <= and dp_ ) {
            dp[i_][j_] = max(dp[i_][j_], dp_);
            visited[i_][j_] = true;
        }
            

        // Case 2
        i_ = ;
        j_ = ;
        dp_ = ;
        if(i_ <=  and j_ <= and dp_ ) {
            dp[i_][j_] = max(dp[i_][j_], dp_);
            visited[i_][j_] = true;
        }
    }

    FOR()
        res = max(res, );
    return dp[][];
}
