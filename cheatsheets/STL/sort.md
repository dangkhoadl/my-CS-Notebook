
## Sort
#### Sort vector
```C++
vector<int> nums;

// Sort Increasing
sort(nums.begin(), nums.end());
sort(nums.begin(), nums.end(), less<int>());
sort(nums.begin(), nums.end(), [](int a, int b){return a < b;});

// Sort Decreasing
sort(nums.begin(), nums.end(), greater<int>());
sort(nums.begin(), nums.end(), [](int a, int b){return a > b;});
```

#### Sort pair
```C++
// --------------- first -------------- //
// first: increase
sort(nums.begin(), nums.end());
// first: decrease
sort(nums.begin(), nums.end(), [](pair<int, char> &a, pair<int, char> &b){return a.first > b.first;});

// --------------- second -------------- //
// second: increase
sort(nums.begin(), nums.end(), [](pair<int, char> &a, pair<int, char> &b){return a.second < b.second;});
// second: decrease
sort(nums.begin(), nums.end(), [](pair<int, char> &a, pair<int, char> &b){return a.second > b.second;});
```

#### Sort unordered_map
```C++
unordered_map<int, int> tab;

// sorted by second: increase
vector<pair<int, int>> tmp(tab.begin(), tab.end());
sort(tmp.begin(), tmp.end(), [](pair<int, int> &a, pair<int, int> &b){return a.second < b.second;});
```


#### Struct sort
```C++
struct Object {
    int index;
    ll value;
    ll weight;
};
vector<Object> objects;

// Sort value/weight decreasing
sort(objects.begin(), objects.end(), 
    [](const Object &a, const Object &b) 
        {return a.value*b.weight > b.value*a.weight;});
```

#### Struct sort - Priority
- Method 1

```C++
struct Object {
    int index;
    ll firstPrior;
    ll secondPrior;
};
vector<Object> objects;

// Sort 1st prior decreasing - 2nd prior increasing
sort(objects.begin(), objects.end(), 
    [](const Object &a, const Object &b) 
        {return a.firstPrior > b.firstPrior || (a.firstPrior == b.firstPrior && a.secondPrior < b.secondPrior);});
```

- Method 2

```C++
struct Object {
    int index;
    ll firstPrior;
    ll secondPrior;
};
vector<Object> objects;

// Sort 1st prior decreasing - 2nd prior increasing
sort(objects.begin(), objects.end(), 
    [](const Object &a, const Object &b) 
        {return a.secondPrior < b.secondPrior;});

stable_sort(objects.begin(), objects.end(), 
    [](const Object &a, const Object &b) 
        {return a.firstPrior > b.firstPrior;});
```
