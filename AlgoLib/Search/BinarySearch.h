
// A[left,right)
int binarySearch(const int A[], int left, int right, int X) {
	--right;
	while(true) {
		int mid = left + (right - left) / 2;
		if (X == A[mid])
			return A[mid];
		if (left > right || X < A[left] || X > A[right])
			return -1;

		if (X > A[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
}
