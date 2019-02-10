

// A[left,right]
int binarySearch(const vector<int> &A, int key, int l, int r) {
    if(l > r) 
        return -1;

    int m = l + (r-l)/2;
    if(A[m] == key)
        return m;
    if(key < A[m])
        return binarySearch(A, key, l, m-1);
    return binarySearch(A, key, m+1, r);
}


// A[left,right]
int binarySearch(const vector<int> &A, int key, int l, int r) {
    while(l <= r) {
        int m = l + (r-l)/2;

        if(A[m] == key)
            return m;
        if(key < A[m])
            r = m-1;
        else
            l = m+1;
    }
    return -1;
}
