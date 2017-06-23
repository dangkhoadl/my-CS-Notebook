
// https://code.google.com/codejam/contest/12254486/dashboard#s=p1

int R,C,K;
int mat[MAXN][MAXN];
int dp[MAXN][MAXN];
int r,c;
ll readInput() {
	cin >> R >> C >> K;
	for_i(0,R,1)
		for_j(0,C,1) {
			mat[i][j] = 0;
			dp[i][j] = 0;
		}
	for_i(0,K,1) {
		cin >> r >> c;
		mat[r][c] = 1;
	}
	return 0;
}

int cnt;
ll solve() {
	cnt = 0;
	for_i(0,R,1) 
		if(mat[i][0] == 0) {
			dp[i][0] = 1;
			++cnt;
		}
	for_j(1,C,1)
		if(mat[0][j] == 0) {
			dp[0][j] = 1;
			++cnt;
		}
	//pr(cnt);
	for_i(1,R,1)
		for_j(1,C,1) 
			if(mat[i][j] == 0) {
				int temp = min(dp[i-1][j],dp[i][j-1]);
				dp[i][j] = min(temp, dp[i-1][j-1]) + 1;
				cnt += dp[i][j];
			}	
			else
				dp[i][j] = 0;

	return cnt;
}
