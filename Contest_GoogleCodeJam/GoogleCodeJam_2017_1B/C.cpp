
// https://codejam.withgoogle.com/codejam/contest/8294486/dashboard#s=p2

const int MAXN = 100 + 3;
const int MAXQ = 100 + 3;

int N, Q;
int E[MAXN], S[MAXN];
int D[MAXN][MAXN];
int U[MAXQ], V[MAXQ];
ll readInput() {
    sii(N,Q);
    FOR(n,1,N+1) sii(E[n], S[n]);
    FOR(i,1,N+1) FOR(j,1,N+1) si(D[i][j]);
    FOR(q,1,Q+1) sii(U[q], V[q]);

    return 0;
}

int dist[MAXN][MAXN];
void STP_dist() {
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j) {
                if(i == j)
                    dist[i][j] = 0;
                else if(dist[i][k] >= inf || dist[k][j] >= inf)
                    dist[i][j] = min(dist[i][j], inf);
                else
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
}

double tim[MAXN][MAXN];
void STP_time() {
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j) {
                if(i == j)
                    tim[i][j] = 0;
                else if(tim[i][k] >= (double)inf || tim[k][j] >= (double)inf)
                    tim[i][j] = min(tim[i][j], (double)inf);
                else
                    tim[i][j] = min(tim[i][j], tim[i][k] + tim[k][j]);
            }
}

vector<double> res;
void sol() {
    // fill dist + floydWarshall
    ms(dist, 0x7f);
    FOR(i,1,N+1) FOR(j,1,N+1) if(D[i][j] != -1) dist[i][j] = D[i][j];
    STP_dist();

    // fill time + floydWarshall
    ms(tim, 0x7f);
    FOR(i,1,N+1) FOR(j,1,N+1) {
        if(E[i] < dist[i][j]) 
            continue;
        tim[i][j] = (double)dist[i][j] / S[i]; 
    }
    STP_time();
    
    // get res
    res.clear();
    FOR(q,1,Q+1) res.pb(tim[U[q]][V[q]]);
    return;
}


void solve(unsigned long long t) {
    sol();
    printf("Case #%llu:", t);
    FOR(i,0,sz(res)) printf(" %0.6lf", res[i]);
    printf("\n");
}
