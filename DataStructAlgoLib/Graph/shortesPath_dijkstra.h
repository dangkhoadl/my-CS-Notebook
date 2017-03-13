
//												shortest path by dijkstra
/*--------------------------------------------------------------------------------------------------------------------------------*/
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

int dist[MAXV];
int pre[MAXV];
void dijkstra(int start) {
	memset(pre + 1, 0, V * sizeof(int));
	MinHeap pq;
	for (int v = 1; v <= V; ++v) {
		dist[v] = v == start ? 0 : inf;
		pq.insert({ dist[v] , v});
	}

	while (!pq.empty()) {
		int v = pq.extractMin();

		for(int i = 0; i < e[v].size(); ++i) 
			if (dist[e[v][i]] > dist[v] + wei[v][i]) {
				dist[e[v][i]] = dist[v] + wei[v][i];
				pre[e[v][i]] = v;

				//Change priority
				pq.changePriority({ dist[e[v][i]] , e[v][i] });
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

/*--------------------------------------------------------------------------------------------------------------------------------*/
const int MAXV = 1e6 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

int dist[MAXV];
int pre[MAXV];
void dijkstra(int start) {
	set<pair<int, int>> pq;
	for (int v = 1; v <= V; ++v) {
		dist[v] = v == start ? 0 : inf;
		pq.insert({ dist[v] , v });
	}
	
	while (pq.size() != 0) {
		int v = pq.begin()->second;
		pq.erase(pq.begin());

		for (int i = 0; i < e[v].size(); ++i) 
			if (dist[e[v][i]] > dist[v] + wei[v][i]) {
				if (dist[e[v][i]] != inf)
					pq.erase(pq.find({ dist[e[v][i]], e[v][i] } ));
				
				dist[e[v][i]] = dist[v] + wei[v][i];
				pre[e[v][i]] = v;
				pq.insert({ dist[e[v][i]] , e[v][i] });
			}
	}
}
