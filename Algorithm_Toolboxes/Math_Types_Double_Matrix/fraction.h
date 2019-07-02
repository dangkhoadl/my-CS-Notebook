int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
int lcm(int a, int b) {
	return b*a / gcd(a, b);
}
void reduceFraction(pair<int, int> &a) {
	int b = gcd(a.first, a.second);
	a.first /= b;
	a.second /= b;
}

// +,-,*,/
pair<int, int> addFractions(const pair<int, int> &a, const pair<int, int> &b) {
	int denom = lcm(a.second, b.second);
	pair<int, int> c = { denom / a.second * a.first + denom / b.second * b.first, denom };
	reduceFraction(c);
	return c;
}
pair<int, int> subFractions(const pair<int, int> &a, const pair<int, int> &b) {
	int denom = lcm(a.second, b.second);
	pair<int, int> c = { denom / a.second * a.first - denom / b.second * b.first, denom };
	reduceFraction(c);
	return c;
}
pair<int, int> multiplyFractions(const pair<int, int> &a, const pair<int, int> &b) {
	pair<int, int> c = { a.first * b.first, a.second * b.second };
	reduceFraction(c);
	return c;
}
pair<int, int> divideFractions(const pair<int, int> &a, const pair<int, int> &b) {
	pair<int, int> c = { a.first * b.second, a.second * b.first };
	reduceFraction(c);
	return c;
}
