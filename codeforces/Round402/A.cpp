/*
A. Pupils Redistribution
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
In Berland each high school student is characterized by academic performance — integer value between 1 and 5.

In high school 0xFF there are two groups of pupils: the group A and the group B. Each group consists of exactly n students. An academic performance of each student is known — integer value between 1 and 5.

The school director wants to redistribute students between groups so that each of the two groups has the same number of students whose academic performance is equal to 1, the same number of students whose academic performance is 2 and so on. In other words, the purpose of the school director is to change the composition of groups, so that for each value of academic performance the numbers of students in both groups are equal.

To achieve this, there is a plan to produce a series of exchanges of students between groups. During the single exchange the director selects one student from the class A and one student of class B. After that, they both change their groups.

Print the least number of exchanges, in order to achieve the desired equal numbers of students for each academic performance.

Input
The first line of the input contains integer number n (1 ≤ n ≤ 100) — number of students in both groups.

The second line contains sequence of integer numbers a1, a2, ..., an (1 ≤ ai ≤ 5), where ai is academic performance of the i-th student of the group A.

The third line contains sequence of integer numbers b1, b2, ..., bn (1 ≤ bi ≤ 5), where bi is academic performance of the i-th student of the group B.

Output
Print the required minimum number of exchanges or -1, if the desired distribution of students can not be obtained.

Examples
input
4
5 4 4 4
5 5 4 5
output
1
input
6
1 1 1 1 1 1
5 5 5 5 5 5
output
3
input
1
5
3
output
-1
input
9
3 2 5 5 2 3 3 3 2
4 1 4 1 1 2 4 4 1
output
4
*/

#define DEBUG
//#define LINUX

#ifdef LINUX
#include <bits/stdc++.h>
#endif

#ifndef LINUX
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
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
#endif
using namespace std;

#define ll long long
#define ull unsigned long long
#define for_i(start,end,step) for(int i = start; i < (int)end; i += step) // [start, end)
#define for_j(start,end,step) for(int j = start; j < (int)end; j += step) // [start, end)

//parameters
ull N;
ull A[100];
ull B[100];
/*-------------------------------------------------------------------*/
ll solve() {
	ll cnt[6];
	memset(cnt, 0, 6 * sizeof(ull));

	for_i(0, N, 1)
		++cnt[A[i]];
	for_i(0, N, 1)
		--cnt[B[i]];
	
	for_i(1, 6, 1) {
		cnt[i] = abs(cnt[i]);
		if (cnt[i] % 2 == 1)
			return -1;
	}
	return accumulate(cnt + 1, cnt + 6, 0) / 4;
}
/**************	 THINK SIMPLY ************************/
int main(int agrc, char *argv[]) {
#ifdef DEBUG
	freopen("..\\Debug\\Input.txt", "r", stdin);
	freopen("..\\Debug\\Output.txt", "w", stdout);
	freopen("..\\Debug\\Cerr.txt", "w", stderr);
	//std::ios::sync_with_stdio(false);
#endif
	/*-------------------------------------------------------------------*/
	//InOut
	cin >> N;
	for_i(0, N, 1)
		cin >> A[i];
	for_i(0, N, 1)
		cin >> B[i];
	//Clear parameter

	//solve
	cout << solve() << endl;

	return 0;
}
