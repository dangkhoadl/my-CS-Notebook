
// https://codejam.withgoogle.com/codejam/contest/3254486/dashboard#s=p1&a=1

const int MAXN = 100 + 3;

int N;
int R[MAXN];
int B[MAXN];
ll readInput() {
    si(N);   
    FOR(n,1,N+1)
        si(R[n]);
    FOR(n,1,N+1)
        si(B[n]);
    return 0;
}


vi e[MAXN];
vi wei[MAXN];
void buildGraph() {
    FOR(n,1,N+1) {
        e[n].clear();
        wei[n].clear();
    }

    FOR(u,1,N) {
        FOR(v,u+1,N+1) {
            e[u].pb(v);
            e[v].pb(u);

            wei[u].pb(min(R[u]^B[v], R[v]^B[u]));
            wei[v].pb(min(R[u]^B[v], R[v]^B[u]));
        }
    }
}

// Min Spanning tree
int cost[MAXN];
int pre[MAXN];
bool processed[MAXN];
void prim(int start) {
    memset(processed, false, sizeof(processed));
    memset(pre, 0, sizeof(pre));
    memset(cost, 0x7f, sizeof(cost));

    cost[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({ -cost[start], start });

    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();

        if (processed[v])
            continue;
        processed[v] = true;

        for (int i = 0; i < e[v].size(); ++i) {
            if (cost[e[v][i]] > wei[v][i] && !processed[e[v][i]]) {
                //Relax
                cost[e[v][i]] = wei[v][i];
                pre[e[v][i]] = v;

                //Update
                pq.push({ -cost[e[v][i]], e[v][i] });
            }
        }
    }
}

int sol() {
    buildGraph();
    prim(1);

    int total = 0;
    FOR(n,1,N+1)
        total += cost[n];
    return total;
}
