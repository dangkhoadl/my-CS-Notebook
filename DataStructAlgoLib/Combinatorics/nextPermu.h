//Find next Permu of a string lexicographically
// Ex: 123 -> 132 -> 213 -> 231 -> 312 -> 321
// Care nextP("321") ----> Error
void nextP(string &a) {
	int n = a.size() - 1;
	
	//Find j = largest subscript with a[j] < a[j + 1]
	int j = n - 1;
	while(a[j] > a[j+1])
		--j;

	// Find k = a[k] is smallest element that > a[j] and to the right of a[j] 
	int k = n;
	while(a[j] > a[k])
		--k;
	swap(a[j], a[k]);

	//Keep the tail end of the Permutation after jth pos in an increasing order
	int r = n;
	int s = j + 1;
	while(r > s) {
		swap(a[r], a[s]);
		--r;
		++s;
	}
}

/************************************************************************************************************/
// Print all Permu of a string using nextP
inline int f(int x) {
	return (x == 1 || x == 0) ? 1 : x * f(x - 1);
}
inline int P(int n, int r) {
	return f(n) / f(n - r);
}
void printAllPermu(string &s) {
	sort(s.begin(), s.end());

	cout << s << endl;
	int p = P(s.size(), s.size());
	for(int i=0; i < p - 1; ++i) {
		nextP(s);
		cout << s << endl;
	}
} 
