
//                              Prim: O(V + Elog(E))
const int MAXV = 100 + 3;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

/*-------------------- Use pq ------------------------*/
int cost[MAXV];
int pre[MAXV];
bool processed[MAXV];
int prim(int start) {
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

    // Calc minSpanning Tree total weight
    int totalTreeWeight = 0;
    for(int v=1; v<=V; ++v)
        totalTreeWeight += cost[v];
    return totalTreeWeight;
}


/*-------------------- Struct - Min Heap -----------------------*/
int cost[MAXV]; // store the weight from i -> pre[i]
int pre[MAXV];  // root node of the tree (start) has pre = 0
int prim(int start) {
    MinHeap H;
    memset(pre + 1, 0, V * sizeof(int));
    for (int v = 1; v <= V; ++v) {
        cost[v] = (v == start) ? 0 : inf;
        H.insert({cost[v], v});
    }

    while (!H.empty()) {
        int v = H.extractMin();
        for (int i = 0; i < e[v].size(); ++i)
            if (H.exist(e[v][i]) && cost[e[v][i]] > wei[v][i]) {
                cost[e[v][i]] = wei[v][i];
                pre[e[v][i]] = v;
                H.changePriority({cost[e[v][i]], e[v][i]});
            }
    }

    // Calc minSpanning Tree total weight
    int totalTreeWeight = 0;
    for(int v=1; v<=V; ++v)
        totalTreeWeight += cost[v];
    return totalTreeWeight;
}
