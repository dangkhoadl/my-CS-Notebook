
// bfs + DP template

bool visited[][];
int dp[][];
int bfs() {
	// Reset 
	ms(visited, false);
	ms(dp, ); //0x7f, -0x7f, -1, 0

	// Init 1st stage
	queue<pii> q;
	q.push( { 0,0 } );
	visited[0][0] = true;
	dp[0][0] = ;
	while(!q.empty()) {
		// current state
		int a = q.front().fi;
		int b = q.front().se;
		int x = dp[a][b];
		q.pop();

		//Process current state


		/*____________ next states ______________*/
		int a_,b_,x_;

		// next state i
		a_ =  ;
		b_ =  ;
		x_ =  ;

		// check visited
		if(!visited[a_][b_] and a_ <= A and b_ <= B) {
			visited[a_][b_] = true;
			q.push( {a_, b_} );
		}
		// dp
		dp[a_][b_] = max(dp[a_][b_], x_); // Only optimization problem (max,min) 

		/*____________ next states by FOR ______________*/
		FOR(i_,1,N+1) {
			a_ =  ;
			b_ =  ;
			x_ =   ;

			// check visited and Stop, Bounding condition
			if(!visited[a_][i_] and a_ <= A and b_ <= B) {
				visited[a_][i_] = true;
				q.push({a_,i_});
			}
			// dp
			dp[a_][i_] = max(dp[a_][i_], x_) // Only optimization problem (max,min)  
		}
	}

	//Check and return value
	FOR()
		res = max(res, );
	return dp[][];
}

