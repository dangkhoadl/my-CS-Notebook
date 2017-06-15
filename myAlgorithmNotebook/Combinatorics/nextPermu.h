
/******************************************** Implementation 1 ****************************************************************/
//Find next Permu of a string lexicographically
// Ex: 123 -> 132 -> 213 -> 231 -> 312 -> 321
void nextP(string &s) {
	int r = s.size() - 1;
	for (int index = r - 1; index >= 0; --index) {
		// [index + 1, r] = decreasing sequence
		if (s[index] >= s[index + 1])
			continue;

		//Swap s[index] with the s[temp]: smallest letter in the [index + 1, r] but s[temp] > s[index]: Can use bin search !!!
		int temp = index + 1;
		for (int i = index + 1; i <= r; ++i)
			if (s[i] < s[temp] && s[i] > s[index])
				temp = i;
		swap(s[index], s[temp]);

		//Reorder [index + 1, r] into increasing sequence
		int l = index + 1;
		while (l < r) {
			swap(s[r], s[l]);
			++l;
			--r;
		}

		break;
	}
}

/******************************************** Implementation 2 ****************************************************************/
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
