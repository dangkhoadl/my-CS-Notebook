

//      Range: [l, r]
// Search in a: a[i] <= x 
//         return i
// [0]5 [1]7 [2]9 [3]10 [4]88 [5]99
//      search(9) --> a[2] = 9
//      search(55) --> a[3] = 10
//      search(150) --> a[5] = 99
//      search(4) --> [-1]
int binSearchPrev(const vector<int> &A, int key, int l, int r) {
    while(l <= r) {
        int m = l + (r-l)/2;

        if(A[m] == key)              // condition
            return m;
        if(key < A[m])               // condition
            r = m - 1;
        else
            l = m + 1;
    }
    return r;
}



//      Range: [l, r]
// Search in a: a[i] >= x
//      return i
// [0]5 [1]7 [2]9 [3]10 [4]88 [5]99
//      search(9) --> a[2] = 9
//      search(2) --> a[0] = 5
//      search(55) --> a[4] = 88
//      search(100) --> [6] (a.size())
int binSearchNext(const vector<int> &A, int key, int l, int r) {
    int last_ = r;
    while(l <= r) {
        int m = l + (r-l)/2;

        if(A[m] == key)              // condition
            return m;
        if (key < A[m])              // condition
            r = m - 1;
        else
            l = m + 1;
    }
    return l;
}
