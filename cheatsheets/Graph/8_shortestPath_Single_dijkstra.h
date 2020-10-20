

// O( (V+Elog(E))
//                       shortest path by dijkstra
/*-------------------------------------------------*/
const int MAXV = 1e6 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

int dist[MAXV];
int pre[MAXV];
bool processed[MAXV];
void dijkstra(int start) {
    memset(processed, false, sizeof(processed));
    memset(pre, 0, sizeof(pre));
    memset(dist, 0x7f, sizeof(dist));

    dist[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({ -dist[start], start });

    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();

        if (processed[v])
            continue;
        processed[v] = true;

        for (int i = 0; i < e[v].size(); ++i)
            if (dist[v] != inf && dist[e[v][i]] > dist[v] + wei[v][i]) {
                //Relax
                dist[e[v][i]] = dist[v] + wei[v][i];
                pre[e[v][i]] = v;

                //Update
                pq.push({ -dist[e[v][i]], e[v][i] });
            }
    }
}

/*---------------------- reconstruct shortest path -----------*/
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
