
# map
#### Constructors

```cpp
unordered_map<int, unordered_map<string, int>> states({
    {1, { {"blank", 1}, {"sign", 2}, {"digit", 3} } },
    {2, { {"digit", 3} } },
    {3, { {"digit", 3} } }
});
unordered_map<int, unordered_map<string, int>> states = {
    {1, { {"blank", 1}, {"sign", 2}, {"digit", 3} } },
    {2, { {"digit", 3} } },
    {3, { {"digit", 3} } }
};


// Build map from vector
vector<pair<int, string>> A({{1,"one"}, {3,"three"}, {2,"two"}});
map<int, string> mp(A.begin(), A.end());
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
map<int, int> _cnt_ = {{1,3}, {2,5}, {3,2}};

// pop_min
assert(_cnt_.size() > 0);
if(_cnt_.begin()->second == 1) {
    _cnt_.erase(_cnt_.begin());
}
else {
    _cnt_.begin()->second -= 1;
}

// pop_max
assert(_cnt_.size() > 0);
if(_cnt_.rbegin()->second == 1) {
    _cnt_.erase(prev(_cnt_.end()));
}
else {
    _cnt_.rbegin()->second -= 1;
}

// pop i-th small
int i = 1;

assert(_cnt_.size() > i);
auto it = next(_cnt_.begin(), i);
if(it->second == 1) {
    _cnt_.erase(it);
}
else {
    it->second -= 1;
}


// pop by key
int key = 2;

assert(_cnt_.size() > 0);
auto it = _cnt_.find(key);
if(it != _cnt_.end()) {
    if(it->second == 1) {
        _cnt_.erase(it);
    }
    else {
        it->second -= 1;
    }
}
```
