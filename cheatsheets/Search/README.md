
# Binary Search left/right pointer note
## Binary Search with left/right pointers

<img src="./img/1.jpg" alt="drawing" width="650"/>

## C++ lower_bound, upper_bound pointers

<img src="./img/2.jpg" alt="drawing" width="650"/>

## Decrease/ Increase pointers

```C++
// decrease
prev(it);   // --it
prev(it, 2); // it -= 2;

// increase
next(it);   // ++it
next(it, 2); // it += 2;
```

# Binary Search verification
- A determine range of x: `[a,b]`. Eg: segments
- function f(x): check true/false. Eg: Rules, Requirements
    + Find x to make f(x) optimal
    + Easy to verify f(x) true/false than find x directly

<img src="./img/3.jpg" alt="drawing" width="700"/>

# Tenary search
- For finding max, min in a unimodal function f

    
<img src="./img/2.png" width="400"/>
