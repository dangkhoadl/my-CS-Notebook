
/*------------------------------------- DFS ---------------------------------------------------------------*/
const int MAXV = 1e6 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

bool visited[MAXV];

void explore(int v) {
	visited[v] = true;

	//Forward v
	

	for (int i = 0; i < e[v].size(); ++i) {
		//forward v - u
		

		if (!visited[e[v][i]])
			explore(e[v][i]);

		//backward v - u
		
	}

	//Backward v
	
}
void dfs(int v) {
	memset(visited, false, V);
	explore(v);
}
void dfsAll() {
	memset(visited, false, V);
	for (int v = 1; v <= V; ++v)
		explore(v);
}
/*--------------------------------------------------------------------------------------------------------*/
const int MAXV = 1e6 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

bool visited[MAXV];

void explore(int v) {
	visited[v] = true;

	//Forward v
	//cout << v << endl;

	for (int i = 0; i < e[v].size(); ++i) {
		//forward v - u
		//cout <<  wei[v][i]<< endl;

		if (!visited[e[v][i]])
			explore(e[v][i]);

		//backward v - u
		//cout <<  wei[v][i]<< endl;
	}

	//Backward v
	//cout << v << endl;
}
void dfs(int v) {
	memset(visited + 1, false, V);
	explore(v);
}
void dfsAll() {
	memset(visited + 1, false, V);
	for (int v = 1; v <= V; ++v)
		if(!visited[v])
		explore(v);
}
/*--------------------------------------------------------------------------------------------------------*/
//DFS by stack (less runtime - only 1 pass)
const int MAXV = 1e6 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

bool visited[MAXV];

void dfs(int start) {
	memset(visited + 1, false, V);

	stack<int> s;
	s.push(start);

	while (!s.empty()) {
		int v = s.top();
		s.pop();

		//process v
		cout << v << endl;

		if (!visited[v]) {
			visited[v] = true;
			for (int i = 0; i < e[v].size(); ++i)
				if (!visited[e[v][i]]) {
					s.push(e[v][i]);

					//process e

				}
		}
	}
}
/*--------------------------------------------- Pre/Post CLK-----------------------------------------------------------*/
const int MAXV = 1e6 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

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
void dfs(int v) {
	memset(visited + 1, false, V);
	explore(v);
}
void dfsAll() {
	memset(visited + 1, false, V);
	for (int v = 1; v <= V; ++v)
		if (!visited[v])
			explore(v);
}

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
	memset(visited + 1, false, V);
	label = 1;
	for (int v = 1; v <= V; ++v)
		if (!visited[v]) {
			explore(v);
			++label;
		}
}
