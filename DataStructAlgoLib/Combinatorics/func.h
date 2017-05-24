
inline int f(int x) {
	return (x == 1 || x == 0) ? 1 : x * f(x - 1);
}

inline int C(int n, int r) {
	return f(n) / f(r) / f(n - r);
}

inline int P(int n, int r) {
	return f(n) / f(n - r);
}
