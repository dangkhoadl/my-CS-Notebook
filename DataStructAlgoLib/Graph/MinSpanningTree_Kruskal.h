
//												MST by Kruskal
/*--------------------------------------------------------------------------------------------------------------------------------*/
const int MAXV = 1e6 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

struct Set {
public:
	std::vector<int> parent;
	std::vector<int> rank;
public:
	Set(int n) {
		parent.assign(n, 0);
		rank.assign(n, 0);
	}
	void MakeSet(int i) {
		parent[i] = i;
		rank[i] = 0;
	}
	int Find(int i) {
		if (i != parent[i])
			parent[i] = Find(parent[i]);
		return parent[i];
	}
	void Union(int i, int j) {
		int i_id = Find(i);
		int j_id = Find(j);
		if (i_id == j_id)
			return;

		if (rank[i_id] > rank[j_id])
			parent[j_id] = i_id;
		else {
			parent[i_id] = j_id;
			if (rank[i_id] == rank[j_id])
				++rank[j_id];
		}
	}
};

vector<int> pathwei;
void Kruskal() {
	Set S(V+1);
	for (int v = 1; v <= V; ++v)
		S.MakeSet(v);

	priority_queue< pair<int, pair<int, int>>> H;
	for (int v = 1; v <= V; ++v)
		for (int i = 0; i < e[v].size(); ++i)
			H.push({ -wei[v][i], {v, e[v][i]} });

	while (!H.empty()) {
		int we = -H.top().first;
		int v = H.top().second.first;
		int w = H.top().second.second;
		H.pop();

		if (S.Find(v) != S.Find(w)) {
			pathwei.push_back(we);
			S.Union(v, w);
		}
	}
}
/*--------------------------------------------------------------------------------------------------------------------------------*/

