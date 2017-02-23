/*
Problem A. Diwali lightings
This contest is open for practice. You can try every problem as many times as you like, though we won't keep track of which problems you solve. Read the Quick-Start Guide to get started.
Small input
5 points
Solve A-small
Judge's response for last submission: Correct.
Large input
8 points
Solve A-large
Judge's response for last submission: Correct.
Problem

Diwali is the festival of lights. To celebrate it, people decorate their houses with multi-color lights and burst crackers. Everyone loves Diwali, and so does Pari. Pari is very fond of lights, and has transfinite powers, so she buys an infinite number of red and blue light bulbs. As a programmer, she also loves patterns, so she arranges her lights by infinitely repeating a given finite pattern S.

For example, if S is BBRB, the infinite sequence Pari builds would be BBRBBBRBBBRB...

Blue is Pari's favorite color, so she wants to know the number of blue bulbs between the Ith bulb and Jth bulb, inclusive, in the infinite sequence she built (lights are numbered with consecutive integers starting from 1). In the sequence above, the indices would be numbered as follows:

B  B  R  B  B  B  R  B  B  B  R  B...
1  2  3  4  5  6  7  8  9  10 11 12
So, for example, there are 4 blue lights between the 4th and 8th positions, but only 2 between the 10th and 12th.

Since the sequence can be very long, she wrote a program to do the count for her. Can you do the same?

Input

The first line of the input gives the number of test cases, T. T test cases follow.
First line of each test case consists of a string S, denoting the initial finite pattern.
Second line of each test case consists of two space separated integers I and J, defined above.

Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is number of blue bulbs between the Ith bulb and Jth bulb of Pari's infinite sequence, inclusive.

Limits

1 ≤ T ≤ 100.
1 ≤ length of S ≤ 100.
Each character of S is either uppercase B or uppercase R.

Small dataset

1 ≤ I ≤ J ≤ 106.
Large dataset

1 ≤ I ≤ J ≤ 1018.
Sample


Input

Output

3
BBRB
4 8
BBRB
10 12
BR
1 1000000
Case #1: 4
Case #2: 2
Case #3: 500000
Cases #1 and #2 are explained above.

In Case #3, bulbs at odd indices are always blue, and bulbs at even indices are always red, so there are half a million blue bulbs between positions 1 and 106.
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
string s;
ull l, r;
ull totalB;
/*-------------------------------------------------------------------*/
ll cal(ll n) {
	ull ans = (n / s.size()) * totalB;
	ull mod = n % s.size();
	for (int i = 0; i < mod; ++i) if (s[i] == 'B') ++ans;
	return ans;
}
ll solve() {
	totalB = 0;
	for (int i = 0; i < s.size(); ++i) if (s[i] == 'B') ++totalB;
	return cal(r) - cal(l-1);
}
/**************	 THINK SIMPLY ************************/
int main(int agrc, char *argv[]) {
	freopen("..\\Debug\\Input.txt", "r", stdin);
	freopen("..\\Debug\\Output.txt", "w", stdout);
	//std::ios::sync_with_stdio(false);
	/*-------------------------------------------------------------------*/
	cin >> T;
	for (ull id = 1; id <= T; ++id) {
		cin >> s >> l >> r;
		//Clear parameter here

		cout << "Case #" << id << ": " << solve() << endl;
	}
	return 0;
}
