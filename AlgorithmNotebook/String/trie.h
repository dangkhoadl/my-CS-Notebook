
vector<map<char, int>> trie;
void constructTrie(const vector<string> &Ps) {
	trie.resize(1);
	for(int p = 0; p < Ps.size(); ++p) {
		int currNode = 0;
		for(int i = 0; i < Ps[p].size(); ++i) {
			char currChar = Ps[p][i];
			auto it = trie[currNode].find(currChar);
			if(it != trie[currNode].end())
				currNode = it->second;
			else {
				int newNode = trie.size();
				trie.resize(newNode + 1);
				trie[currNode].insert( {Ps[p][i], newNode} );
				currNode = newNode;
			}
		}
	}
}
bool prefixMatch(const string &s, int i) {
	int sym = s[i];
	int v = 0;
	while (true) {
		if (trie[v].empty())
			return true;
		auto it = trie[v].find(sym);
		if (it == trie[v].end())
			return false;

		sym = s[++i];
		v = it->second;
	}
}
vector<int> res;
void patternMatching(const string &s) {
	for (int i = 0; i < s.size(); ++i)
		if (prefixMatch(s, i))
			res.push_back(i);
}
