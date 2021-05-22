# Array - DP

#### DP state
- `dp[i][...]`
    + `i` state: Optimal solution in idx range `[0,i]`


- Template: Build up `[0,i]` from `[0,j]`: `j < i`

<img src="./img/2.jpg" width="600"/>

```C++
for(int i=0; i<=N; ++i) for(int j=-1; j<i;++j) {
    if(j==-1) {
        // Update base case i=0
    }
    if(j>=0) {
        // DP
        dp[i][] = min(dp[i][], dp[j][] + A[i]);
    }
}

```



#### Loop by length (for dp: longer array built-up from short array `A[i:j] = A[start:end]`

- Normal loop `A[i:j]`

```C++
for(int i=0; i<N; ++i) {
    for(int j=i; j<N; ++j) {

        cout << i << ' ' << j << endl;
    }
}
```

```
0 0
0 1
0 2
0 3
1 1
1 2
1 3
2 2
2 3
3 3
```

- Loop by len: `A[i:j]`, `len = j-i+1`

```C++
// len = j - i + 1
for(int len=1; len<=N; ++len) {
    for(int i=0; i+len-1<N; ++i) {
        int j = i+len-1;

        cout << i << ' ' << j << endl;
    }
}
```

```
0 0
1 1
2 2
3 3
0 1
1 2
2 3
0 2
1 3
0 3
```

#### Multiple info from 1 loop
- 1 loop can interact with multiple datapoints (Eg: cur, next)


```C++
for(int i=0; i<N-1; ++i) {
    int cur = i;
    int next = i+1;
}
```


# Circular array
- A circular array represented by A[i] can be duplicated to solve
- Example: A = [5,6,1,2,3] -> [5,6,1,2,3,5,6,1,2,3]

#### A wheels
- A wheel has value from [1,N] has pre-defined positions `A[1,N]` can be duplicated to solve as `A[1,N,N+1,2*N]`
- Example: `N = 10, A = [2,3,8,9]` -> `[2,3,8,9,12,13,18,19]`

<img src="./img/1.jpg" width="200"/>


# Median

<img src="./img/1.png" width="600"/>
