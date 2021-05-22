## Decrease/ Increase pointers

```C++
// decrease
prev(it);   // --it
prev(it, 2); // it -= 2;

// increase
next(it);   // ++it
next(it, 2); // it += 2;
```


## C++ lower_bound, upper_bound pointers

- **upper_bound(value)** return first element which is > value. If not, return end().
    + **prev(upper_bound(value))** return first element which is ≤ value
- **lower_bound(value)** return first element which is ≥ value. If not, return end().
    + **prev(lower_bound(value))** return first element which is < value

<img src="./img/2.jpg" alt="drawing" width="650"/>
