
// https://codejam.withgoogle.com/2018/challenges/0000000000007883/dashboard

const int MAXR = 100 + 3;
const int MAXC = 100 + 3;

int R,C,H,V;
int cells[MAXR][MAXC];

ll readInput() {
    sii(R,C); sii(H,V);

    char newline;
    sc(newline);

    FOR(r,1,R+1) {
        FOR(c,1,C+1) {
            char temp;
            sc(temp);
            cells[r][c] = (temp == '@') ? 1 : 0;
        }
        sc(newline);
    }
    return 0;
}


int col[MAXC];
int row[MAXR];
bool sol() {
    int total = 0;
    FOR(r,1,R+1) FOR(c,1,C+1) total += cells[r][c];
    if(total == 0) return true;

    //check 1
    if(total % ((H+1)*(V+1)) != 0) 
        return false;

    ms(col,0);
    ms(row,0);
    FOR(r,1,R+1) FOR(c,1,C+1) {
        row[r] += cells[r][c];
        col[c] += cells[r][c];
    }


    // check 2
    if(total % (H+1) != 0)
        return false;
    if(total % (V+1) != 0)
        return false;

    // check row
    int phuong = total / (H+1);
    int p = 0;
    vi H_P(1,1);
    FOR(r,1,R+1) {
        p += row[r];

        if(p == phuong) {
            H_P.pb(r);
            H_P.pb(r+1);
            p = 0;
        }
    }
    H_P.pop_back();
    if(p != 0) return false;

    // check col
    int thao = total / (V+1);
    int t = 0;
    vi V_T(1,1);
    FOR(c,1,C+1) {
        t += col[c];
        if(t == thao) {
            V_T.pb(c);
            V_T.pb(c+1);
            t = 0;
        }
    }
    V_T.pop_back();
    if(t != 0) return false;


    // Check all
    int khoa = total / ((H+1)*(V+1));
    for(int i=0; i<sz(H_P)-1; i+=2) for(int j=0; j<sz(V_T)-1; j+=2) {
        int cnt = 0;
        FOR(x,H_P[i],H_P[i+1]+1) FOR(y,V_T[j],V_T[j+1]+1) {
            cnt += cells[x][y];
        }
        if(cnt != khoa) {
            return false;
        }
    }

    return true;
}


void solve(unsigned long long t) {
    if(sol())
        printf("Case #%llu: POSSIBLE\n", t);
    else
        printf("Case #%llu: IMPOSSIBLE\n", t);
}
