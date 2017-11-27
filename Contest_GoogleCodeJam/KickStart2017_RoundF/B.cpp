
// https://codejam.withgoogle.com/codejam/contest/7254486/dashboard#s=p1&a=0

const int MAXN = 1e3 + 3;

int E,N;
vi S;
ll readInput() {
    sii(E,N);

    S.clear();
    int i;
    FOR(n,1,N+1) {
        si(i);
        S.pb(i);
    }
    
    return 0;
}


int sol() {
    sort(all(S));

    int H = 0;

    int d = 0;
    int r = sz(S) - 1;
    while(d <= r) {
        // Dance
        if(E > S[d]) {
            E -= S[d++];
            ++H;
        }
        // Recruit
        else if(H > 0 and (r-d) >= 2) {
            E += S[r--];
            --H;
        }
        // Truce All
        else 
            break;
    }
    return H;
}


void solve(unsigned long long t) {
    printf("Case #%llu: %lld\n", t, sol());
}
