
## Hash table for string
- ASCII characters

```C++
vector<int> cnt(128, 0);
for(const auto &c: t) cnt[c] += 1;
```

- All lower case character

```C++
vector<int> cnt(26, 0);
for(const char &c:s) cnt[c-'a'] += 1;
```


## Anagram
- Words that have rearranged characters. Eg:
    + "listen" = "silent"
    + "funeral" = "real fun"
- Solve
    + Sort characters -> compare
    + Note: sort using count sort O(s)

```C++
string count_sort(const string &s) {
    // count
    vector<int> cnt(26, 0);
    for(const char &c:s) cnt[c-'a'] += 1;

    // Sort
    string res = "";
    for(int i=0; i<26; ++i) res += string(cnt[i], 'a'+i);
    return res;
}
```


## Notes on () recursion
- `(`
    + call the recursive func
- `)`
    + Finish all operations
    + return the recursive func
- get(int &i)
    + Put a reference to update current position after return from ')'
