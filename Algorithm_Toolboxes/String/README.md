
## Trie
<img src="./img/trie.png" alt="drawing" width="650"/>

## Hash String
<img src="./img/hashString.jpg" alt="drawing" width="650"/>

## STL
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

#### substr

```C++
string s;

// [i, end)
string sub_string = s.substr(i);

// [i, i+len) or [i, i+len-1]
string sub_string = s.substr(i, len);
```
