
/********************************** Kosaraju ************************************************************/
//O(V + E)
// Algo:
//      - Find groups of Strong Connected Components in Directed graph
//      - DFS(G)
//          Sort the vertex by postvisit order
//      - build Gr = G.inverse()
//      - DFS(Gr)
//          Construct SCC groups

// vertex_id start by 1
class Kosaraju {
private:
    int V;
    vector<vector<int>> e, e_r;
    vector<bool> check, visited, visited_r;
    stack<int> postVisitOrder;
    vector<int> group;
    vector<vector<int>> SCC;


    void explore_G(int v) {
        this->visited[v] = true;

        for (int i = 0; i < this->e[v].size(); ++i) {
            if (!this->visited[e[v][i]])
                this->explore_G(e[v][i]);
        }

        // PostVisit
        this->postVisitOrder.push(v);
    }
    void explore_Gr(int v) {
        this->visited_r[v] = true;

        // Previsit
        this->group.push_back(v);

        for (int i = 0; i < this->e_r[v].size(); ++i) {
            if (!this->visited_r[e_r[v][i]])
                this->explore_Gr(e_r[v][i]);
        }
    }
public:
    Kosaraju(int V = 0) : V(V) {
        this->e.assign(V + 1, vector<int>());
        this->e_r.assign(V + 1, vector<int>());

        this->check.assign(V + 1, false);
        this->visited.assign(V + 1, false);
        this->visited_r.assign(V + 1, false);
    }
    void addEdge(int v, int u) {
        this->e[v].push_back(u);
        this->e_r[u].push_back(v);
    }
    void find_SCC() {
        // dfs G
        for (int v = 1; v <= this->V; ++v) {
            if (!this->visited[v])
                this->explore_G(v);
        }

        //dfs Gr
        while(!this->postVisitOrder.empty()) {
            int v = this->postVisitOrder.top();
            this->postVisitOrder.pop();

            if(!this->visited_r[v])
                this->explore_Gr(v);

            // Put group into SCC
            if (this->group.size() > 0) {
                this->SCC.push_back(group);
                this->group.clear();
            }
        }
    }
    vector<vector<int>> get_SCC() {
        return this->SCC;
    }
};
