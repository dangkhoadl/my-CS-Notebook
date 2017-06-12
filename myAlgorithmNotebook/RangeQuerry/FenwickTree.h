
/*------------------------------------- BIT Sum querry ---------------------------------------------------------------*/
//Array indexed 1: [1,n]
int a[100];
int n;

int tree[100];
//Update tree when a[i] += val
void add(int val, int i) {			
	for (; i <= n; i += i&-i) {
		tree[i] += val;
	}
}
//Update tree @ the first time
void buildtree() {
	memset(tree, 0, sizeof(tree));
	for (int i = 1; i <= n; ++i)
		add(a[i], i);
}


//Querry
// return sum of a in range [1,i]
int sum(int i) {				
	int sum_ = 0;
	for (; i >= 1; i -= i & -i) 
		sum_ += tree[i];
	return sum_;
}
// return sum of a in range [i,j]
int querry(int i, int j) {
	return sum(j) - sum(i - 1);
}
