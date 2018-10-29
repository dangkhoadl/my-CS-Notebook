
bool visited[][];
int dp[][];
int solveDP() {
    ms(visited, false);
    ms(dp, );
    
    visited[0][0] = true;
    dp[0][0] = ;

    FOR(i) FOR(j) {
        if(!visited[i][j])
            continue;

        //----------- Process current state ---------
        if(i == N)
            res = max(res, );


        //---------- Next stages ---------
        int i_, j_, dp_;

        // Case 1
        i_ = ;
        j_ = ;
        dp_ = dp[i][j] + ;
        if(i_ <=  I and j_ <= J and dp_ ) {
            visited[i_][j_] = true;
            dp[i_][j_] = max(dp[i_][j_], dp_);
        }
            

        // Case 2
        i_ = ;
        j_ = ;
        dp_ = dp[i][j] + ;
        if(i_ <= I and j_ <= J and dp_ ) {
            visited[i_][j_] = true;
            dp[i_][j_] = max(dp[i_][j_], dp_);
        }

        // Cases for
        FOR() {
            i_ = ;
            j_ = ;
            dp_ = dp[i][j] + ;
            if(i_ <= I and j_ <= J and dp_ ) {
                visited[a_][b_] = true;
                dp[i_][j_] = max(dp[i_][j_], dp_)
            }
        }
    }

    //Check and return value
    FOR()
        res = max(res, );
    return dp[][];
}
