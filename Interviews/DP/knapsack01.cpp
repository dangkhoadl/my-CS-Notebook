
// https://www.youtube.com/watch?v=8LusJS5-AGo&index=1&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr

const int MAXN = 1000 + 3;

int N, W;
int val[MAXN];
int wei[MAXN];
ll readInput() {
    sii(N,W);
    FOR(n,1,N+1)
        si(val[n]);
    FOR(n,1,N+1)
        si(wei[n]);
    return 0;
}

vi itemsList;
void addResult(int x,int display) {
    itemsList.clear();
    for (int i = 0; i < display; ++i)
        if (x & (1 << i))
            itemsList.pb(i);
}

bool visited[MAXN][MAXN];
int dp[MAXN][MAXN];
int items[MAXN][MAXN];
int bfs() {
    ms(visited, false);
    ms(dp, 0);
    ms(items, 0);

    queue<pii> q;
    q.push({0,0});
    visited[0][0] = true;
    while(!q.empty()) {
        int i = q.front().fi;
        int w = q.front().se;
        int v = dp[i][w];
        int it = items[i][w];
        q.pop();

        int i_, w_, v_, it_;

        i_ = i + 1;
        if(i_ > N)
            continue;

        //Case default
        w_ = w + 1;
        v_ = v;
        it_ = it;
        if(!visited[i_][w_]) {
            visited[i_][w_] = true;
            q.push({i_,w_});
        }
        if(v_ > dp[i_][w_]) {
            dp[i_][w_] = v_;
            items[i_][w_] = it_;
        }

        // Case choose i_
        w_ = w + wei[i_];
        v_ = v + val[i_];
        it_ = it |= (1<<i_);
        if(!visited[i_][w_]) {
            visited[i_][w_] = true;
            q.push({i_,w_});
        }
        if(v_ > dp[i_][w_]) {
            dp[i_][w_] = v_;
            items[i_][w_] = it_;
        }

        // Case not choose i_
        w_ = w;
        v_ = v;
        it_ = it &= ~(1<<i_);
        if(!visited[i_][w_]) {
            visited[i_][w_] = true;
            q.push({i_,w_});
        }
        if(v_ > dp[i_][w_]) {
            dp[i_][w_] = v_;
            items[i_][w_] = it_;
        }
    }
    
    //print selected items
    addResult(items[N][W], N+1);
    return dp[N][W];
}
