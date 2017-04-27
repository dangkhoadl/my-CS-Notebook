/********************************** Subset ********************************************************/
// Set = {0,1,2,3, ..., n-1}
//	Number of Subset = C(0,n) + C(1,n) + ... + C(n,n) = (1+1)^n = 2^n = (1 << n)
#define isOn(S, k) (S & (1 << k))
void printAllSubset(int n) {
	for (int x = 0; x < (1 << n); ++x) {
		for (int i = 0; i < n; ++i) {
			if (isOn(x,i))
				cout << i << ' ';
		}
		cout << endl;
	}
}
/*______________________________________________________________________________*/
// Print all subset of vector a 
//	Number of Subset = C(0,n) + C(1,n) + ... + C(n,n) = (1+1)^n = 2^n = (1 << n)
#define isOn(S, k) (S & (1 << k))
void printAllSubset(const vector<int> &a) {
	for (int x = 0; x < (1 << a.size()); ++x) {
		for (int i = 0; i < a.size(); ++i) {
			if (isOn(x,i))
				cout << a[i] << ' ';
		}
		cout << endl;
	}
}

/********************************** Combination ********************************************************/
// Set = {0,1,2,3, ..., n-1}
//  Number of Combination = C(k,n)
#define isOn(S, k) (S & (1 << k))
void printAllCombination(int n, int k) {
	for (int x = 0; x < (1 << n); ++x) {
		if (__builtin_popcount(x) == k) {
			for (int i = 0; i < n; ++i)
				if (isOn(x, i))
					cout << i << ' ';
			cout << endl;
		}
	}
}

// Print all Combination of array a
//  Number of Combination = C(k,n)
#define isOn(S, k) (S & (1 << k))
void printAllCombination(const vector<int> &a, int k) {
	for (int x = 0; x < (1 << a.size()); ++x) {
		if (__builtin_popcount(x) == k) {
			for (int i = 0; i < a.size(); ++i)
				if (isOn(x, i))
					cout << a[i] << ' ';
			cout << endl;
		}
	}
}
