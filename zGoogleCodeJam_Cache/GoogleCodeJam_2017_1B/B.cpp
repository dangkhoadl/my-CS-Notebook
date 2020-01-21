
// https://codejam.withgoogle.com/codejam/contest/8294486/dashboard#s=p1

const int MAXN = 1000 + 3;

int N;
int R,O,Y,G,B,V;
ll readInput() {
    cin >> N >> R >> O >> Y >> G >> B >> V;
    return 0;
}


bool IMPOS;
string res; 
void sol() {
    IMPOS = false;
    res.clear();

    // Edge cases
    if(R>0 && R==G) {
        if(O!=0 || Y!=0 || B!=0 || V!=0) {
            IMPOS = true;
            return;
        }
        REP(R) {
            res.pb('R');
            res.pb('G');
        }
        return;
    }

    if(B>0 && O==B) {
        if(R!=0 || Y!=0 || G!=0 || V!=0) {
            IMPOS = true;
            return;
        }
        REP(B) {
            res.pb('B');
            res.pb('O');
        }
        return;
    }

    if(Y>0 && Y==V) {
        if(R!=0 || O!=0 || G!=0 || B!=0) {
            IMPOS = true;
            return;
        }
        REP(Y) {
            res.pb('Y');
            res.pb('V');
        }
        return;
    }


    // Simplify 
    vector<string> red;
    string r;
    if(G>0) {
        r.pb('R'); --R;
        REP(G) {
            r.pb('G');
            r.pb('R'); --R;
        }
        if(R<0) {
            IMPOS = true;
            return;
        }
        red.pb(r);
    }
    REP(R) red.pb("R");
    
    vector<string> blue;
    string b;
    if(O>0) {
        b.pb('B'); --B;
        REP(O) {
            b.pb('O');
            b.pb('B'); --B;
        }
        if(B<0) {
            IMPOS = true;
            return;
        }
        blue.pb(b);
    }
    REP(B) blue.pb("B");


    vector<string> yell;
    string y;
    if(V>0) {
        y.pb('Y'); --Y;
        REP(V) {
            y.pb('V');
            y.pb('Y'); --Y;
        }
        if(Y<0) {
            IMPOS = true;
            return;
        }
        yell.pb(y);
    }
    REP(Y) yell.pb("Y");


    // check
    int phuong = sz(red) + sz(blue) + sz(yell);
    if(2*sz(red) > phuong) {
        IMPOS = true;
        return;
    }
    if(2*sz(blue) > phuong) {
        IMPOS = true;
        return;
    }
    if(2*sz(yell) > phuong) {
        IMPOS = true;
        return;
    }

    // Rank
    priority_queue<pair<int, vector<string>>> PQ;
    PQ.push({sz(red), red});
    PQ.push({sz(blue), blue});
    PQ.push({sz(yell), yell});

    vector<string> champ = PQ.top().se; PQ.pop();
    vector<string> runup = PQ.top().se; PQ.pop();
    vector<string> loser = PQ.top().se; PQ.pop();

    // Distribute
    vector<string> khoa;
    FOR(i,0,sz(loser)) khoa.pb(loser[i]);
    FOR(i,0,sz(runup)) khoa.pb(runup[i]);
    FOR(i,0,sz(champ)) khoa.pb(champ[i]);

    vector<string> thao(phuong);
    FOR(i,0,sz(thao)) if(i%2==0) {
        thao[i] = khoa.back();
        khoa.pop_back();
    }
    FOR(i,0,sz(thao)) if(i%2!=0) {
        thao[i] = khoa.back();
        khoa.pop_back();
    }

    // get res
    FOR(i,0,sz(thao)) {
        res += thao[i];
    }
}

void solve(unsigned long long t) {
    sol();
    if(IMPOS)
        cout << "Case #" << t << ": IMPOSSIBLE" << endl;
    else
        cout << "Case #" << t << ": " << res << endl;;
}
