
// bfs + DP template

bool visited[][];
int dp[][];
int bfs() {
    ms(visited, false);
    ms(dp, );

    queue<pii> q;
    q.push( { 0,0 } );

    visited[0][0] = true;
    dp[0][0] = ;

    while(!q.empty()) {
        int a = q.front().fi;
        int b = q.front().se;
        q.pop();

        //----------- Process current state ---------
        if(a == N)
            res = max(res, );


        //---------- Next stages ---------
        int a_,b_,dp_;

        // Case 1
        a_ =  ;
        b_ =  ;
        dp_ =  dp[a][b] + ;
        if(!visited[a_][b_] and a_ <= A and b_ <= B) {
            visited[a_][b_] = true;
            q.push( {a_, b_} );
        }
        dp[a_][b_] = max(dp[a_][b_], dp_); 


        // Case 2
        a_ =  ;
        b_ =  ;
        dp_ =  dp[a][b] + ;
        if(!visited[a_][b_] and a_ <= A and b_ <= B) {
            visited[a_][b_] = true;
            q.push( {a_, b_} );
        }
        dp[a_][b_] = max(dp[a_][b_], dp_);
        

        // Cases for
        FOR() {
            a_ =  ;
            b_ =  ;
            dp_ =  dp[a][b] + ;
            if(!visited[a_][b_] and a_ <= A and b_ <= B) {
                visited[a_][b_] = true;
                q.push( {a_,b_} );
            }
            dp[a_][b_] = max(dp[a_][b_], dp_)
        }
    }

    //Check and return value
    FOR()
        res = max(res, );
    return dp[][];
}
