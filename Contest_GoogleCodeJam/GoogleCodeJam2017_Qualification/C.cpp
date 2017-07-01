
// https://codejam.withgoogle.com/codejam/contest/3264486/dashboard#s=p2

int N, K;
ll readInput() {
	scanf("%lld %lld", &N, &K);
	return 0;
}

/*_________________________________ Solution 1 O(K*log(K)) _________________________________*/
pii sol1() {
	priority_queue<int> S;
	S.push(N);
	int x0 = 0;
	int x1 = 0;
	FOR(k, 1, K + 1, 1) {
		int x = S.top();
		S.pop();
		x0 = ceil((double)(x - 1) / 2);
		x1 = floor((double)(x - 1) / 2);
		S.push(x0);
		S.push(x1);
	}
	return{ x0,x1 };
}

