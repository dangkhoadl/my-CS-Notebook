

#### return values
- Normal return

```C++
// Return when dfs only generate 1 case
return dfs(x, str, i + 1)
```

- Search - backtrack

```C++
// Search for the true case
//     if >= 1 case true -> true
//     if all cases false -> false
FOR(x,0,4)
    if(dfs(x, str, i + 1)) return true;
```

# 1. DP

#### Transition

```C++
// state j --> state i (j < i)
for(int i=1; i<N; ++i) {
    for(int j=0; j<i; ++j) {
        // Full relaxation condition
        if(dp[i] < dp[j] + A[i]) {
            // Relax
            dp[i] = A[i] + dp[j];

            // backtrack
            backtrack[i] = j;
        }

        // Relaxation Short-form
        dp[i] = max(dp[i], dp[j] + A[i]);
    }
}
```

#### BottomUp or Topdown-dfs
- BottomUp when

```C++
// If DP only relax in 1 direction (i.e increasing) --> Bottom Up
dp[i+1][w+A[i]] = max(dp[i+1][w+A[i]], dp[i][w]) // A[i] > 0 \forall i
dp[j] = min(dp[j], dp[i] + A[i]);  // j > i, \forall i,j 
```


# 2. Backtrack/DFS + DP template


```C++
bool get(int i) {
    // base cases + quick returns
    if(base_cases) return x;
    if(success_cond) {
        print(ans);
        return true;
    }

    // Check visited or dp
    vis[i] = true;

    // Branching
    next_ = ...+...;
    if(0<=next_ && next_< N && vis[next_] == false) {
        ans += ...;
        if(get(next_)) return true;
        ans -= ...;
    }

    next_ = ...-...;
    if(0<=next_ && next_< N && vis[next_] == false) {
        ans += ...;
        if(get(next_)) return true;
        ans -= ...;
    }

    for() {
        next_ = ;
        if(0<=next_ && next_< N && vis[next_] == false) {
            ans += ...;
            if(get(next_)) return true;
            ans -= ...;
        }
    }

    return false;
}
```
