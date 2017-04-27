const int MAXEDGE = 21;
int n;
int par[MAXEDGE];
int dat[MAXEDGE];

int root;
vector<int> child[MAXEDGE];
/*-----------------------------------------------------------------------------------------------------------------*/
void bfs(int x) {
	queue<int> q;
	q.push(x);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		//Process
		printf("%lld\n", node);

		//Enqueue
		for (int i = 0; i < child[node].size(); ++i)
			q.push(child[node][i]);
	}
}
