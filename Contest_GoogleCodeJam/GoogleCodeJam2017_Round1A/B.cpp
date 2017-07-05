
// https://codejam.withgoogle.com/codejam/contest/5304486/dashboard#s=p1

const int MAXN = 50 + 1;
int N,P;
int R[MAXN];
int Q[MAXN][MAXN];
ll readInput() {
    sii(N,P);
    FOR(n,1,N+1)
        si(R[n]);
    FOR(n,1,N+1)
        FOR(p,1,P+1)
            si(Q[n][p]);
    return 0;
}

pii findRange(int q, int r) {
    int a = q/r;
    while(10*q <= 11*a*r)
        --a;
    ++a;

    int b = q/r;
    while(9*r*b <= 10*q) 
        ++b;
    --b;

    if(a>b)
        return {-1,-1};
    return {a,b};
}
int res;
vii ab[MAXN];
void process() {
    res = 0;
    FOR(n,1,N+1) {
        ab[n].clear();
        FOR(p,1,P+1) {
            pii r = findRange(Q[n][p], R[n]);
            if(r.fi == -1)
                continue;
            ab[n].pb(r);
        }
    }

    if(N == 1) {
        res = sz(ab[1]);
        return;
    }
    FOR(n,1,N+1) {
        sort(all(ab[n]), [](pii i, pii j){return i.se>j.se;});
        stable_sort(all(ab[n]), [](pii i, pii j){return i.fi>j.fi;});
    }
    while(1) {
        FOR(n,1,N+1)
            if(sz(ab[n]) == 0)
                return;

        int a = -1;
        int b = inf;
        FOR(n,1,N+1) {
            a = max(a,ab[n].back().fi);
            b = min(b,ab[n].back().se);
        }
        if(a>b) {
            FOR(n,1,N+1)
                if(ab[n].back().se == b)
                    ab[n].pop_back();
        }
        else {
            FOR(n,1,N+1)
                ab[n].pop_back();
                ++res;
        }
    }
}

ll solve() {
    process();
    return res;
}
