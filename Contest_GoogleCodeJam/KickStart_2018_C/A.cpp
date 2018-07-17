
// https://codejam.withgoogle.com/codejam/contest/4384486/dashboard#s=p0

const int MAXN = 1000 + 3;

int N;
vector<int> e[MAXN];
void readInput() {
    si(N);

    FOR(n,1,N+1)
        e[n].clear();

    int v, u;
    REP(N) {
        sii(v,u);
        e[v].pb(u), e[u].pb(v);
    }
}

vi travel;
int start_;
bool visited[MAXN];
bool done;
void explore(int v, int pre) {
    visited[v] = true;

    if(!done)
        travel.pb(v);

    FOR(i,0,sz(e[v])) {
        if(visited[e[v][i]] and e[v][i] != pre and !done) {
            travel.pb(e[v][i]);
            start_ = e[v][i];
            done = true;
        }
    }

    FOR(i,0,sz(e[v])) {
        if(!visited[e[v][i]])
            explore(e[v][i], v);
    }

    if(!done) 
        travel.pop_back();
}

set<int> cycle;
int res[MAXN];
bool visited_[MAXN];
void bfs(int s) {
    ms(visited_, false);
    visited_[s] = true;

    queue<pii> q;
    q.push({s,-1});

    while (!q.empty()) {
        int v = q.front().fi;
        int pre = q.front().se;
        q.pop();

        //process v
        auto it = cycle.find(v);
        if(it == cycle.end()) {
            res[v] = res[pre] + 1;
        }

        FOR(i,0,sz(e[v]))
            if (!visited_[e[v][i]]) {
                visited_[e[v][i]] = true;
                q.push({e[v][i],v});
            }
    }
}

int sol() {
    ms(res, 0);
    cycle.clear();
    travel.clear();

    // dfs travel
    ms(visited, false);
    done = false;
    explore(1,-1);

    // detect cycle
    bool inCycle = false;
    FOR(i,0,sz(travel)) {
        if(travel[i] == start_)
            inCycle = !inCycle;

        if(inCycle)
            cycle.insert(travel[i]);
    }

    // bfs to find distance
    bfs(start_);
    
    return 0;
}


void solve(unsigned long long fdfsfv_t) {
    sol();
    printf("Case #%llu:", fdfsfv_t);
    FOR(i,1,N+1) 
        printf(" %lld", res[i]);
    printf("\n");
}
