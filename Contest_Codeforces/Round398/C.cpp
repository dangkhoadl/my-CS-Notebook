// http://codeforces.com/contest/767/problem/C
/*------------------------------------- CONFIG ---------------------------------------------------------------*/
#define DEBUG
//#define LINUX

/*------------------------------------- TEMPLATE ---------------------------------------------------------------*/
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

#define int long long
#define double long double
#define ll long long
#define ull unsigned long long

#define for_i(start,end,step) for(int i = start; i < (int)end; i += step) // [start, end)
#define for_id(start,end,step) for(int i = start; i > (int)end; i += step) // [start, end)
#define for_j(start,end,step) for(int j = start; j < (int)end; j += step) // [start, end)
#define for_jd(start,end,step) for(int j = start; j > (int)end; j += step) // [start, end)
#define for_(start,end,step) for(int _ = start; _ < (int)end; _ += step) // [start, end)

#ifdef DEBUG
#define pr(X) { cerr << #X << " = " << (X) << endl; }
#define pr_(X) { cerr << #X << " = " << (X) << " ; "; }
#define pra(A, start, end) { cerr << #A << '[' << start << ',' << (end - 1) << "] = "; for_(start, end, 1) cerr << A[_] << ' '; cerr << endl; }
#define pra_(A, start, end) { cerr << #A << '[' << start << ',' << (end - 1) << "] = "; for_(start, end, 1) cerr << A[_] << ' '; cerr << " ; "; }
#endif 

const int inf = 1e9 + 7;
#define sqr(x) ((x) * (x))
#define PI (2 * acos((double)0))
double safe_sqrt(double x) { return sqrt(max((double)0.0, x)); }

typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a)) //Care: Only init with 0,-1 and char[]
/*----------------------------------- PARAMETERS -----------------------------------------------------------------*/
const int MAXN = 1e6 + 1;
ll n;
ll par[MAXN];
ll t[MAXN];

int root;
vi child[MAXN];

ll sum;
ll ans1, ans2;

/*------------------------------------- FUNCTIONS ---------------------------------------------------------------*/
void dfs(int x, int cutVal) {
	for_i(0, sz(child[x]), 1) {
		dfs(child[x][i], cutVal);
		t[x] += t[child[x][i]];
	}

	if (t[x] == cutVal && x != root) {
		if (ans1 == -1) {
			ans1 = x;
			t[x] = 0;
		}
		else if (ans2 == -1) {
			ans2 = x;
			t[x] = 0;
		}
	}
}


bool solve() {
	if (sum % 3 != 0)
		return false;
	
	dfs(root, sum / 3);
	if (ans1 != -1 && ans2 != -1)
		return true;

	return false;
}
/*------------------------------------- MAIN ---------------------------------------------------------------*/
int32_t main(int agrc, char *argv[]) {
#ifdef DEBUG
	freopen("..\\Debug\\Input.txt", "r", stdin);
	freopen("..\\Debug\\Output.txt", "w", stdout);
	freopen("..\\Debug\\Cerr.txt", "w", stderr);
	cerr << fixed << setprecision(6);
#endif
	ios::sync_with_stdio(false);
	cin.tie(false);
	cout << fixed << setprecision(11);
	/*----------------------------------------------------------------------------------------------------*/
	//InOut
	cin >> n;
	for_i(1, n + 1, 1) {
		cin >> par[i] >> t[i];
		sum += t[i];
		if (par[i] == 0)
			root = i;
		else 
			child[par[i]].pb(i);
	}

	//Clear parameter
	ans1 = -1;
	ans2 = -1;

	//solve
	if (solve())
		cout << ans1 << ' ' << ans2 << endl;
	else
		cout << -1 << endl;
	return 0;
}