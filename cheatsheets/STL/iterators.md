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
- **lower_bound** if found return `it` where the num exist, if not found return `next(it)`
    + Check existing by `if(it != map.end() && it->first == num)`
- **upper_bound** always return `next(it)`
    + Check existing by `if(it != map.begin() && prev(it)->first == num)`

<img src="./img/2.jpg" alt="drawing" width="650"/>
