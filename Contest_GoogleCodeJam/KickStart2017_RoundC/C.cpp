
// https://code.google.com/codejam/contest/4344486/dashboard#s=p2

const int MAXN = 2 + 3;
const int MAXQ = 50 + 3;

int N, Q;
char fr[MAXN][MAXQ];
char me[MAXQ];
int scr[MAXN];
ll readInput() {
    sii(N,Q);
    FOR(n,1,N+1)
        ss(fr[n], 1);
    ss(me,1);
    FOR(n,1,N+1)
        si(scr[n]);
    return 0;
}

/*______________________________________________ DP ___________________________________ */
int dp1[MAXQ][MAXQ];
int dp2[MAXQ][MAXQ][MAXQ];
int dpSol() {
    int m_,fr1_,fr2_;
    if(N == 1) {
        FOR(i,0,Q+1)
            ms(dp1[i],-1);

        dp1[0][0] = 0;
        FOR(q,0,Q+1) FOR(fr1,0,Q+1) {
            if(dp1[q][fr1] == -1)
                continue;

            //Case T
            m_ = dp1[q][fr1];
            fr1_ = fr1;
            if(me[q+1] == 'T') ++m_;
            if(fr[1][q+1] == 'T') ++fr1_;
            dp1[q+1][fr1_] = max(dp1[q+1][fr1_], m_);

            //Case F
            m_ = dp1[q][fr1];
            fr1_ = fr1;
            if(me[q+1] == 'F') ++m_;
            if(fr[1][q+1] == 'F') ++fr1_;
            dp1[q+1][fr1_] = max(dp1[q+1][fr1_], m_);
        }
        return dp1[Q][scr[1]];
    }

    FOR(i,0,Q+1) FOR(j,0,Q+1)
        ms(dp2[i][j],-1);

    dp2[0][0][0] = 0;
    FOR(q,0,Q+1) FOR(fr1,0,Q+1) FOR(fr2,0,Q+1) {
        if(dp2[q][fr1][fr2] == -1)
            continue;

        //Case T
        m_ = dp2[q][fr1][fr2];
        fr1_ = fr1;
        fr2_ = fr2;
        if(me[q+1] == 'T') ++m_;
        if(fr[1][q+1] == 'T') ++fr1_;
        if(fr[2][q+1] == 'T') ++fr2_;
        dp2[q+1][fr1_][fr2_] = max(dp2[q+1][fr1_][fr2_], m_);

        //Case F
        m_ = dp2[q][fr1][fr2];
        fr1_ = fr1;
        fr2_ = fr2;
        if(me[q+1] == 'F') ++m_;
        if(fr[1][q+1] == 'F') ++fr1_;
        if(fr[2][q+1] == 'F') ++fr2_;
        dp2[q+1][fr1_][fr2_] = max(dp2[q+1][fr1_][fr2_], m_);
    }
    return dp2[Q][scr[1]][scr[2]];
}

/*______________________________________________ BFS ___________________________________ */
bool visited[MAXQ][MAXQ][MAXQ][MAXQ];
queue<pair<pii,pii>> S;
int bfsSol() {
    int m_, fr1_,fr2_;
    if(N == 1) 
        scr[2] = 0;
    while(!S.empty()) S.pop();
    FOR(i,0,Q+1) FOR(j,0,Q+1) FOR(k,0,Q+1)
        ms(visited[i][j][k], false);

    S.push({{0,0},{0,0}});
    visited[0][0][0][0] = true;

    int res = -1;

    while(!S.empty()) {
        int q = S.front().fi.fi;
        int m = S.front().fi.se;
        int fr1 = S.front().se.fi;
        int fr2 = (N == 1) ? 0 : S.front().se.se;
        S.pop();

        if(q > Q)
            continue;

        //process
        if(fr1 == scr[1] && fr2 == scr[2])
            res = max(res,m);

        //Case T
        m_ = m;
        fr1_ = fr1;
        fr2_ = fr2;
        if(me[q+1] == 'T') ++m_;
        if(fr[1][q+1] == 'T') ++fr1_;
        if(fr[2][q+1] == 'T') ++fr2_;
        if(!visited[q+1][m_][fr1_][fr2_]) {
            visited[q+1][m_][fr1_][fr2_] = true;
            S.push({{q+1,m_},{fr1_,fr2_}});
        }

        //Case F
        m_ = m;
        fr1_ = fr1;
        fr2_ = fr2;
        if(me[q+1] == 'F') ++m_;
        if(fr[1][q+1] == 'F') ++fr1_;
        if(fr[2][q+1] == 'F') ++fr2_;
        if(!visited[q+1][m_][fr1_][fr2_]) {
            visited[q+1][m_][fr1_][fr2_] = true;
            S.push({{q+1,m_},{fr1_,fr2_}});
        }
    }
    return res;
}


int solve() {
    return bfsSol();
}
