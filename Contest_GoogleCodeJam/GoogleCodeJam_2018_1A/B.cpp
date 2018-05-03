
// https://codejam.withgoogle.com/2018/challenges/0000000000007883/dashboard/000000000002fff6

const int MAXC = 1000 + 3;

int R,B,C;
int M[MAXC], S[MAXC], P[MAXC];
ll readInput() {
    siii(R,B,C);
    FOR(i,1,C+1) siii(M[i], S[i], P[i]);
    
    return 0;
}


int capacity(int i, int t) {
    return min(M[i], max(0ll, (t-P[i]) / S[i]));
}

bool ok(int t) {
    vi cap;
    FOR(i,1,C+1) cap.pb(capacity(i, t));
    sort(all(cap), DEC<int>);

    int total = 0;
    FOR(i,0,R) total += cap[i];

    return total >= B;
}

int sol() {
    int lo = 0;

    int hi = -1;
    FOR(i,1,C+1) hi = max(hi, S[i]*M[i] + P[i]);
    
    int res = -1;
    while(lo <= hi) {
        int T = (lo + hi) / 2;
        if(ok(T)) {
            res = T;
            hi = T - 1;
        }
        else
            lo = T + 1;
    }

    return res;
}


void solve(unsigned long long t) {
    
    printf("Case #%llu: %lld\n", t, sol());
    
}
