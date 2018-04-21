

/*
    O(E*V^2)
    // vertex_id start by 1
*/
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

int F,C;
int G[MAXV][MAXV];
void maximumMatching() {
    int src = F + C + 1;
    int snk = F + C + 2;
    DinicFlow Flow(F+C+2);

    // Connect source -> F
    for(int f=1; f<=F; ++f) {
        Flow.addEdge(src, f, 1);
    }

    // Connect C -> sink
    for(int c=1; c<=C; ++c) {
        Flow.addEdge(F+c, snk, 1);
    }

    // Connect F -> C
    for(int f=1; f<=F; ++f) for(int c=1; c<=C; ++c){
        if(G[f][c] == 1)
            Flow.addEdge(f, F+c, 1);
    }

    // Find Maximum matching
    Flow.maxFlow(src, snk);
    for(int f=1; f<=F; ++f) for(int c=1; c<=C; ++c) {
        if(Flow.checkFlow(f,F+c) == 1)
            cout << f << " matches " << c << endl; 
    }
}
