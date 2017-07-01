
/*------------------------------------- Segment tree Sum querry ---------------------------------------------------------------*/
const int MAXSIZE = 101;
int a[MAXSIZE]; //Array indexed 1: [1,n]
int n; //Note: n must be power of 2: 1,2,4,8,16...


int parent(int i) {
	return i / 2;
}
int leftChild(int i) {
	return 2 * i;
}
int rightChild(int i) {
	return 2 * i + 1;
}


int tree[2*MAXSIZE];
//Update tree when a[i] += val
void add(int val, int i) {
	i += (n-1);
	tree[i] += val;
	for(i = parent(i); i >= 1; i = parent(i))
		tree[i] = tree[leftChild(i)] + tree[rightChild(i)];
}
//Update tree @ the first time
void buildtree() {
	memset(tree, 0, sizeof(tree));
	for(int i = 1; i <= n; ++i)
		add(a[i], i);
}


// return sum of a in range [i,j]
int querry(int i, int j) {
	i += (n - 1);
	j += (n - 1);

	int sum_ = 0;
	for (; i <= j; i = parent(i), j = parent(j)) {
		if (i % 2 == 1)
			sum_ += tree[i++];
		if (j % 2 == 0)
			sum_ += tree[j--];
	}
	return sum_;
}
