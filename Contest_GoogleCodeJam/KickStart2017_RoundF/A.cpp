
// https://codejam.withgoogle.com/codejam/contest/7254486/dashboard

const int MAXN = 1e4 + 3;

int N;
vi a;
ll readInput() {
    a.clear();

    si(N);
    int i;
    REP(N) {
        si(i);
        a.pb(i);
    }
    
    return 0;
}


pii getMid(const vi &a) {
    return {(int)floor( (sz(a) - 1) / 2), a[(int)floor( (sz(a)-1) / 2)]};
}

bool sol() {
    vi aSort(a);
    sort(all(aSort));

    while(sz(aSort) > 0) {
        int m = getMid(a).fi;
        int M = getMid(a).se;

        if(M == aSort[0]) {
            aSort.erase(aSort.begin());
            a.erase(a.begin() + m);
        }
        else if(M == aSort[sz(aSort)-1]) {
            aSort.pop_back();
            a.erase(a.begin() + m);
        }
        else
            return false;
    }   
    return true;
}


void solve(unsigned long long t) {
    if(sol())
        printf("Case #%llu: YES\n", t);
    else
        printf("Case #%llu: NO\n", t);
}
