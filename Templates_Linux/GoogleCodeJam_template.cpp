
/*------------------------------------- CONFIG ---------------------------------------------------------------*/
#define DEBUG
//#define LINUX

/*------------------------------------- TEMPLATE ---------------------------------------------------------------*/
#ifdef LINUX
#include <bits/stdc++.h>
#endif

#ifndef LINUX
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
#include <complex>
#endif
using namespace std;

#define int long long
#define double long double
#define ll long long
#define ull unsigned long long
#define __builtin_popcount __builtin_popcountll

#define REP(a) for(int iii=0,_a=(a); iii < _a; ++iii)
#define FOR(iii,start,end,step) for(int iii=(start), _end=(end); iii < _end; iii += step) 				// [start, end)
#define FORD(iii,start,end,step) for(int iii=(start), _end=(end); iii > _end; iii += step) 				// [start, end)
#define for_i(start,end,step) for(int i = (start), _end(end), _step(step); i < (int)_end; i += _step) 	// [start, end)
#define for_id(start,end,step) for(int i = (start), _end(end), _step(step); i > (int)_end; i += _step) 	// [start, end)
#define for_j(start,end,step) for(int j = (start), _end(end), _step(step); j < (int)_end; j += _step) 	// [start, end)
#define for_jd(start,end,step) for(int j = (start), _end(end), _step(step); j > (int)_end; j += _step) 	// [start, end)
#define for_(start,end,step) for(int _ = (start), _end(end), _step(step); _ < (int)_end; _ += _step) 	// [start, end)
#define for__(start,end,step) for(int __ = (start), _end(end), _step(step); __ < (int)_end; __ += _step)// [start, end)
#define for_it(A) for(auto it = (A.begin()), _end(A.end()); it != _end; ++it)

#ifdef DEBUG
#define pr(X) { cerr << #X << " = " << (X) << endl; }
#define pr_(X) { cerr << #X << " = " << (X) << " ; "; }
#define pra(A, start, end) { cerr << #A << '[' << start << ',' << (end - 1) << "] = "; for_(start, end, 1) cerr << A[_] << ' '; cerr << endl; }
#define pra_(A, start, end) { cerr << #A << '[' << start << ',' << (end - 1) << "] = "; for_(start, end, 1) cerr << A[_] << ' '; cerr << " ; "; }
#define prai(A, start, end) { cerr << #A << '[' << start << ',' << (end - 1) << "] = "; for_(start, end, 1) cerr << '[' << _ << ']' << A[_] << ' '; cerr << endl; }
#define prai_(A, start, end) { cerr << #A << '[' << start << ',' << (end - 1) << "] = "; for_(start, end, 1) cerr << '[' << _ << ']' << A[_] << ' '; cerr << " ; "; }
#define pra2(A, start1, end1, start2, end2) {for_(start1, end1, 1) {for__(start2, end2, 1) cerr << '[' << _ << "]["  << __ << ']' << A[_][__] << ' '; cerr << endl;} }
void pravi(const vector<int> *a, int start, int end) {
	for (int _ = start; _ < end; ++_) {
		for (int __ = 0; __ < a[_].size(); ++__)
			cerr << '[' << _ << "][" << __ << ']' << a[_][__] << "  ";
		cerr << endl;
	}
}
void prvvi(const vector<vector<int>> &a, int start, int end) {
	for (int _ = start; _ < end; ++_) {
		for (int __ = 0; __ < a[_].size(); ++__)
			cerr << '[' << _ << "][" << __ << ']' << a[_][__] << "  ";
		cerr << endl;
	}
}
#endif

const int inf = 1e9 + 7;
#define sq(x) ((x) * (x))
#define PI (2 * acos((double)0))
double safe_sqrt(double x) { return sqrt(max((double)0.0, x)); }

typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define pb push_back
#define sz(a) (int)(a).size()
#define bg(a) (a).begin()
#define en(a) (a).end()
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a)) //Care: Only init with 0,-1, char[] and bool(true,false)
/*----------------------------------- PARAMETERS -----------------------------------------------------------------*/
ull T;
const int MAXN = 1e6 + 1;


void setClearPar() {
	
}
/*------------------------------------- FUNCTIONS ---------------------------------------------------------------*/


ll readInput() {
	
	return 0;
}


ll solve() {
	

	return 0;
}
/*------------------------------------- MAIN ---------------------------------------------------------------*/
int32_t main(int agrc, char *argv[]) {
#ifdef DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	freopen("cerr.ce", "w", stderr);
	cerr << fixed << setprecision(6);
#endif
	ios::sync_with_stdio(false);
	cin.tie(false);
	cout << fixed << setprecision(11);
	/*----------------------------------------------------------------------------------------------------*/
	//InOut
	cin >> T;

	// Solve all cases
	for (ull case_ = 1; case_ <= T; ++case_) {
		//Set/Clear parameters
		setClearPar();

		//InOut
		readInput();

		//Solve
		cout << "Case #" << case_ << ": " << solve() << endl;
	}
	return 0;
}
