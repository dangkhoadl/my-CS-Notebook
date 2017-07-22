// Set : s = {0,1,2}
//        All subsets (2^n):     NULL, {0}, {1}, {2}, {0,1}, {0,2}, {1,2}, {0,1,2}
//        All permu (n!):        {0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0}
//        C(n,2):                {1,2}, {0,2}, {0,1}
//        P(n,2):                {1,2}, {2,1}, {0,2}, {2,0}, {0,1}, {1,0}

/*_____________________________________________________________________________________ Complete search through all Permu _____________________________________________________________________________________*/
// Set = {0,1,2,3, ..., n-1}
// call func by search(n), permu index = 0
vector<int> permu;
bool chosen[100];
void search(int n) {
    if (permu.size() == n) {
        // process permutation
        for(int i = 0; i < permu.size(); ++i) {
            
        }
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
// Set = {1,2,3,..,n}
// call func by search(n), permu idex start w/ 1
vector<int> permu(1,0);
bool chosen[100];
void search(int n) {
    if (permu.size() == n+1) {
        // process permutation
        for(int i = 1; i < permu.size(); ++i) {
            
        }
    }
    else {
        for (int i = 1; i <= n; ++i) {
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
// set = {0,1,2,...,n-1}
//Permu start w/ 0
vector<int> permu;
void search(int n) {
    for (int i = 0; i < n; i++)
        permu.push_back(i);
    do {
        // process permutation
        for(int j=0; j < permu.size(); ++j) {

        }
    } while (next_permutation(permu.begin(), permu.end()));
}
// set = {1,2,...,n}
//Permu start w/ 1
vector<int> permu;
void search(int n) {
    permu.clear();
    permu.resize(1);
    for (int i = 1; i <= n; ++i)
        permu.push_back(i);
    do {
        // process permutation
        for(int j=1; j < permu.size(); ++j) {
            
        }
    } while (next_permutation(permu.begin()+1, permu.end()));
}
/*_________________________________ Example print all P of a string __________________________*/
string a = "CAB";

vector<int> permu;
void search(int n) {
    for (int i = 0; i < n; i++)
        permu.push_back(i);
    do {
        // process permutation
        for(int j=0; j < permu.size(); ++j)
            cout << a[permu[j]] << ' ';
        cout << endl;
    } while (next_permutation(permu.begin(), permu.end()));
}
