
/*------------------------------------- Factorial ---------------------------------------------------------------*/
inline double f(int x) {
	if(x == 0 || x == 1)
		return 1;

	double f_ = 1.0;
	double f = 1.0;
	for (int i = 2; i < x + 1; ++i) {
		f = f_ * i;
		f_ = f;
	}
	return f;
}

/*------------------------------------- Combination ---------------------------------------------------------------*/
inline int C(int n, int r) {
	return f(n) / f(r) / f(n - r);
}

inline double C(int n, int r) {
	vector<vector<int>> Com(101, vector<int>(101));

	Com[0][0] = 1;
	for(int i = 0; i < n+1; ++i) {
		Com[0][i] = 1;
		Com[i][i] = 1;
	}

	for(int i = 1; i < r+1; ++i) 
		for(int j = 1; j < n+1; ++j) 
			Com[i][j] = Com[i-1][j-1] + Com[i][j-1]; 
		
	return Com[r][n];
}

/*------------------------------------- Permutation ---------------------------------------------------------------*/
inline int P(int n, int r) {
	return f(n) / f(n - r);
}
