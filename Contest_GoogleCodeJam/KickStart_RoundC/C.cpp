
// https://code.google.com/codejam/contest/4344486/dashboard#s=p2

const int MAXN = 2 + 1;
const int MAXQ = 50 + 1;

int N, Q;
char fr[MAXN][MAXQ];
char me[MAXQ];
int scr[MAXN];
ll readInput() {
    scanf("%lld %lld", &N, &Q);
    FOR(n,1,N+1,1)
        scanf("%s", fr[n] + 1);
    scanf("%s", me + 1);
    FOR(n,1,N+1,1)
        scanf("%lld", &scr[n]);
    return 0;
}

int dp[MAXQ][MAXQ];
int sol1() {
    FOR(q,0,Q+1,1)
        ms(dp[q], -1);

    dp[0][0] = 0;
    FOR(q,0,Q,1) 
        FOR(fr1,0,Q,1) {
            if(dp[q][fr1] == -1)
                continue;

            //Case true
            if(fr[1][q+1] == 'F' && me[q+1] == 'F')
                dp[q+1][fr1] = max(dp[q+1][fr1], dp[q][fr1]);
            else if (fr[1][q+1] == 'F' && me[q+1] == 'T')
                dp[q+1][fr1] = max(dp[q+1][fr1], dp[q][fr1] + 1);
            else if (fr[1][q+1] == 'T' && me[q+1] == 'F')
                dp[q+1][fr1+1] = max(dp[q+1][fr1+1], dp[q][fr1]);
            else if (fr[1][q+1] == 'T' && me[q+1] == 'T')
                dp[q+1][fr1+1] = max(dp[q+1][fr1+1], dp[q][fr1] + 1);

            //Case false
            if(fr[1][q+1] == 'F' && me[q+1] == 'F')
                dp[q+1][fr1+1] = max(dp[q+1][fr1+1], dp[q][fr1] + 1);
            else if (fr[1][q+1] == 'F' && me[q+1] == 'T')
                dp[q+1][fr1+1] = max(dp[q+1][fr1+1], dp[q][fr1]);
            else if (fr[1][q+1] == 'T' && me[q+1] == 'F')
                dp[q+1][fr1] = max(dp[q+1][fr1], dp[q][fr1] + 1);
            else if (fr[1][q+1] == 'T' && me[q+1] == 'T')
                dp[q+1][fr1] = max(dp[q+1][fr1], dp[q][fr1]);
        }
    return dp[Q][scr[1]];
}

int dp2[MAXQ][MAXQ][MAXQ];
int fr1i, fr2i;
int inc;
int sol2() {
    FOR(q,0,Q+1,1)
        FOR(fr1,0,Q+1,1)
            ms(dp2[q][fr1], -1);

    dp2[0][0][0] = 0;
    FOR(q,0,Q,1) 
        FOR(fr1,0,Q,1) 
            FOR(fr2,0,Q,1) {
                if(dp2[q][fr1][fr2] == -1)
                    continue;

                //Case true
                fr1i = fr[1][q+1] == 'T' ? fr1+1 : fr1;
                fr2i = fr[2][q+1] == 'T' ? fr2+1: fr2;
                inc = me[q+1] == 'T' ? 1 : 0;
                dp2[q+1][fr1i][fr2i] = max(dp2[q+1][fr1i][fr2i], dp2[q][fr1][fr2] + inc);

                //Case false
                fr1i = fr[1][q+1] == 'F' ? fr1+1 : fr1;
                fr2i = fr[2][q+1] == 'F' ? fr2+1: fr2;
                inc = me[q+1] == 'F' ? 1 : 0;
                dp2[q+1][fr1i][fr2i] = max(dp2[q+1][fr1i][fr2i], dp2[q][fr1][fr2] + inc);
            }
    return dp2[Q][scr[1]][scr[2]];
}
