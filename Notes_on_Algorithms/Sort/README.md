
## Sort
#### Basic sort
```C++
vector<int> nums;

// Sort Increasing
sort(nums.begin(), nums.end());
sort(nums.begin(), nums.end(), [](int a, int b){return a < b;});

// Sort Decreasing
sort(nums.begin(), nums.end(), [](int a, int b){return a > b;});

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

## Priority Queue
#### C++ Default Priority Queue = *Max* Heap
```C++
priority_queue<int> pq;
```

#### C++ Min Priority Queue
```C++
priority_queue<
    int,
    vector<int>,
    greater<int>> pq;
```

#### C++ Max PQ pair<int, int>, max - max
```C++
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    less<pair<int, int>>> pq;
```

#### C++ Speical PQ pair<int, int>
- 1st prior: max second
- 2nd prior: min first

```
(1,8)
(2,8)
(3,8)
(1,7)
(2,7)
(3,7)
(1,6)
(2,6)
(3,6)
```

```C++
struct Compare {
    bool operator() (const pair<int,int> &a, const pair<int,int> &b) const {
        return (a.second < b.second) || (a.second == b.second && a.first > b.first);
    }
};
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    Compare> pq;
```
