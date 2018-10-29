
// https://code.google.com/codejam/contest/3264486/dashboard#s=p1

vi nn;
int exam(int num) {
	nn.clear();
	int pos = 0;
	ull a = 0;
	while(num) {
		a = num % 10;
		num /= 10;
		nn.pb(a);
	}
	reverse(all(nn));
	
	for_i(0, sz(nn)-1, 1) {
		if (nn[i] < nn[i + 1])
			pos = i+1;
		if (nn[i] > nn[i + 1])
			return pos;
	}
	return -1;
}

ull solve() {
	ull res = 0;
	int e = exam(n);
	pr(e);
	if (e == -1)
		return n;
	
	for_i(e + 1, sz(nn), 1)
		nn[i] = 0;
	
	for_i(0, sz(nn), 1) 
		res = res * 10 + nn[i];
	
	return --res;
}
