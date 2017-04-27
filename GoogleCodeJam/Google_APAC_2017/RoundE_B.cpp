/*
Problem B. Beautiful Numbers
This contest is open for practice. You can try every problem as many times as you like, though we won't keep track of which problems you solve. Read the Quick-Start Guide to get started.
Small input
6 points
Solve B-small
Judge's response for last submission: Correct.
Large input
15 points
Solve B-large
Judge's response for last submission: Correct.
Problem

We consider a number to be beautiful if it consists only of the digit 1 repeated one or more times. Not all numbers are beautiful, but we can make any base 10 positive integer beautiful by writing it in another base.

Given an integer N, can you find a base B (with B > 1) to write it in such that all of its digits become 1? If there are multiple bases that satisfy this property, choose the one that maximizes the number of 1 digits.

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of one line with an integer N.

Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the base described in the problem statement.

Limits

1 ≤ T ≤ 100.
Small dataset

3 ≤ N ≤ 1000.
Large dataset

3 ≤ N ≤ 1018.
Sample


Input

Output

2
3
13

Case #1: 2
Case #2: 3

In case #1, the optimal solution is to write 3 as 11 in base 2.

In case #2, the optimal solution is to write 13 as 111 in base 3. Note that we could also write 13 as 11 in base 12, but neither of those representations has as many 1s.
*/


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <istream>
#include <vector>
#include <list>
#include <forward_list>
#include <string>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <set>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <time.h>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <utility>
#include <climits>
#include <cassert>
#include <istream>
#include <random>
#include <iterator>
#include <memory>
#include <cctype>
using namespace std;

#define ll long long
#define ull unsigned long long

//parameters
ll T;
ull n;

/*-------------------------------------------------------------------*/
bool check(int x) {
	ll tmp = n;
	while (tmp) {
		if (tmp % x != 1) return false;
		tmp /= x;
	}
	return true;
}

ll solve() {
	int minN = (int)min((ll)n, 100000LL);
	for (int i = 2; i <= minN; ++i) {
		if (check(i))
			return i;
	}

	int x = (int)pow(n, 1 / 3.0);
	if (check(x))
		return x;
	
	x = (int)pow(n, 1 / 2.0);
	if (check(x))
		return x;
	
	return n - 1;
}
/**************	 THINK SIMPLY ************************/
int main(int agrc, char *argv[]) {
	freopen("..\\Debug\\Input.txt", "r", stdin);
	freopen("..\\Debug\\Output.txt", "w", stdout);
	//std::ios::sync_with_stdio(false);
	/*-------------------------------------------------------------------*/
	cin >> T;
	for (ull id = 1; id <= T; ++id) {
		cin >> n;
		//Clear parameter here
		cout << "Case #" << id << ": " << solve() << endl;
	}
	return 0;
}
