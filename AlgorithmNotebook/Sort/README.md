
## Mergesort
<img src="./img/mergesort_1.jpg" alt="drawing" width="650"/>
<img src="./img/mergesort_2.jpg" alt="drawing" width="650"/>

## Quicksort
<img src="./img/quicksort_partition.jpg" alt="drawing" width="650"/>

## Struct sort
```C++
struct Object {
    int index;
    ll value;
    ll weight;
};
vector<Object> objects;

// Sort value/weight decreasing
sort(objects.begin(), objects.end(), 
	[](const Object &a, const Object &b) {return a.value*b.weight > b.value*a.weight;});
```
