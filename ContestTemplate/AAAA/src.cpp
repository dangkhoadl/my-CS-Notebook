//#define DEBUG
#define LINUX

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
ll n,k;
ll A[200000];
ll B[200000];

struct node {
	ll x;
	ull index;
} C[200000];

/*-------------------------------------------------------------------*/
ll solve() {
	ull ans = 0;
	sort(C, C + n, [](node a, node b) {return a.x < b.x; });

	for_i(0, k, 1)
		ans += A[C[i].index];

	ull pos = n;
	for_i(k, n, 1) {
		if (C[i].x > 0) {
			pos = i;
			break;
		}
		ans += A[C[i].index];
	}

	for_i(pos, n, 1)
		ans += B[C[i].index];

	return ans;
}

/**************	 THINK SIMPLY ************************/
int main(int agrc, char *argv[]) {
#ifdef DEBUG
	freopen("..\\Debug\\Input.txt", "r", stdin);
	freopen("..\\Debug\\Output.txt", "w", stdout);
	//std::ios::sync_with_stdio(false);
#endif
	/*-------------------------------------------------------------------*/
	cin >> n >> k;
	for_i(0, n, 1)
		cin >> A[i];
	for_i(0, n, 1)
		cin >> B[i], C[i].x = A[i] - B[i], C[i].index = i;
	//Clear parameter here
	cout << solve() << endl;

	return 0;
}