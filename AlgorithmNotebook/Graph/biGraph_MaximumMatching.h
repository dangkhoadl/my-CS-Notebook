
//O(V * E^2)
//		Find max matching from set U(u1,u2...) -> set V(v1,v2,...)
//input:
//	U V
//	v1| u1 u2 u3 ...
//	v2| u1 u2 u3 ...
//	v3| u1 u2 u3 ...
//	...

//Example:
// 4 4
// 1 0 0 0
// 0 0 1 0
// 1 1 0 1
// 0 0 1 0

//read Input store
// 1 = source
// [2,U+1] = set U = u1,u2...
// [U+2, U+V+1] = set V = v1, v2...
// U+V+2 = sink

//maxMatching() return max number of match
//match() return {ui --> vi}
/********************************************* Maximum matching *************************************************************************************/
const int MAXV = 101;

int U, V;
vector<int> g[MAXV];
map<int,int> gWei[MAXV];
void readInput() {
	cin >> U >> V;
	for(int i = 2; i <= U+1; ++i) {
		g[1].push_back(i);
		gWei[1].insert( {i, 1} );
		g[i].push_back(1);
		gWei[i].insert( {1, 0} );
	}
	for(int i = U+2; i <= U+V+1; ++i) {
		g[i].push_back(U+V+2);
		gWei[i].insert( {U+V+2, 1} );
		g[U+V+2].push_back(i);
		gWei[U+V+2].insert( {i, 0} );
	}
	int temp;
	for(int u = 2; u <= U+1; ++u)
		for(int v = U+2; v <= U+V+1; ++v) {
			cin >> temp;
			if(temp) {
				g[u].push_back(v);
				gWei[u].insert( {v, 1} );
				g[v].push_back(u);
				gWei[v].insert( {u, 0} );
			}
		}
}
int pre[MAXV];
bool visited[MAXV];
int maxMatching() {
	int s = 1;
	int t = U + V + 2;
	int maxMatches = 0;

	//Repeat
	while(true) {
		// bfs to find path from s -> t
		memset(visited + 1, false, V+U+2);
		memset(pre + 1, -1, (V+U+2) * sizeof(int));
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
		
		//Update flow
		for(int v = t; v != s; v = pre[v]) {
			gWei[pre[v]][v] = 0;
			gWei[v][pre[v]] = 1;
		}
		++maxMatches;
	}
	return maxMatches;
}
vector<pair<int, int>> results;
void match() {
	for (int u = 2; u <= U + 1; ++u)
		for (int v = U + 2; v <= U + V + 1; ++v) 
			if (gWei[v][u] > 0)
				results.push_back( {u-1, v-U-1} );
}