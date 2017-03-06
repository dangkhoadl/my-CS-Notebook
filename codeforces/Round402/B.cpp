/*
B. Weird Rounding
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp is crazy about round numbers. He especially likes the numbers divisible by 10k.

In the given number of n Polycarp wants to remove the least number of digits to get a number that is divisible by 10k. For example, if k = 3, in the number 30020 it is enough to delete a single digit (2). In this case, the result is 3000 that is divisible by 103 = 1000.

Write a program that prints the minimum number of digits to be deleted from the given integer number n, so that the result is divisible by 10k. The result should not start with the unnecessary leading zero (i.e., zero can start only the number 0, which is required to be written as exactly one digit).

It is guaranteed that the answer exists.

Input
The only line of the input contains two integer numbers n and k (0 ≤ n ≤ 2 000 000 000, 1 ≤ k ≤ 9).

It is guaranteed that the answer exists. All numbers in the input are written in traditional notation of integers, that is, without any extra leading zeros.

Output
Print w — the required minimal number of digits to erase. After removing the appropriate w digits from the number n, the result should have a value that is divisible by 10k. The result can start with digit 0 in the single case (the result is zero and written by exactly the only digit 0).

Examples
input
30020 3
output
1
input
100 9
output
2
input
10203049 2
output
3
Note
In the example 2 you can remove two digits: 1 and any 0. The result is number 0 which is divisible by any number.
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
#include <ctime>
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
#define for_id(start,end,step) for(int i = start; i > (int)end; i += step) // [start, end)
#define for_j(start,end,step) for(int j = start; j < (int)end; j += step) // [start, end)
#define for_jd(start,end,step) for(int j = start; j > (int)end; j += step) // [start, end)

//parameters
char s[111];
ull N;
ull k;
/*-------------------------------------------------------------------*/
ll solve() {
	ull cnt = 0;
	ull zeros = 0;
	for_id(N, 0, -1) {
		if (s[i] == '0')
			++zeros;
		else
			++cnt;
		if (zeros == k)
			return cnt;
	}
	return N - 1;
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
	scanf("%s", s + 1);
	N = strlen(s + 1);
	cin >> k;
	//Clear parameter

	//solve
	cout << solve() << endl;

	return 0;
}
