
// O (log n)
/***************************** Lowest Common Ancestor ******************************************************/

// init range: [1, n]
#define MAXN 20

int par_[MAXN];
int size_[MAXN];    // size of the corresponding set
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
void merge(int a, int b) {  // Modify merge --> the highest node == parent
    a = find(a);
    b = find(b);
    size_[a] += size_[b];
    par_[b] = a;
}
//-------------------------- LCA(a,b) ------------------------
int lca, firstV;
void dfs(int x, int a, int b) {
    for (int i = 0; i < child[x].size(); ++i) 
        dfs(child[x][i],a,b);
    
    if (x == a && firstV == 0)
        firstV = a;
    if (x == b && firstV == 0)
        firstV = b;
    if (firstV != 0 && x == b)
        lca = find(a);
    if (firstV != 0 && x == a)
        lca = find(b);  
    merge(par[x], x);
}
int LCA(int a, int b) {
    init(V);
    firstV = 0;
    dfs(root,a,b);
    return lca;
}
