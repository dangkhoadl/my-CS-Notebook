
// https://codejam.withgoogle.com/codejam/contest/8284486/dashboard#s=p1

bool dp[2005][2005];
bool solveDP() {
    int N1 = s1.size();
    int N2 = s2.size();

    ms(dp,false);
    dp[0][0] = true;

    FOR(x1,0,N1+1) FOR(x2,0,N2+1) {
        if(dp[x1][x2] == false)
            continue;

        // Case normal matching
        if(x1<N1 && x2<N2 &&
                s1[x1] == s2[x2]) {
            dp[x1+1][x2+1] = true;
        }

        int cnt, x1_, x2_;

        // Case s1[x1] = '*'
        if(x1<N1 &&
                s1[x1] == '*') {

            // '*' matches 0-4 characters - if '*' in s2 not count
            cnt = 0;
            x2_ = x2;
            while(cnt <= 4) {
                dp[x1+1][x2_] = true;
                if(s2[x2_++] != '*') ++cnt;
            }
        }

        // Case s2[x2] = '*'
        if(x2<N2 &&
                s2[x2] == '*') {

            // '*' matches 0-4 characters - if '*' in s1 not count
            cnt = 0;
            x1_ = x1;
            while(cnt <= 4) {
                dp[x1_][x2+1] = true;
                if(s1[x1_++] != '*') ++cnt;
            }
        }
    }
    return dp[N1][N2];
}


void solve(unsigned long long fdfsfv_t) {
    bool res = solveDP();
    if(res)
        printf("Case #%llu: TRUE\n", fdfsfv_t);
    else
        printf("Case #%llu: FALSE\n", fdfsfv_t);
}
