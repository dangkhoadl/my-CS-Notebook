
```cpp
multiset<int> A(multiset<int>({2,2,2,3,3,5,9}));

int del_val = 2;

// Del 1 elem, note may del wrong elem if elem not exist
// {2,2,3,3,5,9}
A.erase(A.lower_bound(del_val));

// Del all
// {3,3,5,9}
A.erase(del_val);
```