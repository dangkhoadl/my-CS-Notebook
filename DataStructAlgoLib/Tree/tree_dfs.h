const int MAXEDGE = 21;
int n;
int par[MAXEDGE];
int dat[MAXEDGE];

int root;
vector<int> child[MAXEDGE];
int dep[MAXEDGE];
int hei[MAXEDGE];

/*-----------------------------------------------------------------------------------------------------------------*/
//dfs(root);
void dfs(int x) {
	//PreProcess x

	for_i(0, sz(child[x]), 1) {
		//Preprocess x[child]

		//DFS
		dfs(child[x][i]);

		//PostProcess x[child]
	}

	//PostProcess x
	
}

/*--------------------------------------------------DFS to find depth ---------------------------------------------------------------*/
//dep[root] = 0;
//dfs(root);
void dfs(int x) {
	//PreProcess x
	printf("Node[%lld]: data = %lld, depth from root = %lld\n", x, dat[x], dep[x]);

	for (int i = 0; i < child[x].size(); ++i) {
		//PreProcess x[child]
		dep[child[x][i]] = dep[x] + 1;
		//printf("Node[%lld]: data = %lld, depth from root = %lld\n", child[x][i], dat[child[x][i]], dep[child[x][i]]);

		dfs(child[x][i]);

		//PostProcess x[child]
		//printf("Node[%lld]: data = %lld, depth from root = %lld\n", child[x][i], dat[child[x][i]], dep[child[x][i]]);
	}

	//PostProcess x
	//printf("Node[%lld]: data = %lld, depth from root = %lld\n", x, dat[x], dep[x]);
}

/*----------------------------------------------- DFS to find height ------------------------------------------------------------------*/
void dfs(int x) {
	int maxChildHei = 0;
	for (int i = 0; i < child[x].size(); ++i) {
		dfs(child[x][i]);

		//PostProcess x[child]
		maxChildHei = max(maxChildHei, hei[child[x][i]]);
	}

	//PostProcess x
	hei[x] = maxChildHei + 1;
}
