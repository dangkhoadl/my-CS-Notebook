
//O(V + E)
// Algo:
//		- Find groups of Strong Connected Components in Directed graph
//		- DFS(G)
//			Sort the vertex by postvisit order
//		- build Gr = G.inverse()
//		- DFS(Gr)
//			Construct SCC groups

/********************************** Kosaraju ************************************************************/
const int MAXV = 101;
int V, E;
vector<int> e[MAXV];


// DFS G
bool visited[MAXV];
int preCLK[MAXV];
int postCLK[MAXV];
int CLK = 1;
void explore(int v) {
	visited[v] = true;
	
	//Previsit
	preCLK[v] = CLK;
	++CLK;

	for (int i = 0; i < e[v].size(); ++i) {
		if (!visited[e[v][i]])
			explore(e[v][i]);
	}

	//PostVisit
	postCLK[v] = CLK;
	++CLK;
}
void dfs() {
	memset(visited + 1, false, V);
	for (int v = 1; v <= V; ++v)
		if (!visited[v])
			explore(v);
}
//DFS G_R
vector<int> e_r[MAXV];
bool visited_r[MAXV];
void explore_r(int v) {
	visited_r[v] = true;
	for (int i = 0; i < e_r[v].size(); ++i) {
		if (!visited_r[e_r[v][i]])
			explore_r(e_r[v][i]);
	}
}
//Kosaraju
bool check[MAXV];
vector<pair<int,int>> piiSorted;
vector<vector<int>> SCC;
void kosaraju() {
	// dfs G
	dfs();

	//Sort postVisit 
	for(int i = 1; i <= V; ++i) {
		piiSorted.push_back( {-postCLK[i], i} );
	}
	sort(piiSorted.begin(), piiSorted.end());

	// Create G_r
	for(int v = 1; v <= V; ++v) 
		for(int i = 0; i < e[v].size(); ++i)
			e_r[e[v][i]].push_back(v);

	//dfs G_r
	memset(check + 1, false, V);
	memset(visited_r + 1, false, V);
	for(int i = 0; i < piiSorted.size(); ++i) {
		int v = piiSorted[i].second;
		if(!visited_r[v]) 
			explore_r(v);

		// Put SCC into group
		vector<int> group;
		for(int j = 1; j <= V; ++j) 
			if(visited_r[j] && !check[j]) {
				check[j] = true;
				group.push_back(j);
			}
		
		if (group.size() > 0) 
			SCC.push_back(group);
	}
}
