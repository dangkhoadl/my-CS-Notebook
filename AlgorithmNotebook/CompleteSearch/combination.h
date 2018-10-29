// Set : s = {0,1,2}
//        All subsets (2^n):     NULL, {0}, {1}, {2}, {0,1}, {0,2}, {1,2}, {0,1,2}
//        All permu (n!):        {0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0}
//        C(n,2):                {1,2}, {0,2}, {0,1}
//        P(n,2):                {1,2}, {2,1}, {0,2}, {2,0}, {0,1}, {1,0}

/*_________________________________ Example print all C(n,k) of a vector __________________________*/
// Call search(0,n,k)
vector<int> a = {8,5,4,3,2};
vector<vector<int>> result;
vector<int> subset;
void search(int i, int n, int k) {
    if (i == n) {
        // process subset
        if (subset.size() == k) {
            vector<int> res;
            for (int j = 0; j < subset.size(); ++j)
                res.push_back(a[subset[j]]);
            result.push_back(res);
        }
    }
    else {
        search(i + 1, n, k);
        subset.push_back(i);
        search(i + 1, n, k);
        subset.pop_back();
    }
}

// Set = {0,1,2,3, ..., n-1}
//  Number of Combination = C(k,n)
vector<vector<int>> result;
#define isOn(S, k) (S & (1 << k))
void printAllCombination(int n, int k) {
    for (int x = 0; x < (1 << n); ++x) {
        if (__builtin_popcount(x) == k) {
            vector<int> res;
            for (int i = 0; i < n; ++i)
                if (isOn(x, i))
                    res.push_back(i);
            result.push_back(res);
        }
    }
}

// Print all Combination of array a
//  Number of Combination = C(k,n)
vector<int> a = {8,5,4,3,2};
vector<vector<int>> result;
#define isOn(S, k) (S & (1 << k))
void printAllCombination(int k) {
    for (int x = 0; x < (1 << a.size()); ++x) {
        if (__builtin_popcount(x) == k) {
            vector<int> res;
            for (int i = 0; i < a.size(); ++i)
                if (isOn(x, i))
                    res.push_back(a[i]);
            result.push_back(res);
        }
    }
}
