const int MAXN = 100 + 3;

int N, P;
int G[MAXN];
int readInput() {
    sii(N,P);
    FOR(i,1,N+1) si(G[i]);

    return 0;
}

int floor_(int m, int n) {
    assert(n != 0);

    int a = (m-n)/n+1;
    while((m-n) < n*a) --a;
    ++a;

    int b = m/n-1;
    while(n*b <= m) ++b;
    --b;

    if(a == b)
        return a;
    assert(1==0);
}
int ceil_(int m, int n) {
    assert(n != 0);

    int a = m/n+1;
    while(m <= n*a) --a;
    ++a;

    int b = (m+n)/n-1;
    while(n*b < (m+n)) ++b;
    --b;

    if(a==b)
        return a;
    assert(1==0);
}
int sol() {
    int p0=0,p1=0,p2=0,p3=0;
    FOR(i,1,N+1) {
        if(G[i] % P == 0) ++p0;
        else if(G[i] % P == 1) ++p1;
        else if(G[i] % P == 2) ++p2;
        else if(G[i] % P == 3) ++p3;
    }

    if(P == 2)
        return p0 + ceil_(p1,2);

    if(P == 3) 
        return p0 + min(p1,p2) + ceil_((int)abs(p1-p2),3);

    if(P == 4) 
        return p0 + floor_(p2,2) + min(p1,p3) + \
            ceil_(2*(p2%2) + (int)abs(p1-p3), 4);
}


void solve(unsigned long long fdfsfv_t) {
    printf("Case #%llu: %lld\n", fdfsfv_t, sol());
}
