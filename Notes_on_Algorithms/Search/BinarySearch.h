
// A[left,right]
int binarySearchR(int x, int l, int r) {
    if(l > r)
        return -1;

    int m = l + (r-l)/2;
    if(A[m] == x)
        return m;
    if(x > A[m])
        return binarySearchR(x,m+1,r);
    return binarySearchR(x,l,m-1);
}

int binarySearch(int x, int l, int r) {
    while (true) {
        if (l > r)
            return -1;

        int m = l + (r-l)/2;
        if (A[m] == x)
            return m;

        if (x > A[m]) 
            l = m + 1;
        else
            r = m - 1;
    }
}
