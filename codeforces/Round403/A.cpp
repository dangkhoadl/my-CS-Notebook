/*
A. Andryusha and Socks
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Andryusha is an orderly boy and likes to keep things in their place.

Today he faced a problem to put his socks in the wardrobe. He has n distinct pairs of socks which are initially in a bag. The pairs are numbered from 1 to n. Andryusha wants to put paired socks together and put them in the wardrobe. He takes the socks one by one from the bag, and for each sock he looks whether the pair of this sock has been already took out of the bag, or not. If not (that means the pair of this sock is still in the bag), he puts the current socks on the table in front of him. Otherwise, he puts both socks from the pair to the wardrobe.

Andryusha remembers the order in which he took the socks from the bag. Can you tell him what is the maximum number of socks that were on the table at the same time?

Input
The first line contains the single integer n (1 ≤ n ≤ 105) — the number of sock pairs.

The second line contains 2n integers x1, x2, ..., x2n (1 ≤ xi ≤ n), which describe the order in which Andryusha took the socks from the bag. More precisely, xi means that the i-th sock Andryusha took out was from pair xi.

It is guaranteed that Andryusha took exactly two socks of each pair.

Output
Print single integer — the maximum number of socks that were on the table at the same time.

Examples
input
1
1 1
output
1
input
3
2 1 1 3 2 3
output
2
Note
In the first example Andryusha took a sock from the first pair and put it on the table. Then he took the next sock which is from the first pair as well, so he immediately puts both socks to the wardrobe. Thus, at most one sock was on the table at the same time.

In the second example Andryusha behaved as follows:

Initially the table was empty, he took out a sock from pair 2 and put it on the table.
Sock (2) was on the table. Andryusha took out a sock from pair 1 and put it on the table.
Socks (1, 2) were on the table. Andryusha took out a sock from pair 1, and put this pair into the wardrobe.
Sock (2) was on the table. Andryusha took out a sock from pair 3 and put it on the table.
Socks (2, 3) were on the table. Andryusha took out a sock from pair 2, and put this pair into the wardrobe.
Sock (3) was on the table. Andryusha took out a sock from pair 3 and put this pair into the wardrobe.
Thus, at most two socks were on the table at the same time.
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
ull arr[200002];
/*-------------------------------------------------------------------*/
ll solve() {
	set<ull> hash;
	ull maxH = 0;
	for_i(0, 2 * N, 1) {
		if (hash.find(arr[i]) == hash.end()) {
			hash.insert(arr[i]);
			maxH = max((ull)hash.size(), maxH);
		}
		else {
			hash.erase(arr[i]);
		}
	}
	return maxH;
}
/**************	 THINK SIMPLY ************************/
int main(int agrc, char *argv[]) {
#ifdef DEBUG
	freopen("..\\Debug\\Input.txt", "r", stdin);
	freopen("..\\Debug\\Output.txt", "w", stdout);
	//std::ios::sync_with_stdio(false);
#endif
	/*-------------------------------------------------------------------*/
	//InOut
	cin >> N;
	for_i(0, 2 * N, 1)
		cin >> arr[i];
	//Clear parameter

	//solve
	cout << solve() << endl;

	return 0;
}
