

/*--------------- TopoSort by DFS ----------------------------------------------------------------------------------------------*/
const int MAXV = 1e6 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];


bool visited[MAXV];
vector<int> topoOrder;
void explore(int v) {
	visited[v] = true;
	for (int i = 0; i < e[v].size(); ++i) {
		if (!visited[e[v][i]])
			explore(e[v][i]);
	}

	//PostOrder
	topoOrder.push_back(v);
}
void dfs(int start) {
	memset(visited + 1, false, V);
	explore(start);
}
void topoSort(int source) {
	dfs(source);
	reverse(topoOrder.begin(), topoOrder.end());
}
