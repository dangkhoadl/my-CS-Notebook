# vector
#### Contructors

```cpp
vector<int> A({1,2,3}); 	// [1, 2, 3]
vector<int> A = {1,2,3}; 	// [1, 2, 3]
vector<int> A(5, 0); 		// [0, 0, 0, 0, 0]

// Build vector from map
map<int, string> mp = { {1,"one"}, {2,"two"}, {3,"three"} };
vector<pair<int, string>> A(mp.begin(), mp.end());
```

#### Return multiple val by vector

```cpp
return vector<int>({a, b, c});
```

#### Reverse a vector

```C++
// Reverse all
reverse(v.begin(), v.end());


// Reverse v[l,r]
reverse(v.begin() + l, v.begin() + r + 1);
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
