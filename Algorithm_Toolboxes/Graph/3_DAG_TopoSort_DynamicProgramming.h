
const int MAXV = 100 + 3;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

/******************* DP on DAG *******************/
//    (a1),(a2),... ----------> (b)

/*------ Count the number of path to reach from start to other vertices - f(b) += f(a) -------*/

int f[MAXV];
void countPath(int start) {
    TopoSort topo(V);
    for(int v=1; v<=V; ++v) for(int i=0; i<e[v].size(); ++i)
        topo.addEdge(v, e[v][i]);

    topo.topoSort();
    vi topoOrder = topo.get_Results();

    f[start] = 1;
    for (int i = 0; i < topoOrder.size(); ++i) {
        int v = topoOrder[i];
        for (int j = 0; j < e[v].size(); ++j)
            f[e[v][j]] += f[v];
    }
}


/*------------- shortestPath in DAG - f(b) = min(f(a) + wei(a->b), f[b]) --------------*/
int f[MAXV];
void shortestPath(int start) {
    TopoSort topo(V);
    for(int v=1; v<=V; ++v) for(int i=0; i<e[v].size(); ++i)
        topo.addEdge(v, e[v][i]);

    topo.topoSort();
    vi topoOrder = topo.get_Results();

    memset(f, 0x7f, sizeof(f));
    f[start] = 0;
    for(int i = 0; i < topoOrder.size(); ++i) {
        int v = topoOrder[i];
        for(int j = 0; j < e[v].size(); ++j) 
            f[e[v][j]] = min(f[v] + wei[v][j], f[e[v][j]]);
    }
}
