
// https://codejam.withgoogle.com/codejam/contest/3264486/dashboard#s=p2

const int MAXN = 1e18 + 3;

int N, K;
ll readInput() {
    sii(N,K);
    
    return 0;
}

pii getval(int n) {
    int a, b;
    if(n % 2 == 0) {
        a = n / 2;
        b = a - 1; 
    }
    else {
        a = b = (n-1) / 2;
    }
    return {a,b};
}

pii sol() {
    priority_queue<int> PQ;
    unordered_map<int, int> cnt;

    PQ.push(N);
    cnt[N] = 1;

    pii ab;
    int k = K;
    while(k>0) {
        int num = PQ.top(); PQ.pop();

        k -= cnt[num];
        ab = getval(num);

        auto it = cnt.find(ab.fi);
        if(it == cnt.end()) {
            PQ.push(ab.fi);
            cnt[ab.fi] = cnt[num];
        }
        else
            cnt[ab.fi] += cnt[num];

        it = cnt.find(ab.se);
        if(it == cnt.end()) {
            PQ.push(ab.se);
            cnt[ab.se] = cnt[num];
        }
        else
            cnt[ab.se] += cnt[num];
    }
    return ab;
}


void solve(unsigned long long t) {
    pii res = sol();
    printf("Case #%llu: %lld %lld\n", t, res.fi, res.se);
}
