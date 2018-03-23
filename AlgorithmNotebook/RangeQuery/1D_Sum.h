

/*--------------------------------- Sum query -----------------------*/
// Build O(n), querry O(1)

//Array indexed 1: [1,n]
//     [1]1 [2]2 [3]3 [4]4 [5]5 [6]6 [7]7 [8]8
//          query(5,5) = 5
//          query(3,5) = 3 + 4 + 5 = 12
//          query(1,3) = 1 + 2 + 3 = 6
int a[MAXN];
int n;

int prefix_sum[MAXN];
void build() {
    memset(prefix_sum, 0, sizeof(prefix_sum));
    int sum_ = 0;
    for(int i=1; i <= n; ++i) {
        prefix_sum[i] = sum_ += a[i];
    }
}

// return sum of a in range [i,j]
int query(int i, int j) {
    return prefix_sum[j] - prefix_sum[i-1];
}



//Array indexed 0: [0,n-1]
//     [0]1 [1]2 [2]3 [3]4 [4]5 [5]6 [6]7 [7]8 
//          query(5,5) = 6
//          query(3,5) = 4 + 5 + 6 = 15
//          query(0,3) = 1 + 2 + 3 + 4 = 10
int a[MAXN];
int n;

int prefix_sum[MAXN];
void build() {
    memset(prefix_sum, 0, sizeof(prefix_sum));
    int sum_ = 0;
    for(int i=0; i < n; ++i) {
        prefix_sum[i] = sum_ += a[i];
    }
}

// return sum of a in range [i,j]
int query(int i, int j) {
    return prefix_sum[j] - prefix_sum[i-1];
}
