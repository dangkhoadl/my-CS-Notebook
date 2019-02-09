
// Kadane Algorithm: O(n)
//      pos = store the range of max sub array
// Ex: arr = [1]-2 [2]-3 [3]4 [4]-1 [5]-2 [6]1 [7]5 [8]-3
//
//      maxSubArraySum(arr,1,8) = 7
//      pos = [3,7]
int maxSubArraySum(int arr[], int s, int e, pair<int, int> &pos) {
    int max_here = arr[s];
    int max_so_far = arr[s];

    for(int i=s+1; i<=e; ++i) {
        if(arr[i] < (max_here + arr[i])) {
            max_here += arr[i];
        }
        else {  // maxSub start here
            max_here = arr[i];
            pos.first = i;
        }

        if(max_so_far < max_here) {  // maxSub end here
            max_so_far = max_here;
            pos.second = i;
        }
    }

    if(pos.second < pos.first) // Case 1 element max
        pos.first = pos.second;
    return max_so_far;
}
