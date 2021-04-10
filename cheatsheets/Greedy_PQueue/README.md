## Note: Consider multimap vs map carefully

## Consider Sorting - Grouping duplicated elements as always
- Consider grouping duplicates to reduce runtime of map, priorityqueue etc...

```
    2 2 2 3 5
    -> [{2:3}, {3:1}, {5:1}]
```

- map<int, int>
- map<int, vector<>, vector<>>
- priority_queue<int, int>

## Greedy - Combine strategy
- If we have multiple strategies but not sure which one is the most optimal. Can combine by

```C++
return min(strat_1(x), strat_2(x), strat_3(x))
```
