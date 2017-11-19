

// Hash a string to integer. parameter p,x
// Example , p = 1000000007
// 			 x = 263
// P small --> the int return likely be duplicated

inline long long add(long long a, long long b,long long MOD) {
    if(a<0)
        a = (a%MOD) + MOD;
    if(b<0)
        b = (b%MOD) + MOD;
    return ((a%MOD) + (b%MOD)) % MOD;
}
inline long long mul(long long a,long long b, long long MOD) {
    if(a<0)
        a = (a%MOD) + MOD;
    if(b<0)
        b = (b%MOD) + MOD;
    return ((a%MOD) * (b%MOD)) % MOD;
}
inline long long power(long long a, long long n, long long MOD) {
    assert(n>=0);
    assert(a>=0);
    if(a == 0)
        return 0;
    if(n == 0)
        return 1;
    if(n == 1)
        return a%MOD;

    long long pow_half = power(a, n/2, MOD);
    long long pow_half_sq = (pow_half  * pow_half) % MOD;
    if(n & 1)
        return (pow_half_sq * a) % MOD;
    return pow_half_sq;
}


long long hashString(const string &S, long long x, long long p) {
    long long num = 0;
    for(int i=0; i< S.size(); ++i)
        num = add(num,mul(S[i],power(x,i,p),p),p);
    return num;
}

// [start,end)
long long hashSubString(const string &S, int start, int end, long long x, long long p) {
    assert(start >= 0 and end > start and end <= S.size());
    long long num = 0;
    for(int i = 0; i < (end-start); ++i)
        num = add(num,mul(S[i+start],power(x,i,p),p),p);
    return num;
}
