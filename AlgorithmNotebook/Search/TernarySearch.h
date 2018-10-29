
// A[left,right]
int ternarySearchR(int x, int l, int r) {
    if(l > r)
        return -1;

    int m1 = l + (r-l)/3;
    int m2 = m1 + (r-l)/3;
    if(A[m1] == x)
        return m1;
    if(A[m2] == x)
        return m2;
    if(x < A[m1])
        return ternarySearchR(x,l,m1-1);
    if(x > A[m2])
        return ternarySearchR(x,m2+1,r);
    return ternarySearchR(x,m1+1,m2-1);
} 

int ternarySearch(int x, int l, int r) {
    while(true) {
        if(l > r)
            return -1;

        int m1 = l + (r-l)/3;
        int m2 = m1 + (r-l)/3;
        if(A[m1] == x)
            return m1;
        if(A[m2] == x)
            return m2;
        if(x < A[m1]) 
            r = m1 - 1;
        else if(x > A[m2])
            l = m2 + 1;
        else {
            l = m1 + 1;
            r = m2 - 1;
        }
    }
} 
