
// https://www.youtube.com/watch?v=8LusJS5-AGo&index=1&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr

int w[5] = {0,1,3,4,5};
int v[5] = {0,1,4,5,7};
const int I = 4;
const int W = 7;

bool visited[1000][1000];
int dp[1000][1000];
int knapSack01() {
    ms(visited, false);
    ms(dp, -1);

    queue<pii> q;
    q.push({0,0});
    visited[0][0] = true;
    dp[0][0] = 0;
    while(!q.empty()) {
        int i = q.front().fi;
        int wei = q.front().se;
        int val = dp[i][wei];
        q.pop();

        if(i >= I || wei > W)
            continue;
        int i_, wei_, val_;

        //Case default
        i_ = i+1;
        wei_ = wei + 1;
        val_ = val;
        if(!visited[i_][wei_]) {
            visited[i_][wei_] = true;
            q.push({i_,wei_});
        }
        dp[i_][wei_] = max(dp[i_][wei_], val_);

        // Case choose i_
        i_ = i+1;
        wei_ = wei + w[i_];
        val_ = val + v[i_];
        if(!visited[i_][wei_]) {
            visited[i_][wei_] = true;
            q.push({i_,wei_});
        }
        dp[i_][wei_] = max(dp[i_][wei_], val_);

        // Case not choose i_
        i_ = i+1;
        wei_ = wei;
        val_ = val;
        if(!visited[i_][wei_]) {
            visited[i_][wei_] = true;
            q.push({i_,wei_});
        }
        dp[i_][wei_] = max(dp[i_][wei_], val_);
    }
    return dp[I][W];
}
