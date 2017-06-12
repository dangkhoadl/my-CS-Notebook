
//		O(V * E^2)

/*----------------------------------- Edmond Karp for matrix -----------------------------------------------------------------*/
//vertex | numOfAdjVertex	adjvertex[0] capacity[0]	adjvertex[1] capacity[1]	...
//
//6 10					
//2 2 16 3 13			
//2 3 10 4 12
//2 2 4 5 14
//2 3 9 6 20
//2 4 7 6 4
const int MAXV = 101;
int V, E;
int C[MAXV][MAXV];		// graph: Capacity matrix
int T[MAXV][MAXV];		// Residual graph
void readInput() {
	cin >> V >> E;
	for (int v = 1; v <= V; ++v) {
		int num, w, c;
		cin >> num;
		for (int i = 0; i < num; ++i) {
			cin >> w >> c;
			C[v][w] = T[v][w] = c;
		}
	}
}

int F[MAXV][MAXV]; //flow matrix: Output of edmond karp

int pre[MAXV];
int M[MAXV]; // capacity of the path found by bfs
int bfs(int s, int t) {
	memset(pre + 1, -1, V * sizeof(int));
	pre[s] = -2;
	fill(M + 1, M + V + 1, inf);

	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for(int w=1; w <= V; ++w)
			//If there is available residual capacity and v is not seen before in search
			if (w != v && T[v][w] > 0 && pre[w] == -1) {
				//Update
				pre[w] = v;
				M[w] = min(M[v], C[v][w] - F[v][w]);

				//Check destination
				if (w == t)
					return M[t];
				q.push(w);
			}
	}
	return 0;
}

int EdmondsKarp(int s, int t) {
	int maxFlow = 0;

	while (true) {
		// bfs to find a path
		int flow = bfs(s, t);
		if (flow == 0)
			break;

		//Update max flow
		maxFlow += flow;
		
		//Backtrack the search path, and update flow to F and T
		int v = t;
		while (v != s) {
			F[pre[v]][v] += flow;
			F[v][pre[v]] -= flow;
			T[pre[v]][v] -= flow;
			T[v][pre[v]] += flow;

			v = pre[v];
		}
	}
	return maxFlow;
}

/*----------------------------------- Edmond Karp for adjlist -----------------------------------------------------------------*/
//vertex | numOfAdjVertex	adjvertex[0] capacity[0]	adjvertex[1] capacity[1]	...
//
//6 10					
//2 2 16 3 13			
//2 3 10 4 12
//2 2 4 5 14
//2 3 9 6 20
//2 4 7 6 4
const int MAXV = 1e6 + 1;
int V, E;

struct Edge {
	int from, to, flow, cap;
};	
vector<Edge> edges;			//store forward and backward edges, Note: forward edges: even id, backward edges: odd id => opposite edge = id xor 1
vector<int> id[MAXV];		//store indices of edges in the edges list aboved

void readInput() {
	cin >> V >> E;
	int num, w, cap;
	for (int v = 1; v <= V; ++v) {
		cin >> num;
		for (int i = 0; i < num; ++i) {
			cin >> w >> cap;
			id[v].push_back(edges.size());
			edges.push_back({v,w,0,cap});
			id[w].push_back(edges.size());
			edges.push_back({w,v,cap,cap});
		}
	}
}

int pre[MAXV];
bool visited[MAXV];
vector<int> path;
int EdmondsKarp(int s, int t) {
	int maxFlow = 0;
	while (true) {
		//bfs to find a path from s to t
		fill(visited + 1, visited + V + 1, false);
		visited[s] = true;
		memset(pre + 1, -1, V * sizeof(int));

		queue<int> q;
		q.push(s);

		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int i = 0; i < id[v].size(); ++i) 
				if (!visited[edges[id[v][i]].to] && edges[id[v][i]].flow < edges[id[v][i]].cap) {
					q.push(edges[id[v][i]].to);
					visited[edges[id[v][i]].to] = true;
					pre[edges[id[v][i]].to] = edges[id[v][i]].from;
				}
		}

		//Check terminate condition
		if (pre[t] == -1)
			break;

		// reconstruct the path
		path.clear();
		int v = t;
		while (v != s) {
			path.push_back(v);
			v = pre[v];
		}
		path.push_back(s);
		reverse(path.begin(), path.end());

		//find flow of the path
		int flow = inf;
		for (int i = 0; i < path.size() - 1; ++i) {
			int v = path[i];
			int w = path[i + 1];
			for (int j = 0; j < id[v].size(); ++j) {
				if (edges[id[pre[v]][j]].flow < edges[id[pre[v]][j]].cap && edges[id[pre[v]][j]].to == v)
					flow = min(flow, edges[id[v][j]].cap - edges[id[v][j]].flow);
			}
		}
		
		//Update flow
		for (int i = 0; i < path.size() - 1; ++i) {
			int v = path[i];
			int w = path[i + 1];
			for (int j = 0; j < id[v].size(); ++j) 
				if (edges[id[v][j]].to == w) {
					edges[id[v][j]].flow += flow;
					edges[id[v][j] ^ 1].flow -= flow;			//opposite edge = id xor 1
				}
		}
		maxFlow += flow;
	}
	return maxFlow;
}

/*----------------------------------- Edmond Karp for adjlist (optimized)-----------------------------------------------------------------*/
//vertex | numOfAdjVertex	adjvertex[0] capacity[0]	adjvertex[1] capacity[1]	...
//
//6 10					
//2 2 16 3 13			
//2 3 10 4 12
//2 2 4 5 14
//2 3 9 6 20
//2 4 7 6 4

const int MAXV = 1e6 + 1;
int V, E;

struct Edge {
	int from, to, flow, cap;
};	
vector<Edge> edges;			//store forward and backward edges, Note: forward edges: even id, backward edges: odd id => opposite edge = id xor 1
vector<int> id[MAXV];		//store indices of edges in the edges list aboved

void readInput() {
	cin >> V >> E;
	int num, w, cap;
	for (int v = 1; v <= V; ++v) {
		cin >> num;
		for (int i = 0; i < num; ++i) {
			cin >> w >> cap;
			id[v].push_back(edges.size());
			edges.push_back({v,w,0,cap});
			id[w].push_back(edges.size());
			edges.push_back({w,v,cap,cap});
		}
	}
}

int pre[MAXV];
bool visited[MAXV];
int EdmondsKarp(int s, int t) {
	int maxFlow = 0;
	while (true) {
		//bfs to find a path from s to t
		fill(visited + 1, visited + V + 1, false);
		visited[s] = true;
		memset(pre + 1, -1, V * sizeof(int));

		queue<int> q;
		q.push(s);

		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int i = 0; i < id[v].size(); ++i) 
				if (!visited[edges[id[v][i]].to] && edges[id[v][i]].flow < edges[id[v][i]].cap) {
					q.push(edges[id[v][i]].to);
					visited[edges[id[v][i]].to] = true;
					pre[edges[id[v][i]].to] = edges[id[v][i]].from;
				}
		}

		//Check terminate condition
		if (pre[t] == -1)
			break;

		//find flow of the path
		int flow = inf;
		for(int v = t; v != s; v = pre[v])
			for (int j = 0; j < id[pre[v]].size(); ++j) {
				if (edges[id[pre[v]][j]].flow < edges[id[pre[v]][j]].cap && edges[id[pre[v]][j]].to == v)
					flow = min(flow, edges[id[pre[v]][j]].cap - edges[id[pre[v]][j]].flow);
			}
		
		
		//Update flow
		for (int v = t; v != s; v = pre[v])
			for (int j = 0; j < id[pre[v]].size(); ++j)
				if (edges[id[pre[v]][j]].to == v) {
					edges[id[pre[v]][j]].flow += flow;
					edges[id[pre[v]][j] ^ 1].flow -= flow;			//opposite edge = id xor 1
				}
		maxFlow += flow;
	}
	return maxFlow;
}
