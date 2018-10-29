
//												shortest path by BellmanFord (Negative weight)
//		O(V*E)
// Note: for (int k = 0; k < V - 1; ++k): 
//				-> Repeat (V-1) times
//		for (int v = 1; v <= V; ++v)
//			for (int i = 0; i < e[v].size(); ++i)
//				-> Loop E times
//
//		- Works w/ neg weight edges
//		- Can detect neg weight cycle
/*----------------------------------------------------------- BellmanFord simple (No neg cycle in graph) ---------------------------------------------------------------------*/
const int MAXV = 100 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

int dist[MAXV];
int pre[MAXV];
void bellmanFord(int start) {
	memset(pre, 0, sizeof(pre));
	memset(dist, 0x7f, sizeof(dist));

	dist[start] = 0;
	
	for (int k = 0; k < V - 1; ++k)
		for (int v = 1; v <= V; ++v)
			for (int i = 0; i < e[v].size(); ++i)
				if (dist[e[v][i]] > dist[v] + wei[v][i]) {
					dist[e[v][i]] = dist[v] + wei[v][i];
					pre[e[v][i]] = v;
				}
}
vector<int> reconstructSPT(int start, int end) {
	vector<int> res;
	int v = end;
	while (v != start) {
		res.push_back(v);
		v = pre[v];

		if(v == 0)
			return vector<int>();
	}
	res.push_back(start);
	reverse(res.begin(), res.end());
	return res;
}


/*-------------------------------------------------------- BellmanFord w/ Detect negative weight cycles and reconstruct neg cycle ------------------------------------------------------------------------*/
int dist[MAXV];
int pre[MAXV];
set<int> negCycle;
void detectNegCycle() {
	for (int v = 1; v <= V; ++v)
		for (int i = 0; i < e[v].size(); ++i)
			if (dist[e[v][i]] > dist[v] + wei[v][i]) {
				dist[e[v][i]] = dist[v] + wei[v][i];
				pre[e[v][i]] = v;

				negCycle.insert(v);
			}
}
bool bellmanFord(int start) {
	memset(pre, 0, sizeof(pre));
	memset(dist, 0x7f, sizeof(dist));

	dist[start] = 0;

	for (int k = 0; k < V - 1; ++k)
		for (int v = 1; v <= V; ++v)
			for (int i = 0; i < e[v].size(); ++i)
				if (dist[e[v][i]] > dist[v] + wei[v][i]) {
					dist[e[v][i]] = dist[v] + wei[v][i];
					pre[e[v][i]] = v;
				}

	//check neg cycle
	detectNegCycle();
	if (negCycle.empty())
		return false;

	return true;
}
