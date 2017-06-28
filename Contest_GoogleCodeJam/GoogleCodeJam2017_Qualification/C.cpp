
// https://codejam.withgoogle.com/codejam/contest/3264486/dashboard#s=p2

int N, K;
ll readInput() {
	cin >> N >> K;
	return 0;
}
//______ Brute
const int ST = 1002;
bool stall[ST];
int ls[ST];
int rs[ST];
int calls(int pos) {
	int l = 0;
	for_id(pos, 0, -1) {
		if (stall[i] == true)
			break;
		++l;
	}
	return l;
}
int calrs(int pos) {
	int r = 0;
	for_i(pos, N + 1, 1) {
		if (stall[i] == true)
			break;
		++r;
	}
	return r;
}
int minA[ST];
int maxA[ST];
vi cans;
vi cans2;
int choosePos() {
	for_i(1, N + 1, 1) {
		ls[i] = calls(i);
		rs[i] = calrs(i);
	}

	//max min
	int maxMin = -1;
	for_i(1, N + 1, 1) {
		//max min
		minA[i] = min(ls[i], rs[i]);
		maxA[i] = max(ls[i], rs[i]);
		maxMin = max(maxMin, minA[i]);
	}

	//rule
	cans.clear();
	for_i(1, N + 1, 1) {
		if (minA[i] == maxMin)
			cans.pb(i);
	}
	if (sz(cans) == 1) {
		stall[cans[0]] = true;
		return cans[0];
	}

	cans2.clear();
	int maxMax = -1;
	for_i(0, sz(cans), 1) {
		maxMax = max(maxMax, maxA[cans[i]]);
	}
	for_i(0, sz(cans), 1) {
		if (maxA[cans[i]] == maxMax)
			cans2.pb(cans[i]);
	}
	int minRes = inf;
	for_i(0, sz(cans2), 1) {
		minRes = min(minRes, cans2[i]);
	}

	stall[minRes] = true;
	return minRes;
}
pii brute() {
	ms(stall, false);
	stall[0] = true;
	stall[N + 1] = true;
	fill(ls, ls + ST, 0);
	fill(rs, rs + ST, 0);

	int pos = 0;
	for_i(0, K, 1) {
		pos = choosePos();
	}

	int l = 0;
	for_id(pos - 1, -1, -1) {
		if (stall[i] == true)
			break;
		++l;
	}
	int r = 0;
	for_i(pos + 1, N + 1, 1) {
		if (stall[i] == true)
			break;
		++r;
	}
	return{ max(l, r) , min(l,r) };
}
//______ Solution
pii sol1() {
	priority_queue<int> S;
	S.push(N);
	int x0 = 0;
	int x1 = 0;
	FOR(k, 1, K + 1, 1) {
		int x = S.top();
		S.pop();
		x0 = ceil((double)(x - 1) / 2);
		x1 = floor((x - 1) / 2);
		S.push(x0);
		S.push(x1);
		//pr_(x); pr_(x0); pr(x1);
	}
	return{ x0,x1 };
}
