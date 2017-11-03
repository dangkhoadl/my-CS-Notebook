
inline long long gcd(long long a, long long b) {
    assert(a >= 0 and b >= 0 and a + b > 0);

    while(a>0 and b>0) {
        if(a >= b)
            a %= b;
        else
            b %= a; 
    }
    return max(a,b);
}
inline vector<int> extendedGCD(int a, int b) {
    assert(a >= b and b >= 0 and a + b > 0);

    if(b == 0)
        return {a,1,0};

    vector<int> dpq = extendedGCD(b, a%b);
    int x = dpq[2];
    int y = dpq[1] - dpq[2] * (a/b);

    assert(a % dpq[0] == 0 and b % dpq[0] == 0);
    assert(dpq[0] == a * x + b * y);
    return {dpq[0],x,y};
}

const long long MOD = 1e9+7;
inline long long add(long long a, long long b) {
    if(a<0)
        a = (a%MOD) + MOD;
    if(b<0)
        b = (b%MOD) + MOD;
    return ((a%MOD) + (b%MOD)) % MOD;
}
inline long long sub(long long a,long long b) {
    if(a<0)
        a = (a%MOD) + MOD;
    if(b<0)
        b = (b%MOD) + MOD;
    return ((a%MOD) - (b%MOD) + MOD) % MOD;
}
inline long long mul(long long a,long long b) {
    if(a<0)
        a = (a%MOD) + MOD;
    if(b<0)
        b = (b%MOD) + MOD;
    return ((a%MOD) * (b%MOD)) % MOD;
}
inline long long power(long long a, long long b) {
    assert(b>0);
    assert(a>0);
    if(a == 0)
        return 0;
    if(b == 0)
        return 1;
    if(b == 1)
        return a%MOD;
    long long halfb = power(a, b/2);
    if(b & 1)
        return (((halfb * halfb) % MOD ) * a ) % MOD;
    return (halfb * halfb) % MOD;
}
inline long long inv(long long b) {
    if(b<0)
        b = (b%MOD) + MOD;
    assert(MOD > 1 and b > 0 and gcd(b, MOD) == 1);
    vector<int> dts = extendedGCD(MOD, b%MOD);
    return dts[2];
}
inline long long divi(long long a, long long b) {
    if(a<0)
        a = (a%MOD) + MOD;
    if(b<0)
        b = (b%MOD) + MOD;
    return mul(a,inv(b)); 
}
