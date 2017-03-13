/*------------------------------------- BFS ---------------------------------------------------------------*/
const int MAXV = 1e6 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

int edgeDist[MAXV]; // store the number of edges from start to all other vertices

void bfs(int start) {
	memset(edgeDist + 1, -1, V * sizeof(int));
	edgeDist[start] = 0;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		//Process
		//cout << v << endl;

		for (int i = 0; i < e[v].size(); ++i) {
			if (edgeDist[e[v][i]] == -1) {
				q.push(e[v][i]);

				//update
				edgeDist[e[v][i]] = edgeDist[v] + 1;
			}
		}
	}
}
/*------------------------------------- shortest path tree ---------------------------------------------------------------*/
const int MAXV = 1e6 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];


int edgeDist[MAXV]; // store the number of edges from start to all other vertices
int pre[MAXV];

void bfs(int start) {
	memset(edgeDist + 1, -1, V * sizeof(int));
	memset(pre + 1, -1, V * sizeof(int));
	edgeDist[start] = 0;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < e[v].size(); ++i) {
			if (edgeDist[e[v][i]] == -1) {
				q.push(e[v][i]);

				//update
				edgeDist[e[v][i]] = edgeDist[v] + 1;
				pre[e[v][i]] = v;
			}
		}
	}
}

vector<int> reconstructSPT(int start, int end) {
	vector<int> res;
	int v = end;
	while (v != start) {
		res.push_back(v);
		v = pre[v];
		
	}
	res.push_back(start);
	reverse(res.begin(), res.end());
	return res;
}
