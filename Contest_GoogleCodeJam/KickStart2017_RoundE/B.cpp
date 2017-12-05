
// https://codejam.withgoogle.com/codejam/contest/12234486/dashboard#s=p1&a=1

const int MAXN = 5000 + 3;

int N;
int L[MAXN];
ll readInput() {
    si(N);
    FOR(n,1,N+1)
        si(L[n]);
    return 0;
}

int Com[MAXN][MAXN];
int nCk(int n, int k) {
    assert(n>=k);
    return Com[k][n];
}
void buildCombination(int n, int k) {
    Com[0][0] = 1.0;
    for (int i = 0; i < n + 1; ++i) {
        Com[0][i] = 1.0;
        Com[i][i] = 1.0;
    }

    for (int i = 1; i < k + 1; ++i)
        for (int j = 1; j < n + 1; ++j)
            Com[i][j] = Com[i - 1][j - 1] + Com[i][j - 1];
}

int binSearchLow(const vector<int> &a, int x, int l, int r) {
    while (true) {
        if (l > r) {
            return l-1;
        }

        int m = l + (r-l)/2;
        if (a[m] == x)              // condition
            return m;

        if (x > a[m])               // condition
            l = m + 1;
        else
            r = m - 1;
    }
}
int binSearchUp(const vector<int> &a, int x, int l, int r) {
    while (true) {
        if (l > r) {
            return l;
        }

        int m = l + (r-l)/2;
        if (a[m] == x)              // condition
            return m;

        if (x > a[m])               // condition
            l = m + 1;
        else
            r = m - 1;
    }
}


int randInt(int a, int b) {
    random_device r;
    default_random_engine e1(r());
    uniform_int_distribution<int> uniform_dist(a, b-1);
    return uniform_dist(e1);
}
int partition(vector<int> &a, vector<int> &b, int left, int right) { // Add vectors
    int p = randInt(left, right+1);

    // Swap
    swap(a[left], a[p]);
    swap(b[left], b[p]);

    int pivot = a[left];

    int i = left + 1;
    int j = left + 1;
    for( ; i <= right; ++i) {
        if(a[i] <= pivot) {         // Conditions
            // Swap
            swap(a[i], a[j]);
            swap(b[i], b[j]);
            ++j;
        }
    }

    --j;
    // Swap
    swap(a[left], a[j]);
    swap(b[left], b[j]);
    return j;
}
void quicksort(vector<int> &a, vector<int> &b, int left, int right) { // Add vectors
    stack<int> S;
    S.push(left);
    S.push(right);

    while(!S.empty()) {
        // Pop h and l
        right = S.top(); S.pop();
        left = S.top(); S.pop();
 
        int p = partition(a,b,left,right);      // Add vectors

        if(p-1 > left) {
            S.push(left);
            S.push(p-1);
        }
 
        if (p+1 < right) {
            S.push(p+1);
            S.push(right);
        }
    }
}

// Trapezoid: 
//      2A + B > C
//      B != C
vi len;
vi cnt;
vi preSum;
int sol() {
    len.clear();
    cnt.clear();
    preSum.clear();

    // Build Combinations
    buildCombination(5000, 3);

    // Build count
    unordered_map<int,int> getIndx;
    FOR(n,1,N+1) {
        auto it = getIndx.find(L[n]);
        if(it == getIndx.end()) {
            getIndx.insert( {L[n], sz(len)} );
            len.pb(L[n]);
            cnt.pb(1);
            preSum.pb(0);
        }
        else {
            ++cnt[getIndx[L[n]]];
        }
    }

    // Sort
    quicksort(len,cnt,0,sz(len)-1);

    // Build prefix sum
    int sum_ = 0;
    FOR(i,0,sz(cnt)) {
        sum_ += cnt[i];
        preSum[i] = sum_;
    }

    /* ----- Case: AAAC----- */
    int res1 = 0;
    FOR(a,0,sz(len)) {
        if(cnt[a] >= 3) {
            int indx = binSearchLow(len, 3 * len[a] - 1, 0, sz(len)-1);
            res1 += (preSum[indx] - cnt[a]) * nCk(cnt[a], 3);
        }
    }


    /* ----- Case: ABAC ----- */
    int res2 = 0;
    FOR(a,0,sz(len)) {
        if(cnt[a] >= 2) {
            FOR(b,0,sz(len)) {
                if(b == a)
                    continue;
                int indx1 = binSearchUp(len, len[b] + 1, 0, sz(len)-1);
                int indx2 = binSearchLow(len, 2 * len[a] + len[b] - 1, 0, sz(len)-1);

                if(indx1 > indx2)
                    continue;

                int aa = ( indx1 <= a and a <= indx2 ) ? cnt[a] : 0;
                res2 += (preSum[indx2] - preSum[indx1-1] - aa) * cnt[b] * nCk(cnt[a], 2);
            }
        }
    }
    return res1 + res2;
}


void solve(unsigned long long t) {
    printf("Case #%llu: %lld\n", t, sol());
}
