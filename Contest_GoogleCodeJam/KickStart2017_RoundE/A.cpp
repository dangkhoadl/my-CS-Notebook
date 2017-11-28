
// https://codejam.withgoogle.com/codejam/contest/12234486/dashboard#s=p0&a=0

const int MAXN = 100 + 3;

string s;
ll readInput() {
    string temp;
    cin >> temp;

    s.clear();
    s.pb('$');
    s += temp;
    return 0;
}

int dp[MAXN][MAXN][MAXN];
bool visited[MAXN][MAXN][MAXN];
int bfs() {
    ms(visited, false);
    ms(dp, 0x7f);

    queue<pair<int,pii>> q;
    q.push( {0,{ 0,0 }} );

    dp[0][0][0] = 0;
    visited[0][0][0] = true;

    int min_ = inf;

    while(!q.empty()) {
        int i = q.front().fi;
        int c1 = q.front().se.fi;
        int c2 = q.front().se.se;
        q.pop();

        if(i == sz(s)-1) 
            min_ = min(min_, dp[i][c1][c2]);


        int i_, c1_, c2_, dp_;

        // Append
        i_ = i+1;
        c1_ = c1;
        c2_ = c2;
        dp_ = dp[i][c1][c2] + 1;
        if(!visited[i_][c1_][c2_] and i_ <= sz(s)-1 and c1_ <= sz(s)-1 and c2_ <= sz(s)-1) {
            q.push( {i_,{ c1_,c2_ }} );
            visited[i_][c1_][c2_] = true;
        }
        dp[i_][c1_][c2_] = min(dp[i_][c1_][c2_], dp_);

        // Copy
        FOR(p1,1,i) FOR(p2,p1+1,i+1) {
            i_ = i;
            c1_ = p1;
            c2_ = p2;
            dp_ = dp[i][c1][c2] + 1;
            if(!visited[i_][c1_][c2_] and i_ <= sz(s)-1 and c1_ <= sz(s)-1 and c2_ <= sz(s)-1) {
                q.push( {i_,{ c1_,c2_ }} );
                visited[i_][c1_][c2_] = true;
            }
            dp[i_][c1_][c2_] = min(dp[i_][c1_][c2_], dp_);
        }

        // Paste
        bool ok = true;
        i_ = i+1;
        c1_ = c1;
        c2_ = c2;
        dp_ = dp[i][c1][c2]+1;
        FOR(p,c1,c2+1) {
            if(s[p] != s[i_++])
                ok = false;
        }
        --i_;

        if(ok and !visited[i_][c1_][c2_] and i_ <= sz(s)-1 and c1_ <= sz(s)-1 and c2_ <= sz(s)-1) {
            q.push( {i_,{ c1_,c2_ }} );
            visited[i_][c1_][c2_] = true;
        }
        if(ok)
            dp[i_][c1_][c2_] = min(dp[i_][c1_][c2_], dp_);
    }
    return min_;
}
int sol() {
    return bfs();
}


void solve(unsigned long long t) {
    cout << "Case #" << t << ": " << sol() << endl;  
}
