const int MAXV = 21;

int V;
int par[MAXV];
vector<int> child[MAXV];
int val[MAXV];
int root;
/*-----------------------------------------------------------------------------------------------------------------*/
void bfs(int start) {
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		//Process
		

		//Enqueue
		for (int i = 0; i < child[x].size(); ++i)
			q.push(child[x][i]);
	}
}
