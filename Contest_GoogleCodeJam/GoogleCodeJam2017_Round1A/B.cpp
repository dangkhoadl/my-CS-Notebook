
// https://codejam.withgoogle.com/codejam/contest/5304486/dashboard#s=p1

const int MAXN = 50 + 3;

int N, P;
int R[MAXN];
int Q[MAXN][MAXN];
ll readInput() {
    sii(N,P);
    FOR(n,1,N+1)
        si(R[n]);
    FOR(n,1,N+1) FOR(p,1,P+1) {
        si(Q[n][p]);
    }
    
    return 0;
}


// Find x in range[a,b] such that 
//      S <= W*x <= E
// a,b,S,W,E: int
bool findRange(int S, int W, int E, pair<int,int> &res) {
    assert(S <= E);
    int a = S/W+1;
    while(S <= W*a) --a;
    ++a;

    int b = E/W-1;
    while(W*b <= E) ++b;
    --b;

    if(a > b)
        return false;

    res = {a,b};
    return true;
}

// Greedy by Priority queue. If use vector<pair<int,int>> and sort 2 times for first and second --> Must use stable sort
//     sort(first)
//     stable_sort(second)
priority_queue<pii> Range[MAXN];
void cache() {
    FOR(n,1,N+1) {
        while(!Range[n].empty()) Range[n].pop();
    }

    FOR(n,1,N+1) FOR(p,1,P+1) {
        pii res = {-1,-2};
        if(findRange(90*Q[n][p], 99*R[n], 110*Q[n][p], res))
            Range[n].push({-res.fi,-res.se});
    }
}

int sol() {
    cache();

    int cnt = 0;
    while(1) {
        // Stop Condition: 1 PQ is empty
        FOR(n,1,N+1) {
            if(sz(Range[n]) == 0)
                return cnt;
        }

        // Check if all segment intersect
        int a = -inf;
        int b = inf;
        FOR(n,1,N+1) {
            a = max(a,-Range[n].top().fi);
            b = min(b,-Range[n].top().se);
        }

        // Case not all intersect --> Greedy: pop (the end that farthest to the left) 
        if(a>b) {
            FOR(n,1,N+1) {
                if(-Range[n].top().se == b)
                    Range[n].pop();
            }
        }
        // Case all match: form a kit and remove from the pool
        else {
            ++cnt;
            FOR(n,1,N+1) 
                Range[n].pop();
        }
    }
}

void solve(unsigned long long t) {
    printf("Case #%llu: %lld\n", t, sol());
}
