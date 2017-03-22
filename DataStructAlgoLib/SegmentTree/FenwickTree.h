// Build tree: O(nlogn)
//	query: O(logn)
//
//Example : https://www.youtube.com/watch?v=CWDQJGaN1gY&t=119s
//	Sum fenwick tree -> Query the sum of range[l,r] of the arg array
//		arg array = { 3, 2, -1, 6, 5, 4, -3, 3, 7, 2, 3 };	//size = 11
//		=> FT = { 0, 3, 5, -1, 10, 5, 9, -3, 19, 7, 9, 3 }; //size = 12
//
//	query: 
//		sum of range [0,10] = 31
//		sum of range [5,10] = 16
//		update(5,6) -> sum of range [5,10] = 22
//
//Note: index of FT start with 1
//		range of the query: [l,r]
class FenwickTree {
public:
	vector<int> ft;
public:
	FenwickTree(const vector<int>& arg) {
		ft.resize(arg.size() + 1);

		//Build tree
		for (int i = 0; i < arg.size(); ++i) {
			update(i, arg[i]);
		}
	}
	int getParent(int i) {
		return i - (i & -i);
	}
	int getNext(int i) {
		return i + (i & -i);
	}
	void update(int pos, int val) {
		for (int i = pos + 1; i < (int)ft.size(); i = getNext(i)) 
			ft[i] += val;
	}
	int sum(int i) {
		int sum = 0;
		while (i > 0) {
			sum += ft[i];
			i = getParent(i);
		}
		pr(sum);
		return sum;
	}
	int query(int l, int r) {
		return sum(r+1) - sum(l);
	}
};
