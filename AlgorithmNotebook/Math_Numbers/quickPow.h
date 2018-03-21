

// calc a^n in O(logn) 
long long qPow(long long a,long long n) {
    long long res = 1;
    while (n){
        if (n & 1) 
        	res *= a;
        a = (a * a);
        n >>= 1;
    }
    return res;
}
