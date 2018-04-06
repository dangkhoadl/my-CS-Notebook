
//		O(V * E^2)

/*----------------------------------- Edmond Karp - maxFlow -----------------------------------------------------------------*/
vector<int> g[MAXV];
map<int,int> gWei[MAXV];
void buildRGraph() {
	for(int v = 1; v <= V; ++v)
		for(int i = 0; i < e[v].size(); ++i) {
			g[v].push_back(e[v][i]);
			gWei[v].insert ({ e[v][i],  wei[v][i] });
			g[e[v][i]].push_back(v);
			gWei[e[v][i]].insert( { v, 0 } );
		}
}
int pre[MAXV];
bool visited[MAXV];
int EdmondKarp(int s, int t) {
	int maxFlow = 0;

	//Repeat
	while(true) {
		// bfs to find path from s -> t
		memset(visited, false, sizeof(visited));
		memset(pre, -1, sizeof(pre));
		visited[s] = true;
		queue<int> q;
		q.push(s);

		while (!q.empty()) {
			int v = q.front();
			q.pop();

			for (int i = 0; i < g[v].size(); ++i) 
				if (!visited[g[v][i]] && gWei[v][g[v][i]] > 0) {
					visited[g[v][i]] = true;
					q.push(g[v][i]);

					//update
					pre[g[v][i]] = v;
				}
		}

		//Check terminate condition == if no path from s -> t
		if (pre[t] == -1)
			break;
		
		//Find the min flow
		int flow = inf;
		for(int v = t; v != s; v = pre[v])
			flow = min(flow, gWei[pre[v]][v]);
		
		//Update flow
		for(int v = t; v != s; v = pre[v]) {
			gWei[pre[v]][v] -= flow;
			gWei[v][pre[v]] += flow;
		}
		maxFlow += flow;
	}
	return maxFlow;
}
