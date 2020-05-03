
# string
#### substr

```C++
string s;

// [i, end)
string sub_string = s.substr(i);

// [i, i+len) or [i, i+len-1]
string sub_string = s.substr(i, len);
```

#### insert in between

```cpp
string s = "One three";

int i = 4;
s = s.substr(0, i) + "two " + s.substr(i, s.size());
    // "One two three"
```

#### find

```C++
string text;
string pattern;

// Find from pos 0 
//      Return starting idx if found else -1
int p = text.find(pattern);

// Find from pos i
//      Return starting idx if found else -1
int p = text.find(pattern, i);

// Find all
int p = -1;
vector<int> pos;
do {
    p = text.find(pattern, p+1); 
    if(p != -1) pos.push_back(p);
} while(p != -1);
```
