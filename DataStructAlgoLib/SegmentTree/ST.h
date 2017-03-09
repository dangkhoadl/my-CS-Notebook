//Segment Tree
// start id must be 1 (left = 2 * i, right = 2* i + 1)
// l,r i,j base on index of arr :D
// build(1, 0, N - 1); strlen(s) - 1
// update(1, 0, N - 1, i , j); [i,j]
// query(1, 0, N - 1, i , j); [i,j]
#define MAXN 20
#define MAXTREE 4*MAXN+1 
#define inf 0x7FFFFFFF

int arr[MAXN];
struct Node{
	int data;
} ST[MAXTREE];

void build(int id, int l, int r) {
	if (l > r)
		return;

	if (l == r) {
		ST[id] = #####; // Case Leaf Node: interact w/ arr[], arr[l]
		return;
	}

	int mid = l + (r - l) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);

	ST[id] = #####; // Case Node with left, right child: interact w/ ST[2*id] ST[2*id+1]
}

void update(int id, int l, int r, int i, int j, int value) {
	if (l > r || l > j || r < i)
		return;

	if (l == r) {
		ST[id] = #####; // Case Leaf Node interact w/ value
		return;
	}

	int mid = l + (r - l) / 2;
	update(id * 2, l, mid, i, j, value);
	update(id * 2 + 1, mid + 1, r, i, j, value);

	ST[id] = #####; // Case Node with left, right child: interact w/ ST[2*id] ST[2*id+1]
}

Node query(int id, int l, int r, int i, int j) {
	if (l > r || l > j || r < i)
		return #####; // Case out of range, return INF or 0 depend on the algo

	if (l >= i && r <= j)
		return ST[id];

	int mid = l + (r - l) / 2;
	Node q1 = query(id * 2, l, mid, i, j);
	Node q2 = query(id * 2 + 1, mid + 1, r, i, j);

	return #####; //return interact w/ q1,q2
}
