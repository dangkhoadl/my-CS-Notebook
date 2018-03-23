
// https://codejam.withgoogle.com/codejam/contest/9234486/dashboard#s=p1

const int MAXN = 2e4 + 3;
const int MAXK = 5e4 + 3;

int N, K;
vi V;
ll readInput() {
    V.clear();

    sii(N, K);

    int temp;
    REP(N) {
        si(temp);
        V.pb(temp);
    }

    return 0;
}

bool areSame(double a, double b) {
    return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
}
bool isBigger(double a, double b) {
    if(a > b && !(std::fabs(a - b) < std::numeric_limits<double>::epsilon()))
        return true;
    return false;
}
int binSearchPrev(const vector<int> &a, double x, int l, int r) {
    while (true) {
        if (l > r) {
            return l-1;
        }

        int m = l + (r-l)/2;
        if (areSame((double)a[m], x))
            return m;

        if (isBigger(x, (double)a[m]))
            l = m + 1;
        else
            r = m - 1;
    }
}


double E[MAXK];
double sol() {
    double sum = 0.0;
    FOR(i,0,sz(V)) {
        sum += V[i];
    }
    E[0] = (double)sum / N;

    // Greedy K > 0
    sort(all(V));
    FOR(k,1,K+1) {
        int idx = binSearchPrev(V, E[k-1], 0, sz(V)-1);
        sum = (idx+1) * E[k-1];

        FOR(i,idx+1,sz(V))
            sum += V[i];
        E[k] = sum / N;
    }
    
    return E[K];
}


void solve(unsigned long long t) {
    printf("Case #%llu: %.6lf\n", t, sol());
}
