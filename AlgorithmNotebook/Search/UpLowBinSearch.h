

// Search in a: a[i] <= x 

// 5, 7, 9, 10, 88, 99
//      search(9) --> a[2] = 9
//      search(55) --> a[3] = 10
//      search(4) --> -1
int binSearchLow(const vector<int> &a, int x, int l, int r) {
    while (true) {
        if (l > r) {
            return l-1;
        }

        int m = l + (r-l)/2;
        if (a[m] == x)              // condition
            return m;

        if (x > a[m])               // condition
            l = m + 1;
        else
            r = m - 1;
    }
}



// Search in a: a[i] >= x

// 5, 7, 9, 10, 88, 99
//      search(9) --> a[2] = 9
//      search(55) --> a[4] = 88
//      search(100) --> 6
int binSearchUp(const vector<int> &a, int x, int l, int r) {
    while (true) {
        if (l > r) {
            return l;
        }

        int m = l + (r-l)/2;
        if (a[m] == x)              // condition
            return m;

        if (x > a[m])               // condition
            l = m + 1;
        else
            r = m - 1;
    }
}
