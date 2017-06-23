/*
C. Dishonest Sellers
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Igor found out discounts in a shop and decided to buy n items. Discounts at the store will last for a week and Igor knows about each item that its price now is ai, and after a week of discounts its price will be bi.

Not all of sellers are honest, so now some products could be more expensive than after a week of discounts.

Igor decided that buy at least k of items now, but wait with the rest of the week in order to save money as much as possible. Your task is to determine the minimum money that Igor can spend to buy all n items.

Input
In the first line there are two positive integer numbers n and k (1 ≤ n ≤ 2·105, 0 ≤ k ≤ n) — total number of items to buy and minimal number of items Igor wants to by right now.

The second line contains sequence of integers a1, a2, ..., an (1 ≤ ai ≤ 104) — prices of items during discounts (i.e. right now).

The third line contains sequence of integers b1, b2, ..., bn (1 ≤ bi ≤ 104) — prices of items after discounts (i.e. after a week).

Output
Print the minimal amount of money Igor will spend to buy all n items. Remember, he should buy at least k items right now.

Examples
input
3 1
5 4 6
3 1 5
output
10
input
5 3
3 4 7 10 3
4 5 5 12 5
output
25
Note
In the first example Igor should buy item 3 paying 6. But items 1 and 2 he should buy after a week. He will pay 3 and 1 for them. So in total he will pay 6 + 3 + 1 = 10.

In the second example Igor should buy right now items 1, 2, 4 and 5, paying for them 3, 4, 10 and 3, respectively. Item 3 he should buy after a week of discounts, he will pay 5 for it. In total he will spend 3 + 4 + 10 + 3 + 5 = 25.
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
ll n;
ull k;
ull a[200001];
ull b[200001];

struct node{
	ll data;
	ull idx;
} C[200001];
/*-------------------------------------------------------------------*/
ll solve() {
	for_i(0, n, 1)
		C[i].data = a[i] - b[i], C[i].idx = i;
	sort(C, C + n, [](const node &a, const node &b) { return a.data < b.data; });

	ull pay = 0;
	ull pos = 0;
	for_i(0, n, 1) 
		if (C[i].data < 0) {
			pay += a[C[i].idx];
			pos = i + 1;
		}
	
	if (pos < k) 
		for_i(pos, k, 1)
			pay += a[C[i].idx];
	
	
	for_i(max(pos,k), n,1)
		pay += b[C[i].idx];

	return pay;
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
	cin >> n >> k;
	for_i(0, n, 1)
		cin >> a[i];
	for_i(0, n, 1)
		cin >> b[i];
	//Clear parameter

	//solve
	cout << solve() << endl;

	return 0;
}
