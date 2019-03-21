

/*------------------------------ Check if n is a prime -------------------------------------*/
bool isPrime(int n) {
    if(n <= 1)
        return false;
    if(n == 2)
        return true;
    if(n % 2 == 0)
        return false;

    for(int i = 3; i <= (int)sqrt(n); i += 2)
        if(n%i == 0)
            return false;
    return true;
}

/*---------------------------------- check a list of prime between [2,n] ---------------------------------*/
#define MAXN 2000
bool prime[MAXN];
void sieve(int n) {
    memset(prime, true, (n+1) * sizeof(bool));
    prime[0] = false;
    prime[1] = false;

    for(int i = 2; i <= (int)sqrt(n); ++i)
        if(prime[i])
            for(int k = i*i; k <= n; k += i)
                prime[k] = false;
}

/*------------------------- factorize a number(n) --> prime numbers ------------------------------------------*/
// Eg: 6 = 2*3, 4 = 2*2, 45 = 3*3*5
vector<int> factorizePrime(int n) {
    vector<int> prfac;

    for(int x = 2; x*x <= n; ++x) 
        while(n % x == 0) {
            prfac.push_back(x);
            n /= x;
        }
    if(n > 1)
        prfac.push_back(n);

    return prfac;
}
