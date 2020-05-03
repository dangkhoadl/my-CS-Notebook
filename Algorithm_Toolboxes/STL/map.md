
# map
#### Constructors

```cpp
unordered_map<int, unordered_map<string, int>> states = {
    {1, { {"blank", 1}, {"sign", 2}, {"digit", 3} } },
    {2, { {"digit", 3} } },
    {3, { {"digit", 3} } }
};
```

#### Operations
- **Note**: Default value in map is, without insert {key, val}
    + `0` for `int`
    + `""` for `string`

```cpp
// Add val
m[1] += 2;
m[1] = 2;

// Check
m.count(1) == NULL;
m.count(1) != NULL;
m[1] == 0;
m[1] != 0;

// Remove
m.erase(1);
```

#### Hash table for key as pair<> or vector<>

```C++
// O(log(n))
map<pair<int,int>, int> m;
m[{x,y}] = z;


// O(1)
unordered_map<int, unordered_map<int, int>> m;
m[x][y] = z;


// O(log(n))
map<vector<int>, int> m;
m[vector<int>({x,y,z})] = z;
```

#### map as special PQ

```C++
map<int, int> cnt = {{1,3}, {2,5}, {3,2}};

// pop_min
assert(cnt.size() > 0);
if(cnt.begin()->second == 1) {
    cnt.erase(cnt.begin());
}
else {
    cnt.begin()->second -= 1;
}

// pop_max
assert(cnt.size() > 0);
if(cnt.rbegin()->second == 1) {
    cnt.erase(prev(cnt.end()));
}
else {
    cnt.rbegin()->second -= 1;
}

// pop i-th small
int i = 1;
assert(cnt.size() > i);

auto it = next(cnt.begin(), i);
if(it->second == 1) {
    cnt.erase(it);
}
else {
    it->second -= 1;
}
```
