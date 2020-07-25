
// Build: Nlog(N)
// Update: log(N)
// Query: log(N)


int N;
vector<int> A;
    // A start from 0

vector<int> tree;
    // tree start from 1

void build_tree(const vector<int> &A, vector<int> &tree,
        int start_, int end_, int treeNode_) {
        // tree.assign(4*N, 0);
        // build_tree(A, tree, 0, N-1, 1);
    if(start_ == end_) {
        tree[treeNode_] = A[start_];
        return;
    }

    int mid_ = start_ + (end_ - start_) / 2;
    build_tree(A, tree, start_, mid_, 2*treeNode_);
    build_tree(A, tree, mid_+1, end_, 2*treeNode_+1);

    // [Sum tree]
    tree[treeNode_] = tree[2*treeNode_] + tree[2*treeNode_ + 1];
}
void update_tree(vector<int> &A, vector<int> &tree,
        int idx, int val,
        int start_, int end_, int treeNode_) {
        // Update A[idx] = val
        //      update_tree(A, tree, idx, val, 0, N-1, 1);
    if(start_ == end_) {
        A[idx] = val;
        tree[treeNode_] = val;
        return;
    }

    int mid_ = start_ + (end_ - start_) / 2;
    if(idx > mid_) update_tree(A, tree, idx, val, mid_+1, end_, 2*treeNode_+1);
    else update_tree(A, tree, idx, val, start_, mid_, 2*treeNode_);

    // [Sum tree]
    tree[treeNode_] = tree[2*treeNode_] + tree[2*treeNode_+1];
}
int query_tree(const vector<int> &tree,
        int l, int r,
        int start_, int end_, int treeNode_) {
        // query_tree(tree, l, r, 0, N-1, 1);

    // Completely outside gven range - [Sum tree]
    if(start_ > r || end_ < l) return 0;

    // Completely inside given range
    if(start_ >= l && end_ <= r) return tree[treeNode_];

    // Partially inside, partially outside
    int mid_ = start_ + (end_ - start_) / 2;
    int ans1 = query_tree(tree, l, r, start_, mid_, 2*treeNode_);
    int ans2 = query_tree(tree, l, r, mid_+1, end_, 2*treeNode_+1);

    // [Sum tree]
    return ans1 + ans2;
}
