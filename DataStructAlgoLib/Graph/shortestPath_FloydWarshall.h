
//												shortest path by Floyd-Warshall
// 	O(V^3)
// Floyd-Warshall gives us the shortest paths from all source to all target nodes. 
// There are other uses for Floyd-Warshall as well;
// it can be used to find connectivity in a graph (known as the Transitive Closure of a graph).
// Note: Use for adj matrix, No negative wei
/*--------------------------------------------------------------------------------------------------------------------------------*/
const int MAXV = 100 + 1;
int V, E;

int adj[MAXV][MAXV];
void floydWarshall() {
	for (int i = 1; i <= V; ++i)
		for (int j = 1; j <= V; ++j)
			for (int k = 1; k <= V; ++k)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

/*----------------------------------------- Floyd-Warshall for adjlist ---------------------------------------------------------------------------------------*/

const int MAXV = 100 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

int adj[MAXV][MAXV];
void preProcess() {
	for (int i = 1; i <= V; ++i)
		fill(adj[i] + 1, adj[i] + V + 1, inf);

	for (int v = 1; v <= V; ++v)
		for (int i = 0; i < e[v].size(); ++i)
			adj[v][e[v][i]] = wei[v][i];
}

void floydWarshall() {
	for (int i = 1; i <= V; ++i)
		for (int j = 1; j <= V; ++j)
			for (int k = 1; k <= V; ++k)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}


