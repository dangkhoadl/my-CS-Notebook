
//                          DSU
// O(logn) for every operations

/*---------------------------- Simple DSU ---------------------------------------*/
// init range: [1, n]
#define MAXN 20

int par_[MAXN];
int size_[MAXN];    // size of the corresponding set
int id_[MAXN];      // all ids of the set: After Update elements in the same subsets have the same id(= root element)
void init(int n) {
    for(int i = 1; i <= n; ++i)
        par_[i] = i;
    fill(size_ + 1, size_ + n + 1, 1);
}
int Find(int x) {
    while(x != par_[x])
        x = par_[x];
    return x;
}
void Merge(int a, int b) {
    a = Find(a);
    b = Find(b);
    if(size_[a] < size_[b])
        swap(a,b);
    size_[a] += size_[b];
    par_[b] = a;
}
// Update set IDs: elements in the same subsets have the same id(= root element)
void Update(int n) {
    for(int i=1; i<=n; ++i) {
        int x = i;
        while(x != par_[x]) x = par_[x];
        id_[i] = x;
    }
}


/*---------------------------- DSU w/ struct ---------------------------------------*/
// init range: [0, n)
struct disjointSet {
public:
    vector<int> parent_;
    vector<int> rank_;
    vector<int> id_;
public:
    disjointSet(int n) {
        rank_.assign(n, 0);
        parent_.assign(n, 0);
        id_.assign(n, -1);
        for(int i=0; i<n; ++i) parent_[i] = i;
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
    // Update set IDs: elements in the same subsets have the same id(= root element)
    void Update() {
        for(int i=0; i<id_.size(); ++i) {
            int x = i;
            while(x != parent_[x]) x = parent_[x];
            id_[i] = x;
        }
    }
};
