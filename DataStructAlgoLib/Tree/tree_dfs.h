const int MAXEDGE = 21;
int n;
int par[MAXEDGE];
int dat[MAXEDGE];

int root;
vector<int> child[MAXEDGE];
int dep[MAXEDGE];

/*------------------------------------- FUNCTIONS ---------------------------------------------------------------*/

//dep[root] = 0;
//dfs(root);
void dfs(int x) {
	for(int i=0; i < child[x].size(); ++i) {
		dep[child[x][i]] = dep[x] + 1;

		//PreProcess
		printf("Node[%lld]: data = %lld, depth from root = %lld\n", child[x][i], dat[child[x][i]], dep[child[x][i]]);

		dfs(child[x][i]);

		//PostProcess
		//printf("Node[%lld]: data = %lld, depth from root = %lld\n", child[x][i], dat[child[x][i]], dep[child[x][i]]);
	}
}
