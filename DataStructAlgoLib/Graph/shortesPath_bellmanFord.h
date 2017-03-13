
//												shortest path by BellmanFord
/*----------------------------------------------------------- BellmanFord ---------------------------------------------------------------------*/
const int MAXV = 100 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

int dist[MAXV];
int pre[MAXV];
void bellmanFord(int start) {
	memset(pre + 1, 0, V * sizeof(int));
	for (int v = 1; v <= V; ++v) 
		dist[v] = (v == start) ? 0 : inf;
	
	for (int k = 0; k < V - 1; ++k) {
		for (int v = 1; v <= V; ++v)
			for (int i = 0; i < e[v].size(); ++i)
				if (dist[e[v][i]] > dist[v] + wei[v][i]) {
					dist[e[v][i]] = dist[v] + wei[v][i];
					pre[e[v][i]] = v;
				}
	}
}

vector<int> reconstructSPT(int start, int end) {
	vector<int> res;
	int v = end;
	while (v != start) {
		res.push_back(v);
		v = pre[v];

	}
	res.push_back(start);
	reverse(res.begin(), res.end());
	return res;
}

/*-------------------------------------------------------- Detect negative weight cycles ------------------------------------------------------------------------*/
int dist[MAXV];
int pre[MAXV];
queue<int> detectNegCycle() {
	queue<int> q;
	for (int v = 1; v <= V; ++v)
		for (int i = 0; i < e[v].size(); ++i)
			if (dist[e[v][i]] > dist[v] + wei[v][i]) {
				dist[e[v][i]] = dist[v] + wei[v][i];
				pre[e[v][i]] = v;
				
				q.push(v);
			}
	return q;
}
bool bellmanFord(int start) {
	memset(pre + 1, 0, V * sizeof(int));
	for (int v = 1; v <= V; ++v) 
		dist[v] = (v == start) ? 0 : inf;
	
	for (int k = 0; k < V - 1; ++k) {
		for (int v = 1; v <= V; ++v)
			for (int i = 0; i < e[v].size(); ++i)
				if (dist[e[v][i]] > dist[v] + wei[v][i]) {
					dist[e[v][i]] = dist[v] + wei[v][i];
					pre[e[v][i]] = v;
				}
	}

	//check neg cycle
	queue<int> q = detectNegCycle();
	if (q.empty())
		return false;

	return true;
}
