
// https://codejam.withgoogle.com/codejam/contest/5304486/dashboard

const int MAXRC = 25 + 1;
int R,C;
char a[MAXRC][MAXRC];
ll readInput() {
    scanf("%lld %lld", &R, &C);
    FOR(r,1,R+1,1)
        scanf("%s", a[r] + 1);
    return 0;
}

int dirX[2] = {-1,1};
void bfs1(int r, int c, char l) {
    queue<pii> q;
    q.push({r,c});

    while(!q.empty()) {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();

        a[x][y] = l;

        for_i(0,2,1) {
            int nextX = x + dirX[i];
            if(nextX < 1 || nextX > R || a[nextX][y] != '?')
                continue;
            q.push({nextX, y});
        }
    }
}
void firstScan() {
    FOR(r,1,R+1,1) {
        FOR(c,1,C+1,1) {
            if(a[r][c] == '?')
                continue;
            bfs1(r,c,a[r][c]);
        }
    }
}
int dirY[2] = {-1,1};
void bfs2(int r, int c, char l) {
    queue<pii> q;
    q.push({r,c});

    while(!q.empty()) {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();

        a[x][y] = l;

        for_i(0,2,1) {
            int nextY = y + dirY[i];
            if(nextY < 1 || nextY > C || a[x][nextY] != '?')
                continue;
            q.push({x, nextY});
        }

    }
}
void secScan() {
    FOR(r,1,R+1,1) {
        FOR(c,1,C+1,1) {
            if(a[r][c] == '?')
                continue;
            bfs2(r,c,a[r][c]);
        }
    }
}

ll solve() {
    firstScan();
    secScan();
    return 0;
}
