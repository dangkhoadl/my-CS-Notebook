
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


bool cmpsubString(const string &s1, int start1, int end1, const string &s2, int start2, int end2) {
    assert(start1 >= 0 and start1 < end1 and end1 <= s1.size());
    assert(start2 >= 0 and start2 < end2 and end2 <= s2.size());
    if((end1 - start1) != (end2 - start2))
        return false;
    for(int i = 0; i < (end1-start1); ++i) {
        if(s1[i+start1] != s2[i+start2])
            return false;
    }
    return true;
}
int getHashVal(int h[], int p[], int start, int end){
    return h[end-1]-h[start-1]*p[end-start];
}
const int base=1e9+7;
int h[MAXN],p[MAXN];
void precompute(const string &s) {
    memset(p,0,sizeof(p));
    memset(h,0,sizeof(h));
    p[0]=1;
    h[0]=1;
    for(int i=1; i<s.size(); ++i){
        p[i]=p[i-1]*base;
        h[i]=h[i-1]*base+s[i];
    }
}
bool quickCmpsubString(const string &s1, int start1, int end1, int start2, int end2) {
    if(getHashVal(h,p,start1,end1) != getHashVal(h,p,start2,end2))
        return false;
    return cmpsubString(s,start1,end1, s,start2,end2);
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
        i_ = i+(c2-c1)+1;
        c1_ = c1;
        c2_ = c2;
        dp_ = dp[i][c1][c2]+1;

        bool ok;
        if(c1 == 0 and c2 == 0)
            ok = false;
        else
            ok = quickCmpsubString(s,c1_,c2_+1,i+1,i_+1);

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
    precompute(s);
    return bfs();
}


void solve(unsigned long long t) {
    cout << "Case #" << t << ": " << sol() << endl;  
}
