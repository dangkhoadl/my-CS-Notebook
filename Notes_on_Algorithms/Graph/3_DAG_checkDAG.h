
// O(V+E)
// Check if a digraph is DAG (No cycle graph)
// 3 states of a vertex
//      + 0: not visited
//      + 1: pre visited
//      + 2: post visited

const int MAXV = 100 + 3;
int V, E;
vector<int> e[MAXV];

int state[MAXV];
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
}
void dfs() {
    memset(state, 0, sizeof(state));
    for (int v = 1; v <= V; ++v)
        if (state[v] == 0)
            explore(v);
}
bool check_DAG() {
    isDAG = true;
    dfs();
    return isDAG;
}
