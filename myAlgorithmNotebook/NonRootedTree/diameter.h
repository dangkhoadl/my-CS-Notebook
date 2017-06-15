// Diameter = max distance between 2 leaves in a tree


int edgeDist[MAXV]; // store the number of edges from start to all other vertices
void bfs(int start) {
	memset(edgeDist + 1, -1, V * sizeof(int));
	edgeDist[start] = 0;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < e[v].size(); ++i) {
			if (edgeDist[e[v][i]] == -1) {
				q.push(e[v][i]);
				edgeDist[e[v][i]] = edgeDist[v] + 1;
			}
		}
	}
}
pair<int,int> diameter() {
	bfs(1);
	int maxDist = -1;
	int a = 0;
	int b = 0;
	for(int i = 1; i <= V; ++i) 
		if (maxDist < edgeDist[i]) {
			maxDist = edgeDist[i];
			a = i;
		}

	bfs(a);
	maxDist = -1;
	for (int i = 1; i <= V; ++i)
		if (maxDist < edgeDist[i]) {
			maxDist = edgeDist[i];
			b = i;
		}
	return{ a,b };
}
