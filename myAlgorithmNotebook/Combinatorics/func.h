
/*------------------------------------- Factorial ---------------------------------------------------------------*/
inline double factorial(int x) {
	if (x == 0 || x == 1)
		return 1;

	double res = 1;
	for (int i = 2; i < x + 1; ++i)
		res *= i;
	return res;
}

/*------------------------------------- Combination ---------------------------------------------------------------*/
inline double combination(int n, int r) {
	return factorial(n) / factorial(r) / factorial(n - r);
}

double Com[101][101];
inline double combination(int n, int r) {
	Com[0][0] = 1;
	for (int i = 0; i < n + 1; ++i) {
		Com[0][i] = 1;
		Com[i][i] = 1;
	}

	for (int i = 1; i < r + 1; ++i)
		for (int j = 1; j < n + 1; ++j)
			Com[i][j] = Com[i - 1][j - 1] + Com[i][j - 1];

	return Com[r][n];
}

/*------------------------------------- Permutation ---------------------------------------------------------------*/
inline double permutation(int n, int r) {
	return factorial(n) / factorial(n - r);
}

inline double permutation(int n, int r) {
	if (r == 0)
		return 1;
	double res = 1;
	for (int i = n - r + 1; i < n + 1; ++i)
		res *= i;
	return res;
}
