
// O( V + E)
// Input format: L = (x2 v -x1) (-x1 v x2) (x1 v x3) (-x2 v -x3) (x1 v x4)
//
// 2 -1
// -1 -2
// 1 3
// -2 -3
// 1 4

// Algo:
//		Find x1,x2,x3,x4 satisfy the L (L true)
//		Ex: L = (x2 v -x1) (-x1 v x2) (x1 v x3) (-x2 v -x3) (x1 v x4)
//		- create graph with (a v b) = 
// 				(-a)----->(b)
//				(-b)----->(a)
// 			- my rule: 
//					   a = i * 2 - 1
//					  -a = i * 2
//			- Ex: 
//				a1: a1 = (1)   and -a1  = (2)
//				a2: a2 = (3)   and -a2 = (4)
//
//		- Check SCC by kosaraju
//			- if -a and a in the same group ---> false;
//
//		- Yield result
//			- Start the last group of SCC
//				Ex: A = (-x4), B = (x1,x2,-x3), C = (-x1, -x2, x3), D = (x4)
//					Start w/ D -> x4 = true
//							 C -> x3 = true, x2 = false, x1 = false
//							 ...
//			- Final result
//					x1 = false, x2 =false, x3 = true, x4 = true	

/* ------------------------------------------------ 2SAT ----------------------------------------------------------------------------- */

const int MAXV = 101;

vector<pair<int,int>> sat;
void readInput() {
	long long a,b;
	while(scanf("%lld %lld", &a, &b) > 0)
		sat.push_back( {a,b} );
}
vector<int> e[MAXV];
int V=0;
void createGraph() {
	for(int i = 0; i < sat.size(); ++i) {
		int a = sat[i].first;
		int b = sat[i].second;
		V = max(V, abs(a) * 2);
		V = max(V, abs(b) * 2);

		int va, va_, vb, vb_;
		
		if(a > 0) {
			va = a*2 - 1;
			va_ = a*2; 
		}
		else {
			va = -a*2;
			va_ = -a*2 - 1;
		}

		if (b > 0) {
			vb = b * 2 - 1;
			vb_ = b * 2;
		}
		else {
			vb = -b * 2;
			vb_ = -b * 2 - 1;
		}

		e[va_].push_back(vb);
		e[vb_].push_back(va);
	}
}
// ------------------------------------------------ kosaraju ---------------------------
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
bool processed[MAXV];
bool res[MAXV];
bool twoSat() {
	memset(res + 1, false, V/2);
	createGraph();
	kosaraju();

	//check SCC
	for(int i = 0; i < SCC.size(); ++i) {
		memset(processed + 1, false, V/2);
		for(int j = 0; j < SCC[i].size(); ++j) {
			if (SCC[i][j] % 2 == 0) {
				if(processed[SCC[i][j]/2])
					return false;
				processed[SCC[i][j]/2] = true;
			}
			else {
				if(processed[(SCC[i][j] + 1)/2])
					return false;
				processed[(SCC[i][j] + 1)/2] = true;
			}
		}
	}

	// Yield Result
	memset(processed + 1, false, V / 2);
	for(int i = SCC.size()-1; i >= 0; --i)
		for (int j = 0; j < SCC[i].size(); ++j) {
			if (SCC[i][j] % 2 != 0 && !processed[(SCC[i][j] + 1) / 2]) {
				res[(SCC[i][j] + 1) / 2] = true;
				processed[(SCC[i][j] + 1) / 2] = true;
			}
			else if (SCC[i][j] % 2 == 0 && !processed[SCC[i][j] / 2]) {
				processed[SCC[i][j] / 2] = true;
			}
		}

	return true;
}
