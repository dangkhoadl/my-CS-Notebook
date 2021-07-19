

// Hash a string to integer. parameter p,x
// Example , p = 1000000007
// 			 x = 263
// P small --> the int return likely be duplicated

inline int64_t add(int64_t a, int64_t b, int64_t MOD) {
    if(a<0) a = (a%MOD) + MOD;
    if(b<0) b = (b%MOD) + MOD;
    return ((a%MOD) + (b%MOD)) % MOD;
}
inline int64_t mul(int64_t a,int64_t b, int64_t MOD) {
    if(a<0) a = (a%MOD) + MOD;
    if(b<0) b = (b%MOD) + MOD;
    return ((__int128)(a%MOD) * (b%MOD)) % MOD;
}
inline int64_t power(int64_t a, int64_t n, int64_t MOD) {
    assert(n>=0);
    assert(a>=0);
    if(n == 0) return 1;
    if(a == 0) return 0;
    if(n == 1) return a%MOD;

    int64_t pow_half = power(a, n/2, MOD);
    int64_t pow_half_sq = mul(pow_half, pow_half, MOD);
    if(n & 1) return mul(pow_half_sq, a, MOD);
    return pow_half_sq;
}


int64_t hashString(const string &S, int64_t x, int64_t p) {
    int64_t num = 0;
    for(int i=0; i< S.size(); ++i)
        num = add(num,mul(S[i],power(x,i,p),p),p);
    return num;
}

// [start,end)
int64_t hashSubString(const string &S, int start, int end, int64_t x, int64_t p) {
    assert(start >= 0 and end > start and end <= S.size());
    int64_t num = 0;
    for(int i = 0; i < (end-start); ++i)
        num = add(num,mul(S[i+start],power(x,i,p),p),p);
    return num;
}
