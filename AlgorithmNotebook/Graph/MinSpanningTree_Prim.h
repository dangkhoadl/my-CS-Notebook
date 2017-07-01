
//								Prim: O(V + Elog(E))
const int MAXV = 1e6 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];
/*------------------------------------------------- Use pq -------------------------------------------------------------------------------*/
int cost[MAXV];
int pre[MAXV];
bool processed[MAXV];
void prim(int start) {
	fill(processed + 1, processed + V + 1, false);
	fill(pre + 1, pre + V + 1, 0);
	fill(cost + 1, cost + V + 1, inf);
	cost[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ -cost[start], start });

	while (!pq.empty()) {
		int v = pq.top().second;
		pq.pop();

		if (processed[v])
			continue;
		processed[v] = true;

		for (int i = 0; i < e[v].size(); ++i) {
			if (cost[e[v][i]] > wei[v][i] && e[v][i] != pre[v]) {
				//Relax
				cost[e[v][i]] = wei[v][i];
				pre[e[v][i]] = v;

				//Update
				pq.push({ -cost[e[v][i]], e[v][i] });
			}
		}
	}
}

/*-------------------------------------------------------- Struct ------------------------------------------------------------------------*/
struct MinHeap {
public:
	vector<pair<int, int>> H_;
public:
	void makeHeap() {
		make_heap(H_.begin(), H_.end(), [](const pair<int, int> &a, const pair<int, int> &b) {return a.first > b.first; });
	}
	void insert(pair<int, int>  p) {
		H_.push_back(p);
		push_heap(H_.begin(), H_.end(), [](const pair<int, int> &a, const pair<int, int> &b) {return a.first > b.first; });
	}
	bool empty() {
		if (H_.size() == 0)
			return true;
		return false;
	}
	int getMin() {
		return H_.front().second;
	}
	int extractMin() {
		int min = H_.front().second;
		pop_heap(H_.begin(), H_.end(), [](const pair<int, int> &a, const pair<int, int> &b) {return a.first > b.first; });
		H_.pop_back();
		return min;
	}
	struct CompareSecond {
		CompareSecond(int val) : val_(val) {}
		bool operator()(const pair<int, int>& element) const {
			return val_ == element.second;
		}
	private:
		int val_;
	};
	bool exist(int z) {
		auto it = find_if(H_.begin(), H_.end(), CompareSecond(z));
		if (it != H_.end())
			return true;
		return false;
	}
	void changePriority(pair<int, int> p) {
		auto it = find_if(H_.begin(), H_.end(), CompareSecond(p.second));
		if (it != H_.end()) {
			it->first = p.first;
			make_heap(H_.begin(), H_.end(), [](const pair<int, int> &a, const pair<int, int> &b) {return a.first > b.first; });
		}
	}
};

int cost[MAXV]; // store the weight from i -> pre[i]
int pre[MAXV];	// root node of the tree (start) has pre = 0
void prim(int start) {
	MinHeap H;
	memset(pre + 1, 0, V * sizeof(int));
	for (int v = 1; v <= V; ++v) {
		cost[v] = (v == start) ? 0 : inf;
		H.insert({cost[v], v});
	}

	while (!H.empty()) {
		int v = H.extractMin();
		for (int i = 0; i < e[v].size(); ++i)
			if (H.exist(e[v][i]) && cost[e[v][i]] > wei[v][i]) {
				cost[e[v][i]] = wei[v][i];
				pre[e[v][i]] = v;
				H.changePriority({cost[e[v][i]], e[v][i]});
			}
	}
}
