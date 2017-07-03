//#define LINUX
#define DEBUG

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
#include <complex>
#endif
using namespace std;

#ifdef DEBUG
#ifdef DEBUG
#define pr(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); cerr << endl;}
vector<string> split(const string& s, char c) {
    vector<string> v;
    stringstream ss(s);
    string x;
    while (getline(ss, x, c))
        v.emplace_back(x);
    return move(v);
}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
    cerr << it -> substr((*it)[0] == ' ', it->length()) << " = " << a << ", ";
    err(++it, args...);
}
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
#else
#define pr(args...)
#define pra(A, start, end)
#define pra_(A, start, end)
#define prai(A, start, end)
#define prai_(A, start, end)
#define pra2(A, start1, end1, start2, end2)
void pravi(const vector<int> *a, int start, int end) {}
void prvvi(const vector<vector<int>> &a, int start, int end) {}
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

#define ra(A, start, end) (A)+start, (A)+end
#define rvi(A, start, end) (A).begin()+start, (A).begin()+end
inline bool DEC(int iii_,int jjj_) { return (iii_<jjj_); }
/*******************************************************************************************/


int main(int agrc, char *argv[]) {
#ifdef DEBUG
	freopen("..\\Debug\\Cerr.txt", "w", stderr);
	cerr << fixed << setprecision(6);
#endif

	if (agrc == 3) {
		//Input
		const char *inputFileName(argv[1]);
		FILE *fileIn;
		fileIn = fopen(inputFileName, "r");

		if (!fileIn) {
			printf("File does not exist !!!\n");
			return 0;
		}

		//Read

		fclose(fileIn);

		//Process


		//Output
		const std::string outputFileName(argv[2]);
		std::ofstream fileOut;
		fileOut.open(outputFileName);

		//Write

		fileOut.close();
	}
	else {
		const char* inputProgram(argv[0]);
		printf("Plz rerun the %s program\n", inputProgram);
	}

	return 0;
}
