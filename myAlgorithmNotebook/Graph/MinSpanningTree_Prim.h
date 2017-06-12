
//												MST by Prim
/*--------------------------------------------------------------------------------------------------------------------------------*/
//								O(E*log(V))
const int MAXV = 1e6 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

struct MinHeap {
public:
	std::vector<std::pair<int, int>> H_;
public:
	void makeHeap() {
		std::make_heap(H_.begin(), H_.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {return a.first > b.first; });
	}
	void insert(std::pair<int, int>  p) {
		H_.push_back(p);
		std::push_heap(H_.begin(), H_.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {return a.first > b.first; });
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
		std::pop_heap(H_.begin(), H_.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {return a.first > b.first; });
		H_.pop_back();
		return min;
	}
	struct CompareSecond {
		CompareSecond(int val) : val_(val) {}
		bool operator()(const std::pair<int, int>& element) const {
			return val_ == element.second;
		}
	private:
		int val_;
	};
	bool exist(int z) {
		auto it = std::find_if(H_.begin(), H_.end(), CompareSecond(z));
		if (it != H_.end())
			return true;
		return false;
	}
	void changePriority(std::pair<int, int> p) {
		auto it = std::find_if(H_.begin(), H_.end(), CompareSecond(p.second));
		if (it != H_.end()) {
			it->first = p.first;
			std::make_heap(H_.begin(), H_.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {return a.first > b.first; });
		}
	}
};

int cost[MAXV]; //store the weight from i -> par[i]
int par[MAXV];	// root node of the tree (start) has par = 0
void prim(int start) {
	MinHeap H;
	memset(par + 1, 0, V * sizeof(int));
	for (int v = 1; v <= V; ++v) {
		cost[v] = v == start ? 0 : inf;
		H.insert({cost[v], v});
	}

	while (!H.empty()) {
		int v = H.extractMin();
		for (int i = 0; i < e[v].size(); ++i)
			if (H.exist(e[v][i]) && cost[e[v][i]] > wei[v][i]) {
				cost[e[v][i]] = wei[v][i];
				par[e[v][i]] = v;
				H.changePriority({cost[e[v][i]], e[v][i]});
			}
	}
}

/*-------------------------------------------------------- Use set ------------------------------------------------------------------------*/
// O(E*log(V))
int cost[MAXV]; //store the weight from i -> pre[i]
int pre[MAXV];	//tree dont have root but segment 
void prim() {
	fill(cost + 1, cost + V + 1, inf);
	fill(pre + 1, pre + V + 1, 0);

	set<pair<int, int>> s;
	for (int v = 1; v <= V; ++v)
		s.insert({ cost[v], v });

	while (!s.empty()) {
		int v = s.begin()->second;
		s.erase(s.begin());

		for(int i=0; i<e[v].size(); ++i)
			if (cost[e[v][i]] > wei[v][i]) {
				s.erase({ cost[e[v][i]], e[v][i] });

				//Update
				cost[e[v][i]] = wei[v][i];
				pre[e[v][i]] = v;

				s.insert({cost[e[v][i]], e[v][i]});
			}
	}
}

