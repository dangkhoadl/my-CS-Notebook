
/*____________________________________ DIR ____________________________ */
/*
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
//_________________________________
// Check if x in [a,b)
inline bool inRange(int x, int a, int b) {
    return a <= x && x < b; 
}
//_________________________________
bool visited[][];
int dp[][];
int bfs() {
    ms(visited, false);
    ms(dp, );

    queue<pii> q;
    q.push({0,0});
    visited[0][0] = true;
    dp[0][0] = ;
    while(!q.empty()) {
        int r = q.front().fi;
        int c = q.front().se;
        int val = dp[r][c];
        q.pop();

        // Stop condition
        if(!inRange(r,0,R) || !inRange(c,0,C))
            continue;

        // Process current state
        int r_,c_, val_;
        FOR(i,0,DIR) {
            r_ = r + dirR[i];
            c_ = c + dirC[i];
            val_ = ;

            //check inrange
            if(!inRange(r_,0,R) || !inRange(c_,0,C))
                continue;

            if(!visited[r_][c_]) {
                visited[r_][c_] = true;
                q.push({r_,c_});
            }
            // dp
            dp[r_][c_] = max();  // max,min, +, - 
        }
    }

    // Check and return value
    return dp[][];
}