
// https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm
// Worst case: O(V+E)

class Tarjan {
private:
    const int INF = (int)1e9 + 7;
    int V;
    int CLK;
    vector<vector<int>> e;
    stack<int> S;
    vector<bool> onStack;
    vector<int> order, lowlink;
    vector<vector<int>> SCC;


    void explore(int v) {
        // Set the depth order for v to the smallest unused order
        this->order[v] = this->CLK;
        this->lowlink[v] = this->CLK++;
        this->S.push(v);
        this->onStack[v] = true;

        // Consider successors of v
        for(int i = 0; i < this->e[v].size(); ++i) {
            int w = this->e[v][i];

            if(this->order[w] == -1) {
                // Successor w has not yet been visited; recurse on it
                this->explore(w);
                this->lowlink[v] = min(this->lowlink[v], this->lowlink[w]);
            }
            else if(this->onStack[w]) {
                // Successor w is in stack S and hence in the current SCC
                // Note: The next line may look odd - but is correct.
                // It says w.order not w.lowlink; that is deliberate and from the original paper
                this->lowlink[v] = min(this->lowlink[v], this->order[w]);
            }
        }

        // If v is a root node, pop the stack and generate an SCC
        vector<int> group;
        if(this->lowlink[v] == this->order[v]) {
            int w = 0;
            do {
                w = this->S.top();
                this->S.pop();
                this->onStack[w] = false;
                group.push_back(w);
            } while(w != v);
            this->SCC.push_back(group);
        }
    }
public:
    Tarjan(int V = 0) : V(V) {
        this->e.assign(V + 1, vector<int>());

        this->onStack.assign(V + 1, false);
        this->order.assign(V + 1, -1);
        this->lowlink.assign(V + 1, INF);
    }
    void addEdge(int v, int u) {
        this->e[v].push_back(u);
    }
    void find_SCC() {
        for(int v = 1; v <= this->V; ++v) {
            if(this->order[v] == -1)
                this->explore(v);
        }
    }
    vector<vector<int>> get_SCC() {
        return this->SCC;
    }
};
