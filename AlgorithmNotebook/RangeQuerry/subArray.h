
// Build O(n), Update O(n), querry O(1)

//Array indexed 1: [1,n]
int a[100];
int n;

int sum[100];
void build() {
	memset(sum, 0, sizeof(sum));
	int sum_ = 0;
	for(int i=1; i <= n; ++i) {
		sum[i] = sum_ += a[i];
	}
}

// return sum of a in range [i,j]
int query(int i, int j) {
	return sum[j] - sum[j-1];
}
