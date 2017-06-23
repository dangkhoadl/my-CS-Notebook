// O(V + E)

const int MAXV = 21;
int V;
vector<int> e[MAXV];
int val[MAXV];

/*********************************************************************/
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
void dfs(int start) {
	memset(visited + 1, false, V);
	explore(start);
}
