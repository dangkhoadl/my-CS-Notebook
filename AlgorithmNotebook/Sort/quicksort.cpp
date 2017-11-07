
// [left, right]
// Unstable
// Time complexity - Avg: O(n logn), Worstcase: O(n^2)
// Space complexity - O(logn)
void quicksort(int a[], int left, int right) {
    // Choose pivot
    int pivot = a[left + rand() % (right - left)];

    // partition the array into 2 halves
    // left: < than the pivot
    // right: > than the pivot
    int i = left;
    int j = right;

    while(i <= j) {
        // pointer i: Find element that < pivot from left
        while(a[i] < pivot) ++i;

        // pointer j: Find element that > pivot from right  
        while(a[j] > pivot) --j;

        // if i still in left, j still in right: swap than continue
        if(i <= j) {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    }

    //Continue sorting 2 halves
    if(left < j) quicksort(a, left, j);
    if(i < right) quicksort(a, i, right);
}
