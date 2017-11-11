

// 5. Advanced Problem: Organizing a Lottery


const int MAXN = 50000 + 3;

int S,P;
map<int, pair<vi, vector<char>>> PQ;
ll readInput() {
    sii(S,P);

    int a,b;
    REP(S) {
        sii(a, b);

        auto it = PQ.find(a);
        if(it == PQ.end()) 
            PQ.insert({a, {vi(),vector<char>(1,'l')}});
        else 
            PQ[a].se.pb('l');

        it = PQ.find(b);
        if(it == PQ.end()) 
            PQ.insert({b, {vi(),vector<char>(1,'r')}});
        else 
            PQ[b].se.pb('r');
    }

    int point;
    FOR(p,1,P+1) {
        si(point);

        auto it = PQ.find(point);
        if(it == PQ.end()) 
            PQ.insert({point, {vi(1,p), vector<char>()}});
        else 
            PQ[point].fi.pb(p);
    }
    
    return 0;
}


int res[MAXN];
void sol() {
    ms(res, 0);

    int cnt = 0;
    for_it(PQ) {
        vi index_ = it->se.fi;
        vector<char> vc = it->se.se; 

        FOR(i,0,sz(vc)) {
            if(vc[i] == 'l')
                ++cnt;
        }
        
        FOR(i,0,sz(index_)) {
            res[index_[i]] = cnt;
        }

        FOR(i,0,sz(vc)) {
            if(vc[i] == 'r')
                --cnt;
        }
    }
}

ll solve() {
    sol();

    FOR(p,1,P+1)
        cout << res[p] << ' ';
    cout << endl;

    return 0;
}
