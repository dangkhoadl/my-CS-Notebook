
//                                              shortest path by BellmanFord (Negative weight)
//      O(V*E)
// Note: for (int k = 0; k < V - 1; ++k): 
//              -> Repeat (V-1) times
//      for (int v = 1; v <= V; ++v)
//          for (int i = 0; i < e[v].size(); ++i)
//              -> Loop E times
//
//      - Works w/ neg weight edges
//      - Can detect neg weight cycle

const int MAXV = 100 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];


/*-------------- BellmanFord (with detect negative weight cycles) ---------*/
int dist[MAXV];
int pre[MAXV];
bool bellmanFord(int start) {
    memset(pre, 0, sizeof(pre));
    memset(dist, 0x7f, sizeof(dist));

    dist[start] = 0;
    
    for (int k = 0; k < V - 1; ++k)
        for (int v = 1; v <= V; ++v) 
            for (int i = 0; i < e[v].size(); ++i)
                if (dist[v] != inf && dist[e[v][i]] > dist[v] + wei[v][i]) {
                    dist[e[v][i]] = dist[v] + wei[v][i];
                    pre[e[v][i]] = v;
                }

    // detect neg cycle
    for (int v = 1; v <= V; ++v) 
        for (int i = 0; i < e[v].size(); ++i)
            if (dist[v] != inf && dist[e[v][i]] > dist[v] + wei[v][i]) {
                dist[e[v][i]] = dist[v] + wei[v][i];
                return false;
            }

    // No neg cycle detected
    return true;
}


/*----- BellmanFord w/ Detect negative weight cycles and reconstruct neg cycles --------*/
/*
    dist[u] = inf: no path from s to u
    if u in negCycle: distance from s to u is −∞
*/
int dist[MAXV];
int pre[MAXV];
set<int> negCycle;

bool visited[MAXV];
void bfs(int start) {
    memset(visited, false, sizeof(visited));

    visited[start] = true;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        //Process node v
        negCycle.insert(v);

        for (int i = 0; i < e[v].size(); ++i)
            if (!visited[e[v][i]]) {
                visited[e[v][i]] = true;
                q.push(e[v][i]);
            }
    }
}
bool bellmanFord(int start) {
    memset(pre, 0, sizeof(pre));
    memset(dist, 0x7f, sizeof(dist));
    negCycle.clear();

    dist[start] = 0;

    for (int k = 0; k < V - 1; ++k)
        for (int v = 1; v <= V; ++v) 
            for (int i = 0; i < e[v].size(); ++i)
                if (dist[v] != inf && dist[e[v][i]] > dist[v] + wei[v][i]) {
                    dist[e[v][i]] = dist[v] + wei[v][i];
                    pre[e[v][i]] = v;
                }

    // detect and reconstruct neg cycle
    for (int v = 1; v <= V; ++v) 
        for (int i = 0; i < e[v].size(); ++i)
            if (dist[v] != inf && dist[e[v][i]] > dist[v] + wei[v][i]) {
                dist[e[v][i]] = dist[v] + wei[v][i];
                bfs(v);
            }

    // neg cycle detected
    if (!negCycle.empty())
        return false;

    // No neg cycle
    return true;
}


/*----- reconstruct Shortest Path --------*/
vector<int> reconstructSPT(int start, int end) {
    vector<int> res;
    int v = end;
    while (v != start) {
        res.push_back(v);
        v = pre[v];

        if(v == 0)
            return vector<int>();
    }
    res.push_back(start);
    reverse(res.begin(), res.end());
    return res;
}
