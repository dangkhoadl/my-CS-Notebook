
// O(V+E)

const int MAXV = 1e6 + 1;
int V, E;
vector<int> e[MAXV];

/*--------------- TopoSort - no Cycle detection -----------*/
bool visited[MAXV];
vector<int> topoOrder;
void explore(int v) {
    // Preprocess
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
    topoOrder.clear();
    dfs();
    reverse(topoOrder.begin(), topoOrder.end());
}

/*--------------- TopoSort w/ Cycle detection ------------*/
class TopoSort {
private:
    int V;
    vector<int> state;
    vector<int> topoOrder;
    vector<vector<int>> e;
    bool isDAG;
private:
    void explore(int v) {
        // Preprocess
        this->state[v] = 1;

        for (int i = 0; i < this->e[v].size(); ++i) {
            if (this->state[e[v][i]] == 1)
                this->isDAG = false;
            if (this->state[this->e[v][i]] == 0)
                this->explore(this->e[v][i]);
        }

        // Postprocess
        this->state[v] = 2;
        this->topoOrder.push_back(v);
    }
    void dfs() {
        for (int v = 1; v <= V; ++v)
            if (this->state[v] == 0)
                this->explore(v);
    }
public:
    TopoSort(int V): V(V) {
        this->state.assign(V+1, 0);
        this->isDAG = true;
        this->e.assign(V+1, vector<int>());
    }
    void addEdge(int u, int v) {
        this->e[u].push_back(v);
    }
    bool topoSort() {
        this->topoOrder.clear();
        this->isDAG = true;
        this->dfs();

        if(this->isDAG) {
            reverse(this->topoOrder.begin(), this->topoOrder.end());
            return true;
        }

        this->topoOrder.clear();
        return false;
    }
    vector<int> get_Results() {
        return this->topoOrder;
    }
};
