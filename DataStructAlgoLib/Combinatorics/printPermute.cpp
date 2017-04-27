
/*------------------------------------- Print all permutation of a string ---------------------------------------------------------------*/
// permu ABC O(n*n!)
//
//	l = 0; i = 0
//	l = 1; i = 1
//	ABC
//	l = 1; i = 2
//	ACB
//	l = 0; i = 1
//	l = 1; i = 1
//	BAC
//	l = 1; i = 2
//	BCA
//	l = 0; i = 2
//	l = 1; i = 1
//	CAB
//	l = 1; i = 2
//	CBA
//
//	[l,r]
void permute(string s, int l, int r) {
	if (l == r) {
		cout << s << endl;
		return;
	}

	for (int i = l; i <= r; ++i) {
		swap(s[i], s[l]);
		permute(s, l + 1, r);
	}
}