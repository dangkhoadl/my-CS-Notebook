

/*------------------------------------------------------------
 a[N][M]: [0,0] -> [N-1,M-1]

build(1,0,0,N-1,M-1) - O(n*m) : build(a) 
update(1,0,0,N-1,M-1, i,j,val) - O(logn * logm) : update A_[i][j] = val
query(1,0,0,N-1,M-1, i1,j1,i2,j2) - O(logn * logm) : query [i1,j1] -> [i2,j2]
------------------------------------------------------------*/

class QuadTree {
public:
    vector<vector<int>> A_;
    int N, M;
private:
    vector<int> tree;
    void build(int idx, int a1, int b1, int a2, int b2) {
        if (a1 > a2 || b1 > b2) return;

        if(a1==a2 && b1==b2)
            tree[idx] = A_[a1][b1];
        else {
            int ma = a1+(a2-a1)/2;
            int mb = b1+(b2-b1)/2;
            build(4*idx - 2, a1, b1, ma, mb);
            build(4*idx - 1, ma+1, b1, a2, mb);
            build(4*idx    , a1, mb+1, ma, b2);
            build(4*idx + 1, ma+1, mb+1, a2, b2);

            /*---- Function: sum, min, max... ----*/
            tree[idx] = tree[4*idx-2] + tree[4*idx-1] + tree[4*idx] + tree[4*idx+1];
        }
    }
public:
    QuadTree(const vector<vector<int>> &a) : A_(a), N(a.size()) {
        M = a.size() > 0 ? a[0].size() : 0;
        tree.assign(1e6, 0);
        build(1, 0,0,N-1,M-1);
    }
    void update(int idx, int a1, int b1, int a2, int b2, int i, int j, int val) {
        if (a1 > a2 || b1 > b2) return;

        if(i == a1 && j == b1 && i == a2 && j == b2) {
            A_[i][j] = val;
            tree[idx] = val;
        }
        else {
            int ma = a1+(a2-a1)/2;
            int mb = b1+(b2-b1)/2;
            if(a1 <= i && i <= ma && b1 <= j && j <= mb)
                update(4*idx - 2, a1, b1, ma, mb, i, j, val);
            else if(ma < i && b1 <= j && j <= mb)
                update(4*idx - 1, ma+1, b1, a2, mb, i, j, val);
            else if(a1 <= i && i <= ma && mb < j)
                update(4*idx    , a1, mb+1, ma, b2, i, j, val);
            else 
                update(4*idx + 1, ma+1, mb+1, a2, b2, i, j, val);

            /*---- Function: sum, min, max... ----*/
            tree[idx] = tree[4*idx-2] + tree[4*idx-1] + tree[4*idx] + tree[4*idx+1];
        }
    }
    int query(int idx, int a1, int b1, int a2, int b2, int i1, int j1, int i2, int j2) {
        /*---- Note: Out-of-range vals ----*/
        if (a1 > a2 || b1 > b2) return 0;
        if(i1 > a2 || j1 > b2 || i2 < a1 || j2 < b1 || a1 > a2 || b1 > b2)
            return 0;

        if(i1 <= a1 && j1 <= b1 && a2 <= i2 && b2 <= j2)
            return tree[idx];

        int ma = a1+(a2-a1)/2;
        int mb = b1+(b2-b1)/2;
        int p1 = query(4*idx - 2, a1, b1, ma, mb, i1, j1, i2, j2);
        int p2 = query(4*idx - 1, ma+1, b1, a2, mb, i1, j1, i2, j2);
        int p3 = query(4*idx    , a1, mb+1, ma, b2, i1, j1, i2, j2);
        int p4 = query(4*idx + 1, ma+1, mb+1, a2, b2, i1, j1, i2, j2);

        /*---- Function: sum, min, max... ----*/
        return p1 + p2 + p3 + p4;
    }
};
