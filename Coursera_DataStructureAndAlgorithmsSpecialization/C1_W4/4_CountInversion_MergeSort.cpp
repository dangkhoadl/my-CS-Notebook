

const int MAXN = 1e5 + 3;

int N;
int a[MAXN];
ll readInput() {
    si(N);
    FOR(i,1,N+1)
        si(a[i]);
    return 0;
}


// O(n^2)
int brute() {
    int cnt = 0;
    FOR(i,1,N) FOR(j,i+1,N+1) {
        if(a[i] > a[j])
            ++cnt;
    }
    return cnt;
}


// O(nlogn)
int cnts = 0;
int temp[MAXN];
void mergesort(int a[], int temp[], int left, int right, int &cnt) {
    /*-------------------------------------- Stop condition ----------------------------------*/
    if(left >= right)
        return;

    /*-------------------------------------- Sort each half Recursively ----------------------------------*/
    int mid = left + (right - left) / 2;
    mergesort(a, temp, left, mid, cnt);
    mergesort(a, temp, mid+1, right, cnt);


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
        else if(j > right) {
            cnt += (left + cur - i);
            temp[cur++] = a[i++];
        }

        // Case left < right, copy left to temp
        else if(a[i] <= a[j]) {
            cnt += (left + cur - i);
            temp[cur++] = a[i++];
        }

        // case left > right, copy right to temp
        else temp[cur++] = a[j++];
    }

    /*-------------------------------------- Copy temp back into a[left,right] ----------------------------------*/
    for(int i=0; i < cur; ++i) a[left + i] = temp[i];
}
int sol() {
    int cnt = 0;
    mergesort(a,temp,1,N,cnt);
    return cnt;
}


ll solve() {
    // cout << brute() << endl;
    cout << sol() << endl;

    return 0;
}
