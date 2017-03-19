
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












