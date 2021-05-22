
# Priority Queue
## 1. Max-Min heap 1 element
#### C++ Default Priority Queue = *Max* Heap

```C++
priority_queue<int> max_heap;

// Clear method
max_heap = priority_queue<int>();
```

#### Min Heap

```C++
priority_queue<int, vector<int>, greater<int>> min_heap;

// Clear method
min_heap = priority_queue<int, vector<int>, greater<int>>();
```

## 2. 2 elements with different priority

#### C++ special PQ pair<int, int>
- 1st prior: min first
- 2nd prior: max second

```
(1,8)
(1,7)
(1,6)
(2,8)
(2,7)
(2,6)
(3,8)
(3,7)
(3,6)
```

```C++
// min first - max second
struct Compare {
    bool operator() (const pair<int,int> &a, const pair<int,int> &b) const {
        return (a.first > b.first) || (a.first == b.first && a.second < b.second);
    }
};
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    Compare> pq;
```

#### C++ special PQ pair<int, int>
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
// max second - min first
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
