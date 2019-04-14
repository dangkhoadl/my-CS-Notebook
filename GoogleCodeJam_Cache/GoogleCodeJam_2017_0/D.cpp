
// https://codejam.withgoogle.com/codejam/contest/3264486/dashboard#s=p3

const int MAXN = 100 + 3;

int N, M;
vector<pair<char, pii>> data;
ll readInput() {
    data.clear();
    sii(N,M);
    REP(M) {
        char sign, newline;
        int x,y;
        sc(newline);
        sc(sign);
        sii(x,y);
        data.pb({sign,{x,y}});
    }
    return 0;
}

class DinicFlow {
private:
    static const int INF = (int)1e9 + 7;
    int n, m;
    vector<int> dist, head, work;
    vector<int> point, flow, capa, next_;
    vector<vector<int>> edges;


    int bfs(int s, int t) {
        for(int i=1; i<=n; ++i) this->dist[i] = -1;
        queue<int> q;
        this->dist[s] = 0; q.push(s);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = this->head[u]; i >= 0; i = this->next_[i])
                if (this->dist[this->point[i]] < 0 && this->flow[i] < this->capa[i]) {
                    this->dist[this->point[i]] = this->dist[u] + 1;
                    q.push(this->point[i]);
                }
        }

        return this->dist[t] >= 0;
    }
    int dfs(int s, int t, int f = INF) {
        if (s == t) return f;
        for (int &i = this->work[s]; i >= 0; i = this->next_[i])
            if (this->dist[this->point[i]] == this->dist[s] + 1 && this->flow[i] < this->capa[i]) {
                int d = this->dfs(this->point[i], t, min(f, this->capa[i] - this->flow[i]));
                if (d > 0) {
                    this->flow[i] += d;
                    this->flow[i ^ 1] -= d;
                    return d;
                }
            }
        return 0;
    }
public:
    DinicFlow(int n = 0) {
        this->n = n;
        this->m = 0;
        this->dist.assign(n + 7, 0);
        this->head.assign(n + 7, -1);
        this->work.assign(n + 7, 0);
        this->edges.assign(n + 7, vector<int>(n + 7, -1));
    }

    int addEdge(int u, int v, int c1, int c2 = 0) {
        int res = m;
        this->point.push_back(v); this->capa.push_back(c1); this->flow.push_back(0); this->next_.push_back(this->head[u]); this->head[u] = this->m++;
        this->point.push_back(u); this->capa.push_back(c2); this->flow.push_back(0); this->next_.push_back(this->head[v]); this->head[v] = this->m++;
        this->edges[u][v] = res;
        return res;
    }

    int maxFlow(int s, int t) {
        int totFlow = 0;
        while (this->bfs(s, t)) {
            for(int i=1; i<=n; ++i) this->work[i] = this->head[i];
            while (true) {
                int d = this->dfs(s, t);
                if (d == 0) break;
                totFlow += d;
            }
        }
        return totFlow;
    }

    int checkFlow(int u, int v) const {
        return this->flow[this->edges[u][v]];
    }
};

char board[MAXN][MAXN];

bool row[MAXN], col[MAXN], oldCross[MAXN][MAXN];
bool newCross[MAXN][MAXN];
int solve_Cross() {
    ms(row, false);
    ms(col, false);
    ms(oldCross, false);
    ms(newCross, false);

    int points = 0;

    // mark old signs
    FOR(x,1,N+1) FOR(y,1,N+1) {
        if(board[x][y] == 'x' || board[x][y] == 'o') {
            ++points;
            row[x] = true;
            col[y] = true;
            oldCross[x][y] = true;
        }
    }

    // BiGraph: row - col
    DinicFlow Flow(2*N + 2);
    int src = 2*N + 1;
    int snk = 2*N + 2;

    // Connect src -> rows
    FOR(x, 1, N+1) if (!row[x]) 
        Flow.addEdge(src, x, 1);

    // Connect cols -> snk
    FOR(y, 1, N+1) if (!col[y]) 
        Flow.addEdge(y+N, snk, 1);

    // Connect rows -> cols
    FOR(x,1,N+1) FOR(y,1,N+1) if(!oldCross[x][y]) {
        Flow.addEdge(x, N+y, 1);
    }

    // maximum matching
    points += Flow.maxFlow(src, snk);
    FOR(x,1,N+1) FOR(y,1,N+1) if(!oldCross[x][y] && Flow.checkFlow(x,N+y))
        newCross[x][y] = true;

    return points;
}

// Number of 1 side diag = 2*N - 1
//      main diag(/) = x + y -1
//      sub diag(\) = x + N - y
bool mainDiag[2*MAXN], subDiag[2*MAXN], oldPlus[MAXN][MAXN];
bool newPlus[MAXN][MAXN];
int solve_Plus() {
    ms(mainDiag, false);
    ms(subDiag, false);
    ms(oldPlus, false);
    ms(newPlus, false);

    int points = 0;

    // mark mark old signs
    FOR(x,1,N+1) FOR(y,1,N+1) {
        if(board[x][y] == '+' || board[x][y] == 'o') {
            ++points;
            mainDiag[x+y-1] = true;
            subDiag[x+N-y] = true;
            oldPlus[x][y] = true;
        }
    }

    int diagNum = 2*N - 1;

    // BiGraph: mainDiag - subDiag
    DinicFlow Flow(2*diagNum + 2);
    int src = 2*diagNum + 1;
    int snk = 2*diagNum + 2;

    // Connect src -> mainDiags
    FOR(d1, 1, diagNum+1) if (!mainDiag[d1]) 
        Flow.addEdge(src, d1, 1);

    // Connect subDiags -> snk
    FOR(d2, 1, diagNum+1) if (!subDiag[d2]) 
        Flow.addEdge(diagNum + d2, snk, 1);

    // Connect rows -> cols
    FOR(x,1,N+1) FOR(y,1,N+1) if(!oldPlus[x][y]) {
        Flow.addEdge(x+y-1, diagNum + x+N-y, 1);
    }

    // maximum matching
    points += Flow.maxFlow(src, snk);
    FOR(x,1,N+1) FOR(y,1,N+1) if(!oldPlus[x][y] && Flow.checkFlow(x+y-1, diagNum + x+N-y))
        newPlus[x][y] = true;

    return points;
}

vii Plusses;
vii Crosses;
vii Ows;
int sol() {
    ms(board, '.');

    Plusses.clear();
    Crosses.clear();
    Ows.clear();

    // Prepare the board
    FOR(i,0,sz(data)) {
        char s = data[i].fi;
        int x = data[i].se.fi;
        int y = data[i].se.se;
        board[x][y] = s;
    }

    // Solve 2 cases then Update new Signs added
    int points = solve_Cross() + solve_Plus();
    FOR(x,1,N+1) FOR(y,1,N+1) {
        if(board[x][y] != 'o' && (oldPlus[x][y]||newPlus[x][y]) && (oldCross[x][y]||newCross[x][y]))
            Ows.pb({x,y});
        else if(newPlus[x][y])
            Plusses.pb({x,y});
        else if(newCross[x][y])
            Crosses.pb({x,y});
    }
    return points;
}


void solve(unsigned long long t) {
    int points = sol();
    int totals = sz(Ows) + sz(Crosses) + sz(Plusses);
    printf("Case #%llu: %lld %lld\n", t, points, totals);
    FOR(i,0,sz(Ows)) 
        printf("%c %lld %lld\n", 'o', Ows[i].fi, Ows[i].se);
    FOR(i,0,sz(Plusses)) 
        printf("%c %lld %lld\n", '+', Plusses[i].fi, Plusses[i].se);
    FOR(i,0,sz(Crosses)) 
        printf("%c %lld %lld\n", 'x', Crosses[i].fi, Crosses[i].se);
}
