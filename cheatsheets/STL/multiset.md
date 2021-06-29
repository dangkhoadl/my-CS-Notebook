
```cpp
multiset<int> A(multiset<int>({2,2,2,3,3,5,9}));

int del_val = 2;

// Del 1 elem, note may del wrong elem if elem not exist
// {2,2,3,3,5,9}
A.erase(A.lower_bound(del_val));

// Del all val
// {3,3,5,9}
A.erase(del_val);
```

#### multiset as PQ

```cpp
multiset<int> PQ({1,2,3,4,4,4,4,5,6,6});

// pop min
assert(PQ.size() > 0);
int val = *PQ.begin();
PQ.erase(PQ.begin());

// pop max
assert(PQ.size() > 0);
int val = *PQ.rbegin();
PQ.erase(prev(PQ.end()));

// pop i-th small
int i = 2;

assert(PQ.size() > i);
auto it = next(PQ.begin(), i);
int val = *it;
PQ.erase(it);


// pop by key
int val = 4;

assert(PQ.size() > 0);
auto it = PQ.find(val);
if(it != PQ.end()) PQ.erase(PQ.lower_bound(val));
```