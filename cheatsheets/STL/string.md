
# string
#### substr

```C++
string s;

// [i, end)
string sub_string = s.substr(i);

// s[i, i+len) or s[i, i+len-1]
string sub_string = s.substr(i, len);
```

- **Insert in between**

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

#### Compare

```C++
// Compare 2 strings lexicographically. Return
//       0: str_1 == str_2 (abc == abc)
//     < 0: abc < bc || abc < abcd
//     > 0: bc > abc || abcd > abc
int res = str_1.compare(str_2);


// Compare 2 substrings lexicographically
//      substr_1 = str_1[i_1, i_1 + len_1)
//      substr_2 = str_2[i_2, i_2 + len_2)
int res = str_1.compare(i_1, len_1, str_2, i_2, len_2);
```

# Convert

#### string to
```C++
// str -> int
int a = stoi(str);

// str -> long long
long long a = stoll(str);

//str -> double
double a = stod(str);

// str -> char
string str("+");
char c = str[0];
```

#### to string

```C++
// int -> str
int a = 52;
string str = to_string(52);

// char -> str
char c = '+';
string str(c,1);
```

#### int <-> char

```C++
// char -> int
int a = c - '0';

// int -> char
char c = a + '0';
```
