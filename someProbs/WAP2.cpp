// [Exam4] Maximum Xor with Prefix and
// Suffix
// Description
// We have N numbers as an array, you need to find a prefix array and a suffix array,
// which we can get the maximum xor value with all elements in them. Notice that for
// prefix[0, l] and suffix[r, n - 1], do not intersect (l < r), and they can be empty.
// Limits
// －Memory limit per test: 256 megabytes
// －Time limit per test: The faster the better
// Compile & Environment
//  C++
//  g++ Main.cc -o Main -fno-asm -Wall -lm --static -std=c++0x -DONLINE_JUDGE
//  Java
// J2SE 7
// Maximum stack size is 50m
// Input
// The first line is one number N (1 <= N <= 100000)
// The second line contains N numbers ai(0 <= ai <= 1e12) separated by space,
// which represents the array.
// Output
// Just output the maximum xor result.
// Sample Test
// Input
// 3
// 1 2 3
// output
// 3

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 100005;
#define ull unsigned long long

vector<ull> pre;
vector<ull> suf;
vector<ull> res;
vector<ull> a;

unsigned n;
void readInput() {
    cin >> n;
	pre.resize(n+1);
	suf.resize(n+1);
	res.resize(n+1);
	a.resize(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

ull findMax(const vector<ull> &arr, int l, int r) {
	ull result = 0;
	for (int i = l; i <= r; ++i)
		result = max(result, arr[i]);

	return result;
}

ull solve() {
	//Build prefix
	for (int i = 1; i < n; ++i) 
		pre[i] = pre[i - 1] ^ a[i];
	
	//Build suffix
	for (int i = n-1; i >= 1; --i) 
		suf[i] = suf[i + 1] ^ a[i];
	
	//find Max XOR
	ull ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, max(findMax(pre, 0, i), findMax(suf, i + 1, n-1)));

	return ans;
}

int main() {
	readInput();
	cout << solve() << endl;

	return 0;
}
