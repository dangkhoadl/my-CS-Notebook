
// https://www.youtube.com/watch?v=NnD96abizww&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=2

string s1 = "abcdaf";
string s2 = "acbcf";

bool visited[1000][1000];
int dp[1000][1000];
int longestCommonSubsequence() {
    ms(visited, false);
    ms(dp, -1);

    queue<pii> q;
    q.push({0,0});
    visited[0][0] = true;
    dp[0][0] = 0;

    while(!q.empty()) {
        int x1 = q.front().fi;
        int x2 = q.front().se;
        int cnt = dp[x1][x2];
        q.pop();

        if(x1 > sz(s1) || x2 > sz(s2))
            continue;

        int x1_,x2_,cnt_;

        // Case match
        if(s1[x1] == s2[x2]) {
            x1_ = x1+1;
            x2_ = x2+1; 
            cnt_ = cnt+1;
            if(!visited[x1_][x2_]) {
                visited[x1_][x2_] = true;
                q.push({x1_,x2_});
            }
            dp[x1_][x2_] = max(dp[x1_][x2_], cnt_);
            continue;
        } 
        //Case not match
        
        // ++x1
        x1_ = x1+1;
        x2_ = x2; 
        cnt_ = cnt;
        if(!visited[x1_][x2_]) {
            visited[x1_][x2_] = true;
            q.push({x1_,x2_});
        }
        dp[x1_][x2_] = max(dp[x1_][x2_], cnt_);

        // ++x2
        x1_ = x1;
        x2_ = x2+1; 
        cnt_ = cnt;
        if(!visited[x1_][x2_]) {
            visited[x1_][x2_] = true;
            q.push({x1_,x2_});
        }
        dp[x1_][x2_] = max(dp[x1_][x2_], cnt_);
    }
    return dp[sz(s1)][sz(s2)];
}
