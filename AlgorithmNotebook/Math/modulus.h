

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
