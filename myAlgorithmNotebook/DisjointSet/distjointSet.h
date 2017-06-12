
//							DSU
//			init range: [0, num)
/*-------------------------------------------------------------------*/
#define MAXN 20
int par_[MAXN];

void init(int num) {
	memset(par_, -1, num * sizeof(int));
}

int find(int v) {
	return par_[v] < 0 ? v : (par_[v] = find(par_[v]));
}

void merge(int x, int y) {
	if ((x = find(x)) == (y = find(y)))
		return;
	
	if (par_[y] < par_[x]) 
		swap(x, y);
	
	par_[x] += par_[y];
	par_[y] = x;
}

/*-------------------------------------------------------------------*/
struct disjointSet {
public:
	std::vector<int> parent_;
	std::vector<int> rank_;
public:
	disjointSet(int n) {
		parent_.assign(n, 0);
		rank_.assign(n, 0);
	}
	void MakeSet(int i) {
		parent_[i] = i;
		rank_[i] = 0;
	}
	int Find(int i) {
		if (i != parent_[i])
			parent_[i] = Find(parent_[i]);
		return parent_[i];
	}
	void Union(int i, int j) {
		int i_id = Find(i);
		int j_id = Find(j);
		if (i_id == j_id)
			return;

		if (rank_[i_id] > rank_[j_id])
			parent_[j_id] = i_id;
		else {
			parent_[i_id] = j_id;
			if (rank_[i_id] == rank_[j_id])
				++rank_[j_id];
		}
	}
};

/*-------------------------------------------------------------------*/
#define MAXN 20
int par_[MAXN];
int rank_[MAXN];

void makeSet(int i) {
	par_[i] = i;
	rank_[i] = 0;
}

void init(int num) {
	for (int i = 0; i < num; ++i)
		makeSet(i);
}

int find(int i) {
	if (i != par_[i])
		par_[i] = find(par_[i]);
	return par_[i];
}

void merge(int i, int j) {
	int i_id = find(i);
	int j_id = find(j);
	if (i_id == j_id)
		return;

	if (rank_[i_id] > rank_[j_id])
		par_[j_id] = i_id;
	else {
		par_[i_id] = j_id;
		if (rank_[i_id] == rank_[j_id])
			++rank_[j_id];
	}
}
