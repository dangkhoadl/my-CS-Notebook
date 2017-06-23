const int MAXV = 21;

int V;
int par[MAXV];
vector<int> child[MAXV];
int root;
/*--------------------------------------------- Simple dfs --------------------------------------------------------------------*/
void dfs(int x) {
	//Process x

	for(int i = 0; i < child[x].size(); ++i) {
		dfs(child[x][i]);
	}
}


/***************************************************************** DP on tree *************************************************************************************/
//dfs(root);
void dfs(int x) {
	//PreProcess x

	for (int i = 0; i < child[x].size(); ++i) {
		//Preprocess x[child]

		dfs(child[x][i]);
		//PostProcess x[child]
		
	}
	//PostProcess x
	
}
/*--------------------------------------------------DFS to find number of node in subtree ------------------------------------------------*/
int cnt[MAXV];
void dfs(int x) {
	cnt[x] = 1;
	for(int i = 0; i < child[x].size(); ++i) {
		dfs(child[x][i]);
		cnt[x] += cnt[child[x][i]];
	}
}

/*--------------------------------------------------DFS to find depth ---------------------------------------------------------------*/
//Init
//dep[root] = 1;
int dep[MAXV];
void dfs(int x) {
	for (int i = 0; i < child[x].size(); ++i) {
		dep[child[x][i]] = dep[x] + 1;
		dfs(child[x][i]);
	}
}

/*----------------------------------------------- DFS to find height ------------------------------------------------------------------*/
int hei[MAXV];
void dfs(int x) {
	int maxChildHei = 0;
	for (int i = 0; i < child[x].size(); ++i) {
		dfs(child[x][i]);
		maxChildHei = max(maxChildHei, hei[child[x][i]]);
	}
	hei[x] = maxChildHei + 1;
}
