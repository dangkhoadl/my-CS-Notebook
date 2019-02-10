
// A[left,right]
int ternarySearch(const vector<int> &A, int key, int l, int r) {
    if(l > r)
        return -1;

    int m1 = l + (r-l)/3;
    int m2 = m1 + (r-l)/3;

    if(A[m1] == key)
        return m1;
    if(A[m2] == key)
        return m2;
    if(key < A[m1])
        return ternarySearch(A, key, l, m1-1);
    if(A[m2] < key)
        return ternarySearch(A, key, m2+1, r);
    return ternarySearch(A, key, m1+1, m2-1);
}


// A[left,right]
int ternarySearch(const vector<int> &A, int key, int l, int r) {
    while(l <= r) {
        int m1 = l + (r-l)/3;
        int m2 = m1 + (r-l)/3;

        if(A[m1] == key)
            return m1;
        if(A[m2] == key)
            return m2;
        if(key < A[m1]) 
            r = m1 - 1;
        else if(key > A[m2])
            l = m2 + 1;
        else {
            l = m1 + 1;
            r = m2 - 1;
        }
    }
    return -1;
}
