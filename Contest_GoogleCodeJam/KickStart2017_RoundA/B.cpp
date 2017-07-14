
// https://codejam.withgoogle.com/codejam/contest/8284486/dashboard#s=p1

const int MAXN = 2000 + 3;

char s1[MAXN];
char s2[MAXN];
ll readInput() {
    ss(s1,1);
    ss(s2,1);
    return 0;
}

vector<char> S1;
bool check1[20000];
vector<char> S2;
bool check2[20000];
void preset() {
    S1.clear();
    S1.resize(1);
    ms(check1,false);
    FOR(i,1,ssz(s1,1)) {
        if(s1[i] != '*') {
            S1.pb(s1[i]);
            continue;
        }
        check1[sz(S1)] = true;
        REP(4)
            S1.pb('*');
    }

    S2.clear();
    S2.resize(1);
    ms(check2,false);
    FOR(i,1,ssz(s2,1)) {
        if(s2[i] != '*') {
            S2.pb(s2[i]);
            continue;
        }
        check2[sz(S2)] = true;
        REP(4)
            S2.pb('*');
    }
}
/*________________________________________________ DP ______________________________________*/
bool dp[20000][20000];
bool dpSol() {
    preset();

    FOR(x1,1,sz(S1)+1) FOR(x2,1,sz(S2)+1)
        dp[x1][x2] = false;

    dp[1][1] = true;
    FOR(x1,1,sz(S1)+1) FOR(x2,1,sz(S2)+1) {
        if(!dp[x1][x2])
            continue;

        if(check1[x1]) {
            FOR(x1_,x1+1,x1+5)
                dp[x1_][x2] = true;
        }
        if(check2[x2]) {
            FOR(x2_,x2+1,x2+5)
                dp[x1][x2_] = true;
        }
        if(S1[x1] == S2[x2] || S1[x1] == '*' || S2[x2] == '*')
            dp[x1+1][x2+1] = true;
    }
    return dp[sz(S1)][sz(S2)];
}
/*________________________________________________ BFS ______________________________________*/
queue<pii> q;
bool visited[20001][20001];
bool bfsSol() {
    preset();

    while(!q.empty()) q.pop();
    FOR(i,1,sz(S1)+2)
        ms(visited[i], false);

    q.push({1,1});
    visited[1][1] = true;

    while(!q.empty()) {
        int x1 = q.front().fi;
        int x2 = q.front().se;
        q.pop();

        //Process
        if(x1 == sz(S1) && x2 == sz(S2))
            return true;

        if(check1[x1]) {
            FOR(x1_,x1+1,x1+5) {
                if(x1_ <= sz(S1)+1 && !visited[x1_][x2]) {
                    visited[x1_][x2] = true;
                    q.push({x1_,x2});
                }
            }
        }
        if(check2[x2]) {
            FOR(x2_,x2+1,x2+5) {
                if(x2_ <= sz(S2)+1 && !visited[x1][x2_]) {
                    visited[x1][x2_] = true;
                    q.push({x1,x2_});
                }
            }
        }
        if(S1[x1] == S2[x2] || S1[x1] == '*' || S2[x2] == '*') {
            if(x1+1 <= sz(S1)+1 && x2+1 <= sz(S2)+1 && !visited[x1+1][x2+1]) {
                visited[x1+1][x2+1];
                q.push({x1+1,x2+1});
            }
        }
    }
    return false;
}

int solve() {
    return bfsSol();
}
