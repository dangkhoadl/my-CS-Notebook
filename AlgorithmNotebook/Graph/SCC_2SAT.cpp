
// O( V + E)
// Input format: L = (x2 v -x1) (-x1 v x2) (x1 v x3) (-x2 v -x3) (x1 v x4)
//
// 2 -1
// -1 -2
// 1 3
// -2 -3
// 1 4

// Algo:
//		Find x1,x2,x3,x4 satisfy the L (L true)
//		Ex: L = (x2 v -x1) (-x1 v x2) (x1 v x3) (-x2 v -x3) (x1 v x4)
//		- create graph with (a v b) = 
// 				(-a)----->(b)
//				(-b)----->(a)
// 			- my rule: 
//					   a = i * 2 - 1
//					  -a = i * 2
//			- Ex: 
//				a1: a1 = (1)   and -a1  = (2)
//				a2: a2 = (3)   and -a2 = (4)
//
//			- Final result
//					x1 = false, x2 =false, x3 = true, x4 = true	

/* ------------------------------------------------ 2SAT ----------------------------------------------------------------------------- */

const int MAXV = 101;

vector<pair<int,int>> sat;
void readInput() {
	long long a,b;
	while(scanf("%lld %lld", &a, &b) > 0)
		sat.push_back( {a,b} );
}

inline pair<int,int> getVertexID(int i) {
    if(i > 0)
        return {i*2 - 1, i*2};
    return {-i*2, -i*2 -1};
}

inline pair<int,int> getVar(int i) {
    return {i*2-1, i*2};
}

vector<int> e[MAXV];
int V = 0;
void createGraph() {
    for(int i = 0; i < sat.size(); ++i) {
        int a = sat[i].first;
        int b = sat[i].second;
        V = max(V, abs(a) * 2);
        V = max(V, abs(b) * 2);

        int va = getVertexID(a).first;
        int va_ = getVertexID(a).second;
        int vb = getVertexID(b).first;
        int vb_ = getVertexID(b).second;
        
        e[va_].push_back(vb);
        e[vb_].push_back(va);
    }
}
// ------------------------------------------------ Tarjan ---------------------------
int CLK = 1;
stack<int> S;
bool onStack[MAXV];
int order[MAXV];
int lowlink[MAXV];

int groupID = 1;
int SCC[MAXV];
void explore(int v) {
    // Set the depth order for v to the smallest unused order
    order[v] = CLK;
    lowlink[v] = CLK++;
    S.push(v);
    onStack[v] = true;

    // Consider successors of v
    for(int i = 0; i < e[v].size(); ++i) {
        int w = e[v][i];

        if(order[w] == -1) {
            // Successor w has not yet been visited; recurse on it
            explore(w);
            lowlink[v] = min(lowlink[v], lowlink[w]);
        }
        else if(onStack[w]) {
            // Successor w is in stack S and hence in the current SCC
            // Note: The next line may look odd - but is correct.
            // It says w.order not w.lowlink; that is deliberate and from the original paper
            lowlink[v] = min(lowlink[v], order[w]);
        }
    }

    // If v is a root node, pop the stack and generate an SCC
    if(lowlink[v] == order[v]) {
        int w = 0;
        do {
            w = S.top();
            S.pop();
            onStack[w] = false;

            // Set
            SCC[w] = groupID; 
        } while(w != v);

        ++groupID;
    }
}

void tarjan() {
    memset(order, -1, sizeof(order));
    memset(onStack, false, sizeof(onStack));
    memset(lowlink, 0x7f, sizeof(lowlink));
    memset(SCC, -1, sizeof(SCC));
    while(!S.empty()) S.pop();
    for(int v = 1; v <= V; ++v) {
        if(order[v] == -1)
            explore(v);
    }
}

bool res[MAXV];
bool twoSat() {
    memset(res, false, sizeof(res));
    createGraph();
    tarjan();

    //check SCC and yield results
    for(int i = 1; i <= V/2; ++i) {
        int posVar = getVar(i).first;
        int negVar = getVar(i).second;

        if(SCC[posVar] == SCC[negVar])
            return false;

        if(SCC[posVar] < SCC[negVar])
            res[i] = false;
        else
            res[i] = true;
    }
    return true;
}
