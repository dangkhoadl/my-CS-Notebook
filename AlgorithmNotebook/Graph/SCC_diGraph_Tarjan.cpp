
// https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm
const int MAXV = 101;
int V, E;
vector<int> e[MAXV];


int CLK = 1;
stack<int> S;
bool onStack[MAXV];
int index[MAXV];
int lowlink[MAXV];

vector<int> group;
vector<vector<int>> SCC;
void explore(int v) {
    // Set the depth index for v to the smallest unused index
    index[v] = CLK;
    lowlink[v] = CLK++;
    S.push(v);
    onStack[v] = true;

    // Consider successors of v
    for(int i = 0; i < e[v].size(); ++i) {
        int w = e[v][i];

        if(index[w] == -1) {
            // Successor w has not yet been visited; recurse on it
            explore(w);
            lowlink[v] = min(lowlink[v], lowlink[w]);
        }
        else if(onStack[w]) {
            // Successor w is in stack S and hence in the current SCC
            // Note: The next line may look odd - but is correct.
            // It says w.index not w.lowlink; that is deliberate and from the original paper
            lowlink[v] = min(lowlink[v], index[w]);
        }
    }

    // If v is a root node, pop the stack and generate an SCC
    if(lowlink[v] == index[v]) {
        group.clear();
        int w = 0;
        do {
            w = S.top();
            S.pop();
            onStack[w] = false;
            group.push_back(w);
        } while(w != v);
        SCC.push_back(group);
    }
}

void tarjan() {
    memset(index, -1, sizeof(index));
    memset(onStack, false, sizeof(onStack));
    memset(lowlink, 0x7f, sizeof(lowlink));
    for(int v = 1; v <= V; ++v) {
        if(index[v] == -1)
            explore(v);
    }
}
