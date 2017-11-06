
// O(V + E)
/*--------------------------------------------- Connected Components-----------------------------------------------------------*/
const int MAXV = 1e6 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];


bool visited[MAXV];
int CCLabel[MAXV];
int label;
void explore(int v) {
	visited[v] = true;
	CCLabel[v] = label;

	for (int i = 0; i < e[v].size(); ++i) {
		if (!visited[e[v][i]])
			explore(e[v][i]);
	}
}
void dfsAll() {
	memset(visited, false, sizeof(visited));
	label = 1;
	for (int v = 1; v <= V; ++v)
		if (!visited[v]) {
			explore(v);
			++label;
		}
}
