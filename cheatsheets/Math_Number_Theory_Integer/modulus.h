

int mod(int x, int m) {
    return ((x%m)+m) % m;
}

/*****************************************************/
const int64_t MOD = 12 * 60 * 60 * (int64_t)1e9;

inline int64_t add(int64_t a, int64_t b) {
    if(a<0) a = (a%MOD) + MOD;
    if(b<0) b = (b%MOD) + MOD;
    return ((a%MOD) + (b%MOD)) % MOD;
}
inline int64_t sub(int64_t a,int64_t b) {
    if(a<0) a = (a%MOD) + MOD;
    if(b<0) b = (b%MOD) + MOD;
    return ((a%MOD) - (b%MOD) + MOD) % MOD;
}
inline int64_t mul(int64_t a,int64_t b) {
    if(a<0) a = (a%MOD) + MOD;
    if(b<0) b = (b%MOD) + MOD;
    return ((__int128)(a%MOD) * (b%MOD)) % MOD;
}

/************************* Power (req mul) ****************************/
inline int64_t power(int64_t a, int64_t n) {
    assert(n>=0);
    assert(a>=0);
    if(n == 0) return 1;
    if(a == 0) return 0;
    if(n == 1) return a%MOD;

    int64_t pow_half = power(a, n/2);
    int64_t pow_half_sq = mul(pow_half, pow_half);
    if(n & 1) return mul(pow_half_sq, a);
    return pow_half_sq;
}

/************************* INV, DIVI (req mul) ****************************/
inline int64_t gcd(int64_t a, int64_t b) {
    assert(a >= 0 and b >= 0 and a + b > 0);

    while(a>0 and b>0) {
        if(a >= b) a %= b;
        else b %= a;
    }
    return max(a,b);
}
inline vector<int64_t> extendedGCD(int64_t a, int64_t b) {
    assert(a >= b and b >= 0 and a + b > 0);

    if(b == 0) return {a,1,0};

    vector<int64_t> dpq = extendedGCD(b, a%b);
    int64_t x = dpq[2];
    int64_t y = dpq[1] - dpq[2] * (a/b);

    assert(a % dpq[0] == 0 and b % dpq[0] == 0);
    assert(dpq[0] == a * x + b * y);
    return {dpq[0],x,y};
}
inline int64_t inv(int64_t b) {
    if(b<0) b = (b%MOD) + MOD;
    assert(MOD > 1 and b > 0 and gcd(b, MOD) == 1);
    vector<int64_t> dts = extendedGCD(MOD, b%MOD);
    return dts[2];
}
inline int64_t divi(int64_t a, int64_t b) {
    if(a<0) a = (a%MOD) + MOD;
    if(b<0) b = (b%MOD) + MOD;
    return mul(a,inv(b));
}
