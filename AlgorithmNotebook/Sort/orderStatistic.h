


int order_statistics (int a[], int n, int k) {
    int l = 1;
    int r = n; 
    while (true) {
        if (r <= l+1) {
            // the current part size is either 1 or 2, so it is easy to find the answer
            if (r == l+1 && a[r] < a[l])
                swap(a[l], a[r]);
            return a[k];
        }

        // ordering a[l], a[l+1], a[r]
        int m = l + (r-l)/2;
        swap (a[m], a[l+1]);
        if (a[l] > a[r])
            swap (a[l], a[r]);
        if (a[l+1] > a[r])
            swap (a[l+1], a[r]);
        if (a[l] > a[l+1])
            swap (a[l], a[l+1]);

        // performing division
        // barrier is a[l + 1], i.e. median among a[l], a[l + 1], a[r]
        int i = l+1;
        int j = r;
        int cur = a[l+1];
        while(true) {
            while (a[++i] < cur) ;
            while (a[--j] > cur) ;
            if (i > j)
                break;
            swap (a[i], a[j]);
        }

        // inserting the barrier
        a[l+1] = a[j];
        a[j] = cur;

        // we continue to work in that part, which must contain the required element
        if (j >= k)
            r = j-1;
        if (j <= k)
            l = i;
    }
}
