// Set : s = {0,1,2}
// 		All subsets (2^n): 	NULL, {0}, {1}, {2}, {0,1}, {0,2}, {1,2}, {0,1,2}
// 		All permu (n!):		{0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0}
//		C(n,2):				{1,2}, {0,2}, {0,1}
//		P(n,2):				{1,2}, {2,1}, {0,2}, {2,0}, {0,1}, {1,0}


/*_____________________________________________________________________________________ Complete search by recursion O(2^n )_____________________________________________________________________________________*/
// Set = {0,1,2,3, ..., n-1}
// call func by search(0,n)
vector<int> subset;
void search(int i, int n) {
	if(i == n) {
		//Process subset

	}
	else {
		search(i + 1, n);
		subset.push_back(i);
		search(i + 1, n);
		subset.pop_back();
	}
}
/*_________________________________ Example print all subsets of a vector __________________________*/
// Call search(0,n)
vector<int> a = {8,5,4,3,2};

vector<int> subset;
void search(int i, int n) {
	if (i == n) {
		// process subset
		for (int j = 0; j < subset.size(); ++j)
			cout << a[subset[j]] << ' ';
		cout << endl;
	}
	else {
		search(i + 1, n);
		subset.push_back(i);
		search(i + 1, n);
		subset.pop_back();
	}
}
/*_________________________________ Example print all C(n,k) of a vector __________________________*/
// Call search(0,n,k)
vector<int> a = {8,5,4,3,2};

vector<int> subset;
void search(int i, int n, int k) {
	if (i == n) {
		// process subset
		if (subset.size() == k) {
			for (int j = 0; j < subset.size(); ++j)
				cout << a[subset[j]] << ' ';
			cout << endl;
		}
	}
	else {
		search(i + 1, n, k);
		subset.push_back(i);
		search(i + 1, n, k);
		subset.pop_back();
	}
}

/*_____________________________________________________________________________________ Complete search through all Permu _____________________________________________________________________________________*/
// Set = {0,1,2,3, ..., n-1}
// call func by search(n)
vector<int> permu;
bool chosen[100];
void search(int n) {
	if (permu.size() == n) {
		// process permutation

	}
	else {
		for (int i = 0; i < n; i++) {
			if (chosen[i]) 
				continue;
			chosen[i] = true;
			permu.push_back(i);
			search(n);
			chosen[i] = false;
			permu.pop_back();
		}
	}
}
/*_________________________________ Example print all P of a string __________________________*/
// Call search(n)
string a = "ABC";

vector<int> permu;
bool chosen[100];
void search(int n) {
	if (permu.size() == n) {
		// process permutation
		for(int j=0; j < permu.size(); ++j)
			cout << a[permu[j]] << ' ';
		cout << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (chosen[i]) 
				continue;
			chosen[i] = true;
			permu.push_back(i);
			search(n);
			chosen[i] = false;
			permu.pop_back();
		}
	}
}
/*_________________________________ Example print all P(n,k) of a string __________________________*/
// Call search(n,k)
string a = "ABCD";

vector<int> permu;
bool chosen[100];
void search(int n,int k) {
	if (permu.size() == k) {
		// process permutation
		for(int j=0; j < permu.size(); ++j)
			cout << a[permu[j]] << ' ';
		cout << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (chosen[i]) 
				continue;
			chosen[i] = true;
			permu.push_back(i);
			search(n, k);
			chosen[i] = false;
			permu.pop_back();
		}
	}
}

/*_____________________________________________________________________________________ C++ builtin Permu _____________________________________________________________________________________*/
vector<int> permu;
void search(int n) {
	for (int i = 0; i < n; i++) {
		permu.push_back(i);
	}
	do {
		// process permutation
		
	} while (next_permutation(permu.begin(), permu.end()));
}
/*_________________________________ Example print all P of a string __________________________*/
string a = "CAB";

vector<int> permu;
void search(int n) {
	for (int i = 0; i < n; i++) {
		permu.push_back(i);
	}
	do {
		// process permutation
		for(int j=0; j < permu.size(); ++j)
			cout << a[permu[j]] << ' ';
		cout << endl;
	} while (next_permutation(permu.begin(), permu.end()));
}

/*_____________________________________________________________________________________ Complete search by bit manipulation _____________________________________________________________________________________*/
// Set = {0,1,2,3, ..., n-1}
//	Number of Subset = C(0,n) + C(1,n) + ... + C(n,n) = (1+1)^n = 2^n = (1 << n)
#define isOn(S, k) (S & (1 << k))
void printAllSubset(int n) {
	for (int x = 0; x < (1 << n); ++x) {
		for (int i = 0; i < n; ++i) {
			if (isOn(x,i)) {
				// Process subset

			}
		}
	}
}

/*_________________________________ Example print all subsets of a vector __________________________*/
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

/*_________________________________ Example print all C(n,k) of a vector __________________________*/
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
