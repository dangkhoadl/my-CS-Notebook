
//  DFS: 	O (V + E)
const int MAXV = 101;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

/*--------------------------------------------------------------------------------------------------------*/
bool visited[MAXV];
void explore(int v) {
	visited[v] = true;

	// Previsit node v
	// cout << v << endl;

	for (int i = 0; i < e[v].size(); ++i) {  // [Note]: Exam all edges from node v
		// Previsit edge v - u
		// cout <<  wei[v][i]<< endl;

		if (!visited[e[v][i]])				// [Note]: Condition to visit edge v-u
			explore(e[v][i]);

		// Postvisit edge v - u
		// cout <<  wei[v][i]<< endl;
	}

	// Postvisit node v
	// cout << v << endl;
}
void dfs(int start) {
	memset(visited, false, sizeof(visited));
	explore(start);
}
void dfsAll() {
	memset(visited, false, sizeof(visited));
	for (int v = 1; v <= V; ++v)
		if(!visited[v])
			explore(v);
}

/*--------------------------------------------- Pre/Post CLK-----------------------------------------------------------*/
bool visited[MAXV];
int preCLK[MAXV];
int postCLK[MAXV];
int CLK = 1;
void explore(int v) {
	visited[v] = true;
	
	// Previsit node v
	preCLK[v] = CLK;
	++CLK;

	for (int i = 0; i < e[v].size(); ++i) {
		if (!visited[e[v][i]])
			explore(e[v][i]);
	}

	// Postvisit node v
	postCLK[v] = CLK;
	++CLK;
}
void dfs(int start) {
	memset(visited, false, sizeof(visited));
	explore(start);
}
void dfsAll() {
	memset(visited, false, sizeof(visited));
	for (int v = 1; v <= V; ++v)
		if (!visited[v])
			explore(v);
}

/*------------------------------------------ DFS by stack (less runtime - only 1 pass) -----------------------*/
bool visited[MAXV];
void dfs(int start) {
	memset(visited, false, sizeof(visited));

	stack<int> s;
	s.push(start);

	while (!s.empty()) {
		int v = s.top();
		s.pop();

		// Previsit node v
		// cout << v << endl;

		if (!visited[v]) {
			visited[v] = true;
			for (int i = 0; i < e[v].size(); ++i)
				if (!visited[e[v][i]]) {
					s.push(e[v][i]);

					// Previsit edge v - u
					// cout <<  wei[v][i]<< endl;
				}
		}
	}
}
