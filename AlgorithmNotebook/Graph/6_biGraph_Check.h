

// Checking whether a Graph is Bipartite
// O(V+E)

/*-------------------------------------------------------------------------------------------------------------*/
const int MAXV = 101;
int V, E;
vector<int> e[MAXV];

bool visited[MAXV];
int color[MAXV];
void explore(int v, int preC) {
    visited[v] = true;
    
    //Process v
    if(preC == 2)
        color[v] = 1;
    if(preC == 1)
        color[v] = 2;

    for(int i = 0; i < e[v].size(); ++i)
        if(!visited[e[v][i]])
            explore(e[v][i], color[v]);
}
void dfs() {
    memset(visited, false, sizeof(visited));
    memset(color, 0, sizeof(color));
    for(int v=1; v<=V; ++v)
        if(!visited[v])
            explore(v, 2);
}
bool biGraphCheck() {
    dfs();
    for (int v = 1; v < V + 1; ++v)
        for (int i = 0; i < e[v].size(); ++i)
            if (color[v] == color[e[v][i]]) 
                return false;

    return true;
}
