#define DEBUG

#ifdef DEBUG
#include <bits/stdc++.h>
#define sz(a) (int)(a).size()
#define REP(a) for(int iii=0, _a=(a); iii < _a; ++iii)
#define FOR(iii,start,end) for(int iii=(start), _end=(end); iii < _end; ++iii)               // [start, end)
#define FORD(iii,start,end) for(int iii=(start), _end=(end); iii > _end; --iii)              // [start, end)
#define for_it(A) for(auto it = (A.begin()), _end(A.end()); it != _end; ++it)
#define quit exit(0);
#define nl cerr<<endl;
template<typename T,typename TT> inline ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
#define pr(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); cerr << endl;}
vector<string> split(const string& s, char c) {vector<string> v;stringstream ssss_(s);string x;while(getline(ssss_, x, c)) {v.emplace_back(x);}return move(v);}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) {cerr << it -> substr((*it)[0] == ' ', it->length()) << " = " << a << ", ";err(++it, args...);}
#define pra(A, start, end) {cerr << #A << '[' << start << ',' << (end - 1) << "] = ";FOR(_,start, end) cerr << A[_] << ' '; cerr << endl; }
#define prai(A, start, end) { cerr << #A << '[' << start << ',' << (end - 1) << "] = ";FOR(_,start, end) cerr << '[' << _ << ']' << A[_] << ' '; cerr << endl; }
#define prit(A) {cerr << #A << " = ";for_it(A) {cerr << *it << ' ';}cerr << endl;}
#define praa(A, start1, end1, start2, end2) {FOR(_,start1, end1) {FOR(__,start2, end2) {ostringstream ss;ss << A[_][__];cerr << setw(10) << left << ss.str();}cerr << endl;}}
#define praai(A, start1, end1, start2, end2) {FOR(_,start1, end1) {FOR(__,start2, end2) {ostringstream ss;ss << '[' << _ << "]["  << __ << "]" << A[_][__];cerr << setw(17) << left << ss.str();}cerr << endl;}}
template<typename T> void prav(const vector<T> *a, int start, int end) {FOR(_,start,end) {FOR(__,0,sz(a[_])) {ostringstream ss;ss << a[_][__];cerr << setw(10) << left << ss.str();} cerr << endl;}}
template<typename T> void pravi(const vector<T> *a, int start, int end) {FOR(_,start,end) {FOR(__,0,sz(a[_])) {ostringstream ss;ss << '[' << _ << "][" << __ << ']' << a[_][__];cerr << setw(17) << left << ss.str();} cerr << endl;}}
template<typename T> void prvv(const vector<vector<T>> &a, int start, int end) {FOR(_,start,end) {FOR(__,0,sz(a[_])) {ostringstream ss;ss << a[_][__];cerr << setw(10) << left << ss.str();}cerr << endl;}}
template<typename T> void prvvi(const vector<vector<T>> &a, int start, int end) {FOR(_,start,end) {FOR(__,0,sz(a[_])) {ostringstream ss;ss << '[' << _ << "][" << __ << ']' << a[_][__];cerr << setw(17) << left << ss.str();}cerr << endl;}}
template<typename T> void prS(const stack<T> &a) {stack<T> s(a);cerr << "stack =  [top] ";while(!s.empty()) {cerr << s.top() << ' ';s.pop();}cerr << endl;}
template<typename T> void prQ(const queue<T> &a) {queue<T> q(a);cerr << "queue =  [front] ";while(!q.empty()) {cerr << q.front() << ' ';q.pop();}cerr << "[back]" << endl;}
template<typename T> void prPQ(const priority_queue<T> &a) {priority_queue<T> pq(a);cerr << "heap =  [top] ";while(!pq.empty()) {cerr << pq.top() << ' ';pq.pop();}cerr << endl;}
#else
#define quit 
#define nl 
#define pr(args...)
#define pra(A, start, end)
#define prai(A, start, end)
#define praa(A, start1, end1, start2, end2)
#define praai(A, start1, end1, start2, end2)
#define prit(A)
template<typename T> void prav(const vector<T> *a, int start, int end) {}
template<typename T> void pravi(const vector<T> *a, int start, int end) {}
template<typename T> void prvv(const vector<vector<T>> &a, int start, int end) {}
template<typename T> void prvvi(const vector<vector<T>> &a, int start, int end) {}
template<typename T> void prS(const stack<T> &a) {}
template<typename T> void prQ(const queue<T> &a) {}
template<typename T> void prPQ(const priority_queue<T> &a) {}
#endif

int main(int agrc, char *argv[]) {
#ifdef DEBUG
	freopen("input.in", "r", stdin);
    freopen("cerr.ce", "w", stderr);
    freopen("output.out", "w", stdout);
#endif
    
     
    return 0;
}