
vector<int> z;
void buildZarray(const string &s) {
	int n = s.size();
	z.resize(n,0);
	int x = 0, y = 0;
	for(int i = 1; i < n; ++i) {
		z[i] = max((int)0, min(z[i-x], y - i + 1));
		while(i + z[i] < n && s[z[i]] == s[i+z[i]]) {
			x = i;
			y = i + z[i];
			++z[i];
		}
	}
}
vector<int>res;
void patternMatching(const string &s, const string &p) {
	string temp = p + '#' + s;
	buildZarray(temp);
	for (int i = 0; i < z.size(); ++i) {
		if (z[i] == p.size())
			res.push_back(i - p.size() - 1);
	}
}