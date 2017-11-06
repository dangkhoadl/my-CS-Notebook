
//O(V + E)
// Algo:
//      - Find groups of Strong Connected Components in Directed graph
//      - DFS(G)
//          Sort the vertex by postvisit order
//      - build Gr = G.inverse()
//      - DFS(Gr)
//          Construct SCC groups

/********************************** Kosaraju ************************************************************/
const int MAXV = 101;
int V, E;
vector<int> e[MAXV];
vector<int> e_r[MAXV];


// DFS G
bool visited[MAXV];
stack<int> postVisitOrder;
void explore(int v) {
    visited[v] = true;

    for (int i = 0; i < e[v].size(); ++i) {
        if (!visited[e[v][i]])
            explore(e[v][i]);
    }

    // PostVisit
    postVisitOrder.push(v);
}

//DFS G_R
bool visited_r[MAXV];
vector<int> group;
void explore_r(int v) {
    visited_r[v] = true;

    // Previsit
    group.push_back(v);

    for (int i = 0; i < e_r[v].size(); ++i) {
        if (!visited_r[e_r[v][i]])
            explore_r(e_r[v][i]);
    }
}

//Kosaraju
bool check[MAXV];
vector<vector<int>> SCC;
void kosaraju() {
    // Create G_r
    for(int v = 1; v <= V; ++v) 
        for(int i = 0; i < e[v].size(); ++i)
            e_r[e[v][i]].push_back(v);

    // dfs G
    memset(visited, false, sizeof(visited));
    for (int v = 1; v <= V; ++v) {
        if (!visited[v])
            explore(v);
    }

    //dfs G_r
    memset(visited_r, false, sizeof(visited));
    while(!postVisitOrder.empty()) {
        int v = postVisitOrder.top();
        postVisitOrder.pop();

        if(!visited_r[v])
            explore_r(v);

        // Put group into SCC
        if (group.size() > 0) {
            SCC.push_back(group);
            group.clear();
        }
    }
}
