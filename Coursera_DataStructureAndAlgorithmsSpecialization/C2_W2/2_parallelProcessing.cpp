
// 2 Problem: Parallel processing

const int MAXN = 1e5 + 3;

int T, J;
int P[MAXN];
ll readInput() {
    sii(T, J);
    FOR(j,0,J)
        si(P[j]);
    
    return 0;
}


int startTime[MAXN];
int thread[MAXN];
void sol() {
    priority_queue<pii> PQ;

    FOR(t,0,T) {
        startTime[t] = 0;
        thread[t] = t;
        PQ.push({-P[t], -t});
    }

    FOR(j,T,J) {
        int time = -PQ.top().fi;
        int thre = -PQ.top().se;
        PQ.pop();

        startTime[j] = time;
        thread[j] = thre;
        PQ.push({-(time + P[j]), -thre});
    }
}


ll solve() {
    sol();
    FOR(j,0,J)
        cout << thread[j] << ' ' << startTime[j] << endl;
    
    return 0;
}
