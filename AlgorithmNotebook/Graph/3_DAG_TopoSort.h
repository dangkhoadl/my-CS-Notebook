
const int MAXV = 1e6 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

/************************************************************** TopoSort *****************************************************************************************************************/
/*--------------- TopoSort - no Cycle detection -------------------------------------*/
bool visited[MAXV];
vector<int> topoOrder;
void explore(int v) {
    visited[v] = true;
    for (int i = 0; i < e[v].size(); ++i) {
        if (!visited[e[v][i]])
            explore(e[v][i]);
    }
    //Postprocess
    topoOrder.push_back(v);
}
void dfs() {
    memset(visited, false, sizeof(visited));
    for (int v = 1; v <= V; ++v)
        if(!visited[v])
            explore(v);
}
void topoSort() {
    dfs();
    reverse(topoOrder.begin(), topoOrder.end());
}

/*--------------- TopoSort w/ Cycle detection ---------------------------------------*/
int state[MAXV];
vector<int> topoOrder;
bool isDAG;
void explore(int v) {
    state[v] = 1;
    //Preprocess

    for (int i = 0; i < e[v].size(); ++i) {
        if (state[e[v][i]] == 1)
            isDAG = false;
        if (state[e[v][i]] == 0)
            explore(e[v][i]);
    }
    state[v] = 2;
    // Postprocess
    topoOrder.push_back(v);
}
void dfs() {
    memset(state, 0, sizeof(state));
    for (int v = 1; v <= V; ++v)
        if (state[v] == 0)
            explore(v);
}
void topoSort() {
    isDAG = true;
    dfs();

    if (isDAG)
        reverse(topoOrder.begin(), topoOrder.end());
    else
        topoOrder.clear();
}


/************************************************************** DP on DAG *****************************************************************************************************************/
//    (a1),(a2),... ----------> (b)

/*--------------- Count the number of path to reach from start to other vertices - f(b) += f(a) ---------------------------------------*/
int state[MAXV];
vector<int> topoOrder;
bool isDAG;
void explore(int v) {
    state[v] = 1;
    for (int i = 0; i < e[v].size(); ++i) {
        if (state[e[v][i]] == 1)
            isDAG = false;
        if (state[e[v][i]] == 0)
            explore(e[v][i]);
    }
    state[v] = 2;
    // Postprocess
    topoOrder.push_back(v);
}
void dfs() {
    memset(state, 0, sizeof(state));
    for (int v = 1; v <= V; ++v)
        if (state[v] == 0)
            explore(v);
}
void topoSort() {
    isDAG = true;
    dfs();

    if (isDAG)
        reverse(topoOrder.begin(), topoOrder.end());
    else
        topoOrder.clear();
}
int f[MAXV];
void countPath(int start) {
    f[start] = 1;
    topoSort();
    for (int i = 0; i < topoOrder.size(); ++i) {
        int v = topoOrder[i];
        for (int j = 0; j < e[v].size(); ++j)
            f[e[v][j]] += f[v];
    }
}

/*--------------- shortestPath in DAG - f(b) = min(f(a) + wei(a->b), f[b]) ---------------------------------------*/
int state[MAXV];
vector<int> topoOrder;
bool isDAG;
void explore(int v) {
    state[v] = 1;
    //Preprocess

    for (int i = 0; i < e[v].size(); ++i) {
        if (state[e[v][i]] == 1)
            isDAG = false;
        if (state[e[v][i]] == 0)
            explore(e[v][i]);
    }
    state[v] = 2;
    // Postprocess
    topoOrder.push_back(v);
}
void dfs() {
    memset(state, 0, sizeof(state));
    for (int v = 1; v <= V; ++v)
        if (state[v] == 0)
            explore(v);
}
void topoSort() {
    isDAG = true;
    dfs();

    if (isDAG)
        reverse(topoOrder.begin(), topoOrder.end());
    else
        topoOrder.clear();
}
int f[MAXV];
void shortestPath(int start) {
    topoSort();

    fill(f+1, f+V+1, inf);
    f[start] = 0;
    for(int i = 0; i < topoOrder.size(); ++i) {
        int v = topoOrder[i];
        for(int j = 0; j < e[v].size(); ++j) 
            f[e[v][j]] = min(f[v] + wei[v][j], f[e[v][j]]);
    }
}
