

// Rabin-Karp
// Find the index of pattern P in text T:
//		Examples:
//			P = aba
//			T = abacaba
//				--> 0 4

//  O(|T| + (q+1)*|P|) : q = number of occurrences of P in T (the case pHash == tHash, usually small)

inline long long add(long long a, long long b,long long MOD) {
    if(a<0)
        a = (a%MOD) + MOD;
    if(b<0)
        b = (b%MOD) + MOD;
    return ((a%MOD) + (b%MOD)) % MOD;
}
inline long long sub(long long a,long long b, long long MOD) {
    if(a<0)
        a = (a%MOD) + MOD;
    if(b<0)
        b = (b%MOD) + MOD;
    return ((a%MOD) - (b%MOD) + MOD) % MOD;
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

// [a,b)
int randInt(int a, int b) {
    // Seed with a real random value, if available
    random_device r;
    default_random_engine e1(r());
    uniform_int_distribution<int> uniform_dist(a, b-1);
    return uniform_dist(e1);
}

// compare if 2 substrings of s1 and s2 are Equal
// [start,end)
bool cmpsubString(const string &s1, int start1, int end1, const string &s2, int start2, int end2) {
    assert(start1 >= 0 and start1 < end1 and end1 <= s1.size());
    assert(start2 >= 0 and start2 < end2 and end2 <= s2.size());
    if((end1 - start1) != (end2 - start2))
        return false;
    for(int i = 0; i < (end1-start1); ++i) {
        if(s1[i+start1] != s2[i+start2])
            return false;
    }
    return true;
}


vector<int> preCompute(const string &T, const string &P, long long x, long long p) {
    vector<int> H(T.size() - P.size() + 1);
    H[T.size() - P.size()] = hashSubString(T, T.size() - P.size(), T.size(), x, p);
    long long y = power(x,P.size(),p);

    for(int i=(T.size()-P.size()-1); i >= 0; --i)
        H[i] = sub(add(mul(x,H[i+1],p),T[i],p),mul(y,T[i+P.size()],p),p);
    return H;
}
vector<int> rabinKarp(const string &T, const string &P) {
    vector<int> result;

    // Assign a Big Prime
    const long long p = 1e9+7;
    long long x = randInt(1,p);

    long long pHash = hashString(P,x,p);
    vector<int> H = preCompute(T,P,x,p);

    for(int i=0; i <= (T.size()-P.size()); ++i) {
        if(pHash != H[i])
            continue;
        if(cmpsubString(T,i,i+P.size(),P,0,P.size()))
            result.push_back(i);
    }
    return result;
}