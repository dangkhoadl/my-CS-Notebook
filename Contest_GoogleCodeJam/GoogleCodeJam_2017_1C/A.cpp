
// https://codejam.withgoogle.com/codejam/contest/3274486/dashboard

const int MAXN = 1000 + 3;

int N,K;
int R[MAXN], H[MAXN];
ll readInput() {
    sii(N, K);
    FOR(i,1,N+1) sii(R[i], H[i]);
    
    return 0;
}

double get_top(int r, int h) {
    return PI*r*r + 2*PI*r*h;
}
double get_bot(int r) {
    return PI*r*r;
}

double sol() {
    vector<pair<pair<int, double>, double>> thao;
    FOR(i,1,N+1) thao.pb({{-R[i], get_top(R[i], H[i]) - get_bot(R[i])}, get_top(R[i], H[i])});
    sort(all(thao));

    double tam = -1.0;
    FOR(i,0,sz(thao)-K+1) {
        double phuong = thao[i].se;

        priority_queue<double> PQ;
        FOR(j,i+1,sz(thao)) PQ.push(thao[j].fi.se);
        int cnt = K-1;
        while(cnt>0) {
            phuong += PQ.top(); PQ.pop();
            --cnt;
        }

        tam = max(tam, phuong);
    }

    return tam;
}


void solve(unsigned long long t) {
    printf("Case #%llu: %0.9lf\n", t, sol());
}
