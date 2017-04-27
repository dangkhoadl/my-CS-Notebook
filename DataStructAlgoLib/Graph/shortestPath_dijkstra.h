
//												shortest path by dijkstra
/*--------------------------------------------------------------------------------------------------------------------------------*/
// O( (V+E) * log(V))

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

int dist[MAXV];		// Store the distance from start -> i
int pre[MAXV];		// store the path
void dijkstra(int start) {
	memset(pre + 1, 0, V * sizeof(int));
	fill(dist + 1, dist + V + 1, inf);
	dist[start] = 0;

	MinHeap pq;
	for (int v = 1; v <= V; ++v) 
		pq.insert({ dist[v] , v});
	
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

/*------------------------------------------------- Use set -------------------------------------------------------------------------------*/
const int MAXV = 1e6 + 1;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

int dist[MAXV];
int pre[MAXV];
void dijkstra(int start) {
	fill(pre + 1, pre + V + 1, inf);
	fill(dist + 1, dist + V + 1, inf);
	dist[start] = 0;

	set<pair<int, int>> s;
	s.insert({dist[start], start});

	while (!s.empty()) {
		int v = s.begin()->second;
		s.erase(s.begin());

		for (int i = 0; i < e[v].size(); ++i)
			if (dist[e[v][i]] > dist[v] + wei[v][i]) {
				//Update
				s.erase({ dist[e[v][i]], e[v][i] } );

				//Relax
				dist[e[v][i]] = dist[v] + wei[v][i];
				pre[e[v][i]] = v;

				//Update
				s.insert({ dist[e[v][i]], e[v][i] });
			}
	}
}

/*------------------------------------------------- Use PQ 1 -------------------------------------------------------------------------------*/
int dist[MAXV];		// Store the distance from start -> i
int pre[MAXV];		// store the path
bool visited[MAXV];
void dijkstra(int start) {
	fill(visited + 1, visited + V + 1, false);
	fill(pre + 1, pre + V + 1, inf);
	fill(dist + 1, dist + V + 1, inf);
	dist[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > > pq;
	pq.push({dist[start], start});

	while (!pq.empty()) {
		int v = pq.top().second;
		pq.pop();

		if (visited[v])
			continue;
		visited[v] = true;

		for (int i = 0; i < e[v].size(); ++i)
			if (dist[e[v][i]] > dist[v] + wei[v][i]) {

				//Relax
				dist[e[v][i]] = dist[v] + wei[v][i];
				pre[e[v][i]] = v;

				//Update
				pq.push({ dist[e[v][i]], e[v][i] });
			}
	}
}

/*------------------------------------------------- Use PQ 2 -------------------------------------------------------------------------------*/
int dist[MAXV];		// Store the distance from start -> i
int pre[MAXV];		// store the path
bool visited[MAXV];
void dijkstra(int start) {
	fill(visited + 1, visited + V + 1, false);
	fill(pre + 1, pre + V + 1, inf);
	fill(dist + 1, dist + V + 1, inf);
	dist[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ -dist[start], start });

	while (!pq.empty()) {
		int v = pq.top().second;
		pq.pop();

		if (visited[v])
			continue;
		visited[v] = true;

		for (int i = 0; i < e[v].size(); ++i)
			if (dist[e[v][i]] > dist[v] + wei[v][i]) {

				//Relax
				dist[e[v][i]] = dist[v] + wei[v][i];
				pre[e[v][i]] = v;

				//Update
				pq.push({ -dist[e[v][i]], e[v][i] });
			}
	}
}
