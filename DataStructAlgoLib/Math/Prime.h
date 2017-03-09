/*-------------------------------------------------------------------*/
bool isPrime(int n) {
	if (n <= 1)
		return false;
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;

	for (int i = 3; i <= (int)sqrt(n); i += 2)
		if (n%i == 0)
			return false;
	return true;
}

/*-------------------------------------------------------------------*/
#define MAXN 2000
bool prime[MAXN];
void sieve(int n) {
	memset(prime, true, (n+1) * sizeof(bool));
	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i <= (int)sqrt(n); ++i)
		if (prime[i])
			for (int k = i*i; k <= n; k += i)
				prime[k] = false;
}
