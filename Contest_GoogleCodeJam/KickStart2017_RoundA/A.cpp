
// https://codejam.withgoogle.com/codejam/contest/8284486/dashboard

int R,C;
ll readInput() {
    sii(R,C);
    return 0;
}

const long long MOD = 1e9 + 7;
inline long long add(long long a, long long b) {
    return ((a%MOD) + (b%MOD)) % MOD;
}
inline long long sub(long long a,long long b) {
    return ((a%MOD) - (b%MOD) + MOD) % MOD;
}
inline long long mul(long long a,long long b) {
    return ((a%MOD) * (b%MOD)) % MOD;
}

inline long long power(long long a, long long b) {
    if(b == 0)
        return 1;
    if(b == 1)
        return a%MOD;
    long long halfb = power(a,b/2);
    if(b & 1)
        return (((halfb * halfb) % MOD ) * a ) % MOD;
    return (halfb * halfb) % MOD;
}
inline long long inv(long long b) {
    return power(b,MOD-2) % MOD;
}
inline long long divi(long long a, long long b) {
    return mul(a,inv(b)) % MOD; 
}

// 1 + 2 + ... + n = n(n+1)/2
inline int sumFirstN(int n){
    return divi(mul(n, add(n,1)), 2);
}
// 1^2 + 2^2 + ... + n^2 = n(n+1)(2n+1) / 6
inline int sumFirstNSquare(int n){
    return divi(mul(mul(n,add(n,1)),add(mul(2,n),1)),6);
}
// 1^3 + 2^3 + ... + n^3 = n^2 * (n+1)^2 / 4
inline int sumFirstNCube(int n) {
    return divi(mul(power(n,2),power(n+1,2)),4);
}
int sol() {
    // Math formula: https://www.quora.com/How-many-squares-have-all-four-vertices-in-an-n-times-n-grid-of-dots
    int n = min(R,C);
    int m = max(R,C);
    return add(sub(sumFirstNCube(n-1),mul(sumFirstNSquare(n-1),add(m,n))),mul(mul(m,n),sumFirstN(n-1)));
}

ll solve() {
    
    return sol();
}
