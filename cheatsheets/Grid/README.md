#### Mahattan distance
- dist(P) = dist(P.X) + dist(P.Y) = |X| + |Y|


#### Grid
```C++
/*____________________________________ DIR ____________________________ */
/*              [r][c]
*   up:         -1  0
*   down:        1  0
*   left:        0 -1
*   right        0  1
*   up-left     -1 -1
*   up-right    -1  1
*   down-right   1  1
*   down-left    1 -1
*/

// 8-dir: up, down, left ,right, up-left, up-right, down-right, down-left
const int DIR = 8;
int dirR[DIR] = {-1, 1, 0, 0,-1,-1, 1, 1};
int dirC[DIR] = { 0, 0,-1, 1,-1, 1, 1,-1};

// 4-dir: up, down, left ,right
const int DIR = 4;
int dirR[DIR] = {-1, 1, 0, 0};
int dirC[DIR] = { 0, 0,-1, 1};

// 2-dir: up, down
const int DIR = 2;
int dirR[DIR] = {-1, 1};
int dirC[DIR] = { 0, 0};

// 2-dir: left, right
const int DIR = 2;
int dirR[DIR] = { 0, 0};
int dirC[DIR] = {-1, 1};

// 3-dir: down, down-right, right
const int DIR = 3;
int dirR[DIR] = {1,1,0};
int dirC[DIR] = {0,1,1};


/*________________________ check Inrange ______________________ */
// Check if x in [a,b)
inline bool inRange(int x, int a, int b) {
    return a <= x && x < b; 
}


/*________________________ 1D <-> 2D ______________________ */
// 2D(n*m) -> 1D
int cell = i*m + j;

// 1D -> 2D
int i = cell / m;
int j = cell % m;
```
