
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
#include <complex>
#endif
using namespace std;

#define int long long
#define ll long long
#define ull unsigned long long

#define MIN LLONG_MIN
#define MAX LLONG_MAX
const int inf = 1e9 + 7;
const double EPS = 1e-9;
#define sq(x) ((x) * (x))
#define PI (2 * acos((double)0))

typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define pb push_back
#define sz(a) (int)(a).size()
#define ssz(a,start) (int)(strlen(a+start) + 1)
#define bg(a) (a).begin()
#define en(a) (a).end()
#define all(a) (a).begin(), (a).end()
#define ra(A, start, end) (A)+start, (A)+end
#define rv(A, start, end) (A).begin()+start, (A).begin()+end
#define ms(a,x) memset(a, x, sizeof(a)) //Care: Only init with 0,-1, char[] and bool(true,false)

#define REP(a) for(int iii=0, _a=(a); iii < _a; ++iii)
#define FOR(iii,start,end) for(int iii=(start), _end=(end); iii < _end; ++iii)               // [start, end)
#define FORD(iii,start,end) for(int iii=(start), _end=(end); iii > _end; --iii)              // [start, end)
#define for_it(A) for(auto it = (A.begin()), _end(A.end()); it != _end; ++it)

inline bool DEC(int iii_,int jjj_) { return (iii_<jjj_); }
inline double safe_sqrt(double x) { return sqrt(max((double)0.0, x)); }
inline const bool areSame(double a, double b) {return fabs(a - b) < EPS;}   
inline int d2i(double x) {return x >= 0 ? x + EPS : x - EPS;}
inline double sfloor(double x) {return x >= 0 ? floor(x + EPS) : floor(x - EPS);}
inline double sceil(double x) {return x >= 0 ? ceil(x - EPS) : ceil(x + EPS);};

#define bitcount __builtin_popcountll
#define checkbit(n,b) ( (n >> b) & 1)

#define si(nnn) scanf("%lld",&nnn)
#define sii(nnn,mmm) scanf("%lld %lld",&nnn, &mmm)
#define sd(ddd) scanf("%lf", &ddd)
#define sc(ccc) scanf("%c", &ccc)
#define ss(sss,iii) scanf("%s",sss+iii)

#ifdef DEBUG
#define quit exit(0);
#define nl cerr<<endl;
template<typename T,typename TT> inline ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
#define pr(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); cerr << endl;}
vector<string> split(const string& s, char c) {vector<string> v;stringstream ssss_(s);string x;while(getline(ssss_, x, c)) {v.emplace_back(x);}return move(v);}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) {cerr << it -> substr((*it)[0] == ' ', it->length()) << " = " << a << ", ";err(++it, args...);}
#define pra(A, start, end) { cerr << #A << '[' << start << ',' << (end - 1) << "] = ";FOR(_,start, end) cerr << A[_] << ' '; cerr << endl; }
#define pra_(A, start, end) { cerr << #A << '[' << start << ',' << (end - 1) << "] = ";FOR(_,start, end) cerr << A[_] << ' '; cerr << " ; "; }
#define prai(A, start, end) { cerr << #A << '[' << start << ',' << (end - 1) << "] = ";FOR(_,start, end) cerr << '[' << _ << ']' << A[_] << ' '; cerr << endl; }
#define prai_(A, start, end) { cerr << #A << '[' << start << ',' << (end - 1) << "] = ";FOR(_,start, end) cerr << '[' << _ << ']' << A[_] << ' '; cerr << " ; "; }
#define prit(A) {cerr << #A << " = ";for_it(A) {cerr << *it << ' ';}cerr << endl;}
#define praa(A, start1, end1, start2, end2) {FOR(_,start1, end1) {FOR(__,start2, end2) cerr << '[' << _ << "]["  << __ << ']' << A[_][__] << ' '; cerr << endl;} }
template<typename T> void prav(const vector<T> *a, int start, int end) {FOR(_,start,end) {FOR(__,0,sz(a[_])) {cerr << '[' << _ << "][" << __ << ']' << a[_][__] << "  ";} cerr << endl;}}
template<typename T> void prvv(const vector<vector<T>> &a, int start, int end) {FOR(_,start,end) {FOR(__,0,sz(a[_])) {cerr << '[' << _ << "][" << __ << ']' << a[_][__] << "  ";}cerr << endl;}}
template<typename T> void prS(const stack<T> &a) {stack<T> s(a);cerr << "stack =  [top] ";while(!s.empty()) {cerr << s.top() << ' ';s.pop();}cerr << endl;}
template<typename T> void prQ(const queue<T> &a) {queue<T> q(a);cerr << "queue =  [front] ";while(!q.empty()) {cerr << q.front() << ' ';q.pop();}cerr << "[back]" << endl;}
template<typename T> void prPQ(const priority_queue<T> &a) {priority_queue<T> pq(a);cerr << "heap =  [top] ";while(!pq.empty()) {cerr << pq.top() << ' ';pq.pop();}cerr << endl;}
#else
#define quit 
#define nl 
#define pr(args...)
#define pra(A, start, end)
#define pra_(A, start, end)
#define prai(A, start, end)
#define prai_(A, start, end)
#define praa(A, start1, end1, start2, end2)
#define prit(A)
template<typename T> void prav(const vector<T> *a, int start, int end) {}
template<typename T> void prvv(const vector<vector<T>> &a, int start, int end) {}
template<typename T> void prS(const stack<T> &a) {}
template<typename T> void prQ(const queue<T> &a) {}
template<typename T> void prPQ(const priority_queue<T> &a) {}
#endif
/*------------------------------------- FUNCTIONS ---------------------------------------------------------------*/
const int MAXN = 1000 + 3;


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
    readInput();

    //solve
    solve();
    return 0;
}
