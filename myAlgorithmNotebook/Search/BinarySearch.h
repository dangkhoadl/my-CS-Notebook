
// A[left,right)
int binarySearch(int A[], int l, int r, int X) {
	--r;
	while (true) {
		if (l > r)
			return -1;

		int m = l + ((r - l) >> 1);
		if (A[m] == X)
			return m;

		if (X > A[m])
			l = m + 1;
		else
			r = m - 1;
	}
}
