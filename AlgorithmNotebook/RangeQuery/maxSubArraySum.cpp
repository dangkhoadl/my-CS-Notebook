
//find the maximum partial sum of an array
//Ex: a = {-1,2,4,-3,5,2,-5,2}
//  -> maxSum = 10 
//      range: [1,6)

int a[8] = { -1,2,4,-3,5,2,-5,2 };
const int N = sizeof(a) / sizeof(int);

int bruteForce() {  //O(n^3)
    int maxSum = -inf;
    for(int i=0; i < N; ++i) 
        for (int j = i; j < N; ++j)
            maxSum = max(accumulate(a + i, a + j + 1, 0), maxSum);
    return maxSum;
}


// Consider the subproblem of finding the maximum-sum subarray that ends at
// position k . There are two possibilities:
//  1. The subarray only contains the element at position k .
//  2. The subarray consists of a subarray that ends at position k − 1, followed by
//      the element at position k .
int Optimized() {   //O(n)
    int maxSum = -inf;
    int sumP = -inf;
    for (int i = 0; i < N; ++i) {
        sumP = max(a[i], sumP + a[i]);
        maxSum = max(maxSum, sumP);
    }
    return maxSum;
}
