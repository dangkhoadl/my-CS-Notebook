
// bfs + DP template

bool visited[][];
int dp[][];
int bfs() {
	// Reset 
	ms(visited, false);
	ms(dp, );

	// Init 1st stage
	queue<pii> q;
	q.push( { 0,0 } );
	dp[0][0] = ;
	while(!q.empty()) {
		// current state
		int a = q.front().fi;
		int b = q.front().se;
		int x = dp[a][b];
		q.pop();

		//Stop condition
		if( a > A )
			continue;

		//Process current state


		/*____________ next states ______________*/
		int a_,b_,x_;

		// next state i
		a_ =  ;
		b_ =  ;
		x_ =  ;

		// check visited
		if(!visited[a_][b_]) {
			visited[a_][b_] = true;
			q.push( {a_, b_} );
		}
		// dp
		dp[a_][b_] = max(dp[a_][b_], x_); // max,min, +, - 

		/*____________ next states by FOR ______________*/
		FOR(i_,1,N+1) {
			x_ =   ;
			// check visited
			if(!visited[a_][i_]) {
				visited[a_][i_] = true;
				q.push({a_,i_});
			}
			// dp
			dp[a_][i_] = max(dp[a_][i_], x_) // max,min, +, - 
		}
	}

	//Check and return value
	return dp[][];
}

