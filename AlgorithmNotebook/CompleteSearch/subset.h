// Set : s = {0,1,2}
//        All subsets (2^n):     NULL, {0}, {1}, {2}, {0,1}, {0,2}, {1,2}, {0,1,2}
//        All permu (n!):        {0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0}
//        C(n,2):                {1,2}, {0,2}, {0,1}
//        P(n,2):                {1,2}, {2,1}, {0,2}, {2,0}, {0,1}, {1,0}


// Set = {0,1,2,3, ..., n-1}
// subset index from 0
// call func by search(0,n)
vector<int> subset;
void search(int i, int n) {
    if(i == n) {
        //Process subset
        for(int i=0; i < subset.size(); ++i) {

        }
    }
    else {
        search(i + 1, n);
        subset.push_back(i);
        search(i + 1, n);
        subset.pop_back();
    }
}
// Set = {1,2,3, ..., n}
// subset index from 1
// call func by search(1,n)
vector<int> subset(1);
void search(int i, int n) {
    if(i == n+1) {
        //Process subset
        for(int i=1; i < subset.size(); ++i) {

        }
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


/*_________________________________ Example print all subsets of n-element Set __________________________*/
// Set = {0,1,2,3, ..., n-1}
//    Number of Subset = C(0,n) + C(1,n) + ... + C(n,n) = (1+1)^n = 2^n = (1 << n)
vector<set<int>> subsets;
#define isOn(S, k) (S & (1 << k))
void printAllSubset(int n) {
    for (int x = 0; x < (1 << n); ++x) {
        set<int> a;
        for (int i = 0; i < n; ++i) {
            if (isOn(x,i)) {
                a.insert(i);
            }
        }
        subsets.push_back(a);
    }
}

/*_________________________________ Example print all subsets of a vector __________________________*/
//    Number of Subset = C(0,n) + C(1,n) + ... + C(n,n) = (1+1)^n = 2^n = (1 << n)
vector<set<int>> subsets;
#define isOn(S, k) (S & (1 << k))
void printAllSubset(const vector<int> &a) {
    for (int x = 0; x < (1 << a.size()); ++x) {
        set<int> aa;
        for (int i = 0; i < a.size(); ++i) {
            if (isOn(x,i))
                aa.insert(a[i]);
        }
        subsets.push_back(aa);
    }
}
