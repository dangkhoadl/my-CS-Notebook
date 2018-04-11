
// https://codejam.withgoogle.com/codejam/contest/4344486/dashboard#s=p1

const int MAXN = 55 + 2;

int N;
char a[MAXN][MAXN];
ll readInput() {
    si(N);
    FOR(i,1,N+1)
        ss(a[i], 1);
    return 0;
}

/************************************** BRUTE ***************************************************/
vi permuR;
vi permuC;
bool ok;
char b[MAXN][MAXN];
void check() {
    FOR(n,1,N+1)
        ms(b[n] + 1, '.');
    b[N/2+1][N/2+1] = 'X';
    FOR(i,1,N/2+1) {
        b[i][i] = 'X';
        b[i][N-i+1] = 'X';
        b[N-i+1][i] = 'X';
        b[N-i+1][N-i+1] = 'X';
    }
    FOR(i,1,N+1) FOR(j,1,N+1) {
        if(a[permuR[i]][permuC[j]] != b[i][j]) 
            return;
    }
    ok = true;
}
void searchC(int n) {
    permuC.clear();
    permuC.resize(1);
    for (int i = 1; i <= n; ++i)
        permuC.push_back(i);
    do {
        check();
    } while (next_permutation(permuC.begin()+1, permuC.end()));
}
void searchR(int n) {
    permuR.clear();
    permuR.resize(1);
    for (int i = 1; i <= n; ++i) 
        permuR.push_back(i);
    do {
        searchC(N);
    } while (next_permutation(permuR.begin()+1, permuR.end()));
}
bool brute() {
    ok = false;
    searchR(N);
    if(ok)
        return true;
    return false;
}

/************************************** SOL ***************************************************/
int one;
int cnt;
vi rec[MAXN];
bool scanR() {
    FOR(i,1,N+1)
        rec[i].clear();

    one = 0;
    FOR(i,1,N+1) {
        cnt = 0;
        FOR(j,1,N+1) {
            if(a[i][j] == 'X') {
                ++cnt;
                rec[i].pb(j);
            }
        }

        if(cnt != 1 && cnt != 2)
            return false;
        if(cnt == 1) 
            ++one;
    }
    if(one != 1)
        return false;
    return true;
}
bool scanC() {
    one = 0;
    FOR(j,1,N+1) {
        cnt = 0;
        FOR(i,1,N+1) {
            if(a[i][j] == 'X') 
                ++cnt;
        }
        if(cnt != 1 && cnt != 2)
            return false;
        if(cnt == 1) 
            ++one;
    }
    if(one != 1)
        return false;
    return true;
}
set<pii> isRec;
bool verify() {
    isRec.clear();
    FOR(i,1,N+1) if(sz(rec[i]) == 2) {
        auto it = isRec.find( {rec[i][0], rec[i][1]} );
        if(it == isRec.end())
            isRec.insert( {rec[i][0], rec[i][1]} );
        else
            isRec.erase(it);
    }
    if(sz(isRec) > 0)
        return false;
    return true;
}
bool sol() {
    if(!scanR())
        return false;
    if(!scanC())
        return false;
    if(!verify())
        return false;
    return true;
}
bool solve() {
    return sol();
}
