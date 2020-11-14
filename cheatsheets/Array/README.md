# Array
- Normal loop `A[i:j] = A[start:end]`

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

#### Loop by length (for dp: longer array built-up from short array `A[i:j] = A[start:end]`

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


# Circular array
- A circular array represented by A[i] can be duplicated to solve
- Example: A = [5,6,1,2,3] -> [5,6,1,2,3,5,6,1,2,3]

#### A wheels
- A wheel has value from [1,N] has pre-defined positions `A[1,N]` can be duplicated to solve as `A[1,N,N+1,2*N]`
- Example: `N = 10, A = [2,3,8,9]` -> `[2,3,8,9,12,13,18,19]`

<img src="./img/1.jpg" width="200"/>
