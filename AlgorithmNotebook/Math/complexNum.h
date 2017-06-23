pair<int, int> addComplex(const pair<int, int> &a, const pair<int, int> &b) {
	return{a.first + b.first, a.second + b.second}; 
}

pair<int, int> multiplyComplex(const pair<int, int> &a, const pair<int, int> &b) {
	return{ a.first * b.first - a.second * b.second, a.first * b.second + a.second * b.first };
}