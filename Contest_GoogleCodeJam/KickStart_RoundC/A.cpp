
// https://codejam.withgoogle.com/codejam/contest/4344486/dashboard

const int MAXN = 50 + 3;

char B[MAXN];
ll readInput() {
    ss(B,1);
    return 0;
}

int b[MAXN];
int a[MAXN];
char A[MAXN];
int n;
bool sol() {
    n = ssz(B,1) - 1;
    
    if(n & 1)
        return false;

    //convert
    FOR(i,1,ssz(B,1))
        b[i] = B[i] - 'A';

    //Process
    a[2] = b[1];
    for(int i = 4; i < ssz(B,1); i+=2) 
        a[i] = (b[i-1] - a[i-2] + 26) % 26;
    a[n-1] = b[n];
    for(int i = n-3; i > 0; i-=2)
        a[i] = (b[i+1] - a[i+2] + 26) % 26;

    //Convert
    FOR(i,1,ssz(B,1))
        A[i] = a[i] + 'A';
    return true;
}

bool solve() {
    return sol();
}
