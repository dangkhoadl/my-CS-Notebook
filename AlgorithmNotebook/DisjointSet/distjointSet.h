
//							DSU
// O(logn) for every operations

/*---------------------------- Update Data ---------------------------------------*/
int root_a = find(a);
int root_b = find(b);
if(root_a != root_b) {
    merge(a, b);
    int root = find(root_b);
    if(a == root)
        R[a] += R[b];           // Update if root_a is the new root
    else
        R[b] += R[a];           // Update if root_b is the new root


/*---------------------------- Simple DSU 1 ---------------------------------------*/
// init range: [1, n]
#define MAXN 20

int par_[MAXN];
int size_[MAXN];	// size of the corresponding set
void init(int n) {
	for(int i = 1; i <= n; ++i)
		par_[i] = i;
	fill(size_ + 1, size_ + n + 1, 1);
}
int find(int x) {
	while(x != par_[x])
		x = par_[x];
	return x;
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(size_[a] < size_[b])
		swap(a,b);
	size_[a] += size_[b];
	par_[b] = a;
}

/*---------------------------- Simple DSU 2 ---------------------------------------*/
// init range: [0, n)
#define MAXN 20

int par_[MAXN];
void init(int n) {
	memset(par_, -1, n * sizeof(int));
}
int find(int x) {
	return par_[x] < 0 ? x : (par_[x] = find(par_[x]));
}
void merge(int a, int b) {
	if ((a = find(a)) == (b = find(b)))
		return;
	
	if (par_[b] < par_[a]) 
		swap(a, b);
	
	par_[a] += par_[b];
	par_[b] = a;
}

/*---------------------------- DSU w/ struct ---------------------------------------*/
struct disjointSet {
public:
	vector<int> parent_;
	vector<int> rank_;
public:
	disjointSet(int n) {
		parent_.assign(n, 0);
		rank_.assign(n, 0);
	}
	void MakeSet(int i) {
		parent_[i] = i;
		rank_[i] = 0;
	}
	int Find(int x) {
		if (x != parent_[x])
			parent_[x] = Find(parent_[x]);
		return parent_[x];
	}
	void Merge(int a, int b) {
		int a_id = Find(a);
		int b_id = Find(b);
		if (a_id == b_id)
			return;

		if (rank_[a_id] > rank_[b_id])
			parent_[b_id] = a_id;
		else {
			parent_[a_id] = b_id;
			if (rank_[a_id] == rank_[b_id])
				++rank_[b_id];
		}
	}
};
