#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using Long = unsigned long long;
struct XLong {
	static Long const F = 100000000ULL;
	vector<Long> d;
	XLong() = default;
	XLong(vector<Long>&& i) : d{ move(i) } {}
	XLong(Long i) : d{ i } {}

	//make all array elements in range of 8 digits
	void inRange() {
		Long rem = 0;
		for (Long& dp : d) {
			dp += rem;
			rem = dp / F;
			dp %= F;
		}
		while (d.back() == 0)
			d.pop_back();
	}
	//plus
	XLong operator + (XLong const& r) const {
		size_t m = 1 + max(d.size(), r.d.size());
		XLong ret{ vector<Long>(m, 0) };
		for (size_t i = 0; i<d.size(); i++)
			ret.d[i] = d[i];
		for (size_t i = 0; i<r.d.size(); i++)
			ret.d[i] += r.d[i];
		ret.inRange();
		return ret;
	}
	//multiply
	XLong operator * (XLong const& r) const {
		size_t m = 1 + 2 * max(d.size(), r.d.size());
		XLong ret{ vector<Long>(m, 0ULL) };
		for (size_t i = 0; i<d.size(); i++) {
			for (size_t j = 0; j<r.d.size(); j++) {
				int p = i + j;
				Long dp = d[i] * r.d[j];
				ret.d[p] += dp%F;
				ret.d[p + 1] += dp / F;
			}
		}
		ret.inRange();
		return ret;
	}
	//output
	void print() {
		inRange();
		for (int i = d.size() - 1; i >= 0; i--) {
			if (i == d.size() - 1)
				printf("%lld", d[i]);
			else
				printf("%08lld", d[i]);
		}
	}
};

XLong Fibo(int n, int t1, int t2) {
	vector<XLong> F(n);
	F[0] = t1;
	F[1] = t2;
	for (int i = 2; i < n; ++i) {

		F[i] = F[i - 2] + F[i - 1] * F[i - 1];
	}
	return F[n - 1];
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n, t1, t2; cin >> t1 >> t2 >> n;
	XLong result = Fibo(n, t1, t2);
	result.print();

	return 0;
}
