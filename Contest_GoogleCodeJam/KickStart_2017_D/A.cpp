
// https://codejam.withgoogle.com/codejam/contest/8284487/dashboard

const int MAXN = 2000 + 3;

int N, Ts, Tf;
int S[MAXN];
int F[MAXN];
int D[MAXN];
ll readInput() {
    si(N); si(Ts); si(Tf);
    FOR(i,1,N) {
        si(S[i]); si(F[i]); si(D[i]);
    }
    return 0;
}

bool visited[MAXN][MAXN];
int dp[MAXN][MAXN];
int sol() {
    ms(visited,false);
    ms(dp, inf);
    queue<pii> q;

    q.push({0,0});
    dp[0][0] = 0;
    while(!q.empty()) {
        int i = q.front().fi;
        int cnt =  q.front().se;
        int hrs = dp[i][cnt];
        q.pop();

        if(i >= N-1)
            continue;

        int i_, cnt_, hrs_, x;

        //Case visit city i_
        i_ = i+1; 
        cnt_ = cnt+1;
        x = d2i( sceil( ( (double)hrs + Ts - S[i_] ) / F[i_] ) );  
        if(x < 0)
            x = 0; 
        hrs_ = S[i_] + x*F[i_] + D[i_];

        if(!visited[i_][cnt_]) {
            visited[i_][cnt_] = true;
            q.push({i_,cnt_});
        }
        dp[i_][cnt_] = min(dp[i_][cnt_], hrs_);


        //Case not visit i_
        i_ = i+1;
        cnt_ = cnt;
        x = d2i( sceil( ( (double)hrs - S[i_] ) / F[i_] ) ); 
        if(x < 0)
            x = 0; 
        hrs_ = S[i_] + x*F[i_] + D[i_];

        if(!visited[i_][cnt_]) {
            visited[i_][cnt_] = true;
            q.push({i_,cnt_});
        }
        dp[i_][cnt_] = min(dp[i_][cnt_], hrs_);
    }

    // Check
    int res = -1;
    FOR(n,0,N) {
        if(dp[N-1][n] <= Tf)
            res = max(res,n);
    }
    return res;
}


ll solve() {
    return sol();
}
