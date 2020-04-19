
# vector
#### Contructors

```cpp
vector<int> A({1,2,3}); 	// [1, 2, 3]
vector<int> A = {1,2,3}; 	// [1, 2, 3]
vector<int> A(5, 0); 		// [0, 0, 0, 0, 0] 
```

#### Return multiple val by vector

```cpp
return vector<int>({a, b, c});
```

#### range(a,b) in C++

```C++
// Example: range(10,15) = [10, 11, 12, 13, 14]. Usage:
    // for(int &i:range<int>(10,15))
    //      cout << i << endl;
template <typename T>
vector<T> range(T N1, T N2) {
    vector<T> numbers(N2-N1);
    iota(numbers.begin(), numbers.end(), N1);
    return numbers;
}
```

#### slice(m,n) in C++

```cpp
// slice in range: [m, n)
template<typename T>
vector<T> slice_(const vector<T> &v, int m, int n) {
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n;
    return vector<T>(first, last);
}


// Usage
vector<int> v = {0, 1, 2, 3, 4, 5};
vector<int> res = slice_<int>(v, 2, 4);
    // [2, 3]
```

# set
#### Quick check if c in `{'a', 's', 'd'}`

```cpp
unordered_set<char>({'a','s','d'}).count(c) == true;
```


```cpp
// Add to set
s.insert(1);

// Check
s.count(1) == true;
s.count(1) == false;

// Remove
s.erase(1);
```

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


# string
#### substr

```C++
string s;

// [i, end)
string sub_string = s.substr(i);

// [i, i+len) or [i, i+len-1]
string sub_string = s.substr(i, len);
```

#### insert in between

```cpp
string s = "One three";

int i = 4;
s = s.substr(0, i) + "two " + s.substr(i, s.size());
    // "One two three"
```

#### find

```C++
string text;
string pattern;

// Find from pos 0 
//      Return starting idx if found else -1
int p = text.find(pattern);

// Find from pos i
//      Return starting idx if found else -1
int p = text.find(pattern, i);

// Find all
int p = -1;
vector<int> pos;
do {
    p = text.find(pattern, p+1); 
    if(p != -1) pos.push_back(p);
} while(p != -1);
```
