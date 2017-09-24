
// https://code.google.com/codejam/contest/12254486/dashboard#s=p0

string s;
int a, b;
ll readInput() {
	cin >> s;
	cin >> a >> b;
	--a;
	--b;
	return 0;
}

int head, tail;
int hi, ti;
int bcnt;
int hcnt, tcnt;
ll solve() {
	hcnt = 0;
	bcnt = 0;
	tcnt = 0;
	head = a / sz(s);
	tail = b / sz(s);
	hi = a % sz(s);
	ti = b % sz(s);

	if (head == tail) {
		for_i(hi, ti + 1, 1)
			if (s[i] == 'B')
				++hcnt;
		return hcnt;
	}

	//bcnt
	for_i(0, sz(s), 1)
		if (s[i] == 'B')
			++bcnt;

	//head
	for_i(hi,sz(s),1)
		if (s[i] == 'B')
			++hcnt;

	//tail
	for_i(0, ti+1, 1)
		if (s[i] == 'B')
			++tcnt;

	return hcnt + tcnt + (tail-head-1)*bcnt;
}
