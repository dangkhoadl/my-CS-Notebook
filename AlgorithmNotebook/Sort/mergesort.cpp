

// [left, right]
// Stable
// Time Complexity - O(nlogn)
// Space Complexity - Depend
void mergesort(int a[], int temp[], int left, int right) {

    /*-------------------------------------- Stop condition ----------------------------------*/
    if(left >= right)
        return;

    /*-------------------------------------- Sort each half Recursively ----------------------------------*/
    int mid = left + (right - left) / 2;
    mergesort(a, temp, left, mid);
    mergesort(a, temp, mid+1, right);


    /*-------------------------------------- Merge 2 halves into temp ----------------------------------*/
    // Merge 2 halves: 
    //      i - 1st half
    //      j - 2nd half
    // cur: merge pointer
    int i = left;
    int j = mid + 1;
    int cur = 0;

    // While 1 reach the end of its
    while(i <= mid || j <= right) {
        // Case left = 0 elements, copy right to temp
        if(i > mid) temp[cur++] = a[j++];

        // case right = 0 elements, copy left to temp
        else if(j > right) temp[cur++] = a[i++];

        // Case left < right, copy left to temp
        else if(a[i] <= a[j]) temp[cur++] = a[i++];                     // Important Note: The " <= " make the mergeSort stable: If a[i] == a[i]: we favor the left one (stable !!!)

        // case left > right, copy right to temp
        else temp[cur++] = a[j++];
    }

    /*-------------------------------------- Copy temp back into a[left,right] ----------------------------------*/
    for(int i=0; i < cur; ++i) a[left + i] = temp[i];
}
