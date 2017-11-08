
// https://codejam.withgoogle.com/codejam/contest/8284486/dashboard#s=p1

const int MAXN = 2000 + 3;

char s1[MAXN];
char s2[MAXN];
ll readInput() {
    ss(s1,1);
    ss(s2,1);
    return 0;
}

string x1, x2;
void convert() {
    x1 = "_";
    FOR(i,1,ssz(s1,1)) {
        if(s1[i] == '*')
            x1 += "*+++";
        else
            x1 += s1[i];
    }

    x2 = "_";
    FOR(i,1,ssz(s2,1)) {
        if(s2[i] == '*')
            x2 += "*+++";
        else
            x2 += s2[i];
    }
}


/*________________________________________________ Sol1 __________________________________________ */
bool dp[MAXN*4][MAXN*4];
bool sol1() {
    convert();

    ms(dp, false);

    dp[1][1] = true;

    FOR(p1, 1, sz(x1)+1) FOR(p2, 1, sz(x2)+1) {
        if(!dp[p1][p2])
            continue;

        int p1_, p2_;

        // 1
        if(x1[p1] == '*') {
            FOR(i,1,5) {
                p1_ = p1 + i;
                p2_ = p2;
                dp[p1_][p2_] = true;
            }
        }

        // 2
        if(x2[p2] == '*') {
            FOR(i,1,5) {
                p1_ = p1;
                p2_ = p2 + i;
                dp[p1_][p2_] = true;
            }
        }

        // 3
        if(x1[p1] == x2[p2] || x1[p1] == '+' || x2[p2] == '+' || x1[p1] == '*' || x2[p2] == '*') {
            p1_ = p1 + 1;
            p2_ = p2 + 1;
            dp[p1_][p2_] = true;
        }
    }
    return dp[sz(x1)][sz(x2)];
}

/*________________________________________________ Sol2 __________________________________________ */
// bool dp[MAXN*4][MAXN*4];
bool sol2() {
    convert();

    ms(dp, false);

    queue<pii> q;
    q.push({1,1});
    dp[1][1] = true;

    while(!q.empty()) {
        int p1 = q.front().fi;
        int p2 = q.front().se;
        q.pop();

        int p1_, p2_;
        bool check_;

        //1
        if(x1[p1] == '*') {
            FOR(i,1,5) {
                p1_ = p1 + i;
                p2_ = p2;

                if(p1_ > sz(x1) or p2_ > sz(x2))
                    continue;
                if(!dp[p1_][p2_]) q.push({p1_,p2_});
                dp[p1_][p2_] = true;
            }
        }

        //2
        if(x2[p2] == '*') {
            FOR(i,1,5) {
                p1_ = p1;
                p2_ = p2 + i;

                if(p1_ > sz(x1) or p2_ > sz(x2))
                    continue;
                if(!dp[p1_][p2_]) q.push({p1_,p2_});
                dp[p1_][p2_] = true;
            }
        }

        // 3
        if(x1[p1] == x2[p2] || x1[p1] == '+' || x2[p2] == '+' || x1[p1] == '*' || x2[p2] == '*') {
            p1_ = p1 + 1;
            p2_ = p2 + 1;

            if(p1_ > sz(x1) or p2_ > sz(x2))
                continue;
            if(!dp[p1_][p2_]) q.push({p1_,p2_});
            dp[p1_][p2_] = true;
        }
    }
    return dp[sz(x1)][sz(x2)];
}


void solve(unsigned long long t) {
    bool res = sol1();
    if(res)
        printf("Case #%llu: %s\n", t, "TRUE");
    else
        printf("Case #%llu: %s\n", t, "FALSE");
}
