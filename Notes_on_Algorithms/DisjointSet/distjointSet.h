
//                          DSU
//    find, merge: O(log(n))
//    getID: O(nlog(n))

// init range: [0, n)
class disjointSet {
private:
    vector<int> par_;
    vector<int> rank_;
    vector<int> id_;
public:
    disjointSet(int n) {
        this->rank_.assign(n, 0);
        this->id_.assign(n, 0);
        this->par_.assign(n, 0);
        for(int i=0; i<n; ++i) id_[i] = par_[i] = i;
    }
    int find(int x) {
        if(x != par_[x]) par_[x] = find(par_[x]);
        return par_[x];
    }
    void merge(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a == root_b)
            return;

        if (rank_[root_a] > rank_[root_b])
            par_[root_b] = root_a;
        else {
            par_[root_a] = root_b;
            if (rank_[root_a] == rank_[root_b])
                ++rank_[root_b];
        }
    }

    // Update IDs: elements in the same subsets have the same id(= root of subset)
    vector<int> getID() {
        for(int i=0; i<id_.size(); ++i) id_[i] = find(i);
        return id_;
    }
    // get number of sets
    int getNumset() {
        unordered_set<int> roots;
        for(int i=0; i<id_.size(); ++i) {
            id_[i] = find(i);
            roots.insert(id_[i]);
        }
        return roots.size();
    }
};
