

/*------------------------------------------------------------
 a[N]: [0,N-1]

build(1,0,N-1) - O(n) : build(a) 
update(1,0,N-1, i,val) - O(logn) : update A_[i] = val
query(1,0,N-1, i,j) - O(logn) : query [i,j]
------------------------------------------------------------*/
class SegmentTree {
public:
    vector<int> A_;
    int N;
private:
    vector<int> tree;
    void build(int idx, int l, int r) {
        if(l == r)
            tree[idx] = A_[l];      
        else {
            int m = l+(r-l)/2;
            build(2*idx, l, m);
            build(2*idx+1, m+1, r);

            /*---- Function: sum, min, max... ----*/
            tree[idx] = tree[2*idx] + tree[2*idx+1];
        }
    }
public:
    SegmentTree(const vector<int> &a) : A_(a), N(a.size()) {
        tree.assign(4*N, 0);
        build(1,0,N-1);
    }
    void update(int idx, int l, int r, int i, int val) {
        if(l == r) {
            A_[i] = val;
            tree[idx] = val;
        }
        else {
            int m = l+(r-l)/2;
            if(l <= i && i <= m)
                update(2*idx, l, m, i, val);
            else
                update(2*idx+1, m+1, r, i, val);

            /*---- Function: sum, min, max... ----*/
            tree[idx] = tree[2*idx] + tree[2*idx+1];
        }
    }
    int query(int idx, int l, int r, int i, int j) {
        /*---- Note: Out-of-range vals ----*/
        if(j < l || r < i)
            return 0;
        if(i <= l && r <= j)
            return tree[idx];

        int m = l+(r-l)/2;
        int p1 = query(2*idx, l, m, i, j);
        int p2 = query(2*idx+1, m+1, r, i, j);

        /*---- Function: sum, min, max... ----*/
        return p1 + p2;
    }
};
