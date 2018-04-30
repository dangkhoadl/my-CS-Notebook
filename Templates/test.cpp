

/*------------------------------------- CONFIG ---------------------------------------------------------------*/
#define TEST
#define DEBUG

/*------------------------------------- TEMPLATE ---------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ull unsigned long long

#define MIN LLONG_MIN
#define MAX LLONG_MAX
const long long inf = 9187201950435737471;
const long long ninf = -9114861777597660799;
const double EPS = 1e-9;
#define sq(x) ((x)*(x))
#define PI (2*acos((double)0))

typedef pair<int,int> pii;
typedef vector<pair<int,int>> vii;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
template<typename T> inline bool DEC(T fdfsfv_i,T fdfsfv_j) {return((fdfsfv_i)>(fdfsfv_j));}

#define pb push_back
#define sz(a) (int)(a).size()
#define ssz(a,start) (int)(strlen((a)+start)+1)
#define bg(a) (a).begin()
#define en(a) (a).end()
#define all(a) (a).begin(), (a).end()
#define ra(A,start,end) (A)+(start),(A)+(end)
#define rv(A,start,end) (A).begin()+(start),(A).begin()+(end)
#define ms(a,x) memset((a),(x),sizeof(a)) //Care: Only init with 0,-1,0x7f, char[] and bool(true,false)

#define REP(a) for(int idx=0,_a=(a);idx<_a;++idx)
#define FOR(idx,start,end) for(int (idx)=(start),_end=(end);(idx)<_end;++(idx)) // [start, end)
#define FORD(idx,start,end) for(int (idx)=(start),_end=(end);(idx)>_end;--(idx)) // [start, end)
#define FORIT(itx,A) for(auto (itx)=((A).begin()),_end((A).end());(itx)!=_end;++(itx))

#define bitcount __builtin_popcountll
#define checkbit(n,b) (((n)>>(b))&1)

#define si(m) scanf("%lld",&(m))
#define sii(m,n) scanf("%lld %lld",&(m),&(n))
#define siii(m,n,k) scanf("%lld %lld %lld",&(m),&(n),&(k))
#define sd(ld) scanf("%lf",&(ld))
#define sc(ch) scanf("%c",&(ch))
#define ss(str,idx) scanf("%s",(str)+(idx))

#if defined(DEBUG) && defined(TEST)
#define quit exit(0);
#define nl cerr<<endl;
template<typename T,typename TT> inline ostream& operator<<(ostream &fdfsfv_s,pair<T,TT> fdfsfv_t){return fdfsfv_s<<"("<<fdfsfv_t.first<<","<<fdfsfv_t.second<<")";}
#define pr(args...) {vector<string> fdfsfv_v=split(#args,',');err(fdfsfv_v.begin(),args);cerr<<endl;}
vector<string> split(const string& fdfsfv_str,char fdfsfv_c){vector<string> fdfsfv_vstr;stringstream ssss_(fdfsfv_str);string fdfsfv_x;while(getline(ssss_,fdfsfv_x,(fdfsfv_c))){fdfsfv_vstr.emplace_back(fdfsfv_x);}return move(fdfsfv_vstr);}
void err(vector<string>::iterator fdfsfv_itx) {}
template<typename T,typename... Args> void err(vector<string>::iterator fdfsfv_itx,T fdfsfv_a,Args... args){cerr<<(fdfsfv_itx)->substr((*(fdfsfv_itx))[0]==' ',(fdfsfv_itx)->length())<<" = " <<(fdfsfv_a)<<", ";err(++(fdfsfv_itx),(args)...);}
#define pra(A,start,end) {cerr<<#A<<'['<<(start)<<','<<((end)-1)<<"] = ";FOR(fdfsfv_,(start),(end)){cerr <<(A)[fdfsfv_]<< ' ';}cerr<<endl;}
#define prai(A,start,end) {cerr <<#A<<'['<<(start)<<','<<((end)-1)<<"] = ";FOR(fdfsfv_,(start),(end)){cerr<<'['<<fdfsfv_<<']'<<(A)[fdfsfv_]<<' ';}cerr<<endl;}
#define prit(A) {cerr<<#A<<" = ";FORIT(fdfsfv_it__,(A)){cerr<<(*fdfsfv_it__)<<' ';}cerr << endl;}
#define praa(A,start1,end1,start2,end2) {FOR(fdfsfv_,(start1),(end1)){FOR(fdfsfv__,(start2),(end2)){ostringstream fdfsfv_ssx;fdfsfv_ssx<<(A)[fdfsfv_][fdfsfv__];cerr<<setw(10)<<left<<fdfsfv_ssx.str();}cerr<<endl;}}
#define praai(A,start1,end1,start2,end2) {FOR(fdfsfv_,(start1),(end1)){FOR(fdfsfv__,(start2),(end2)){ostringstream fdfsfv_ssx;fdfsfv_ssx <<'['<<fdfsfv_<<"]["<<fdfsfv__<<"]"<<(A)[fdfsfv_][fdfsfv__];cerr<<setw(17)<<left<<fdfsfv_ssx.str();}cerr<<endl;}}
template<typename T> void prav(const vector<T> *fdfsfv_a,int start,int end) {FOR(fdfsfv_,(start),(end)){FOR(fdfsfv__,0,sz((fdfsfv_a)[fdfsfv_])){ostringstream fdfsfv_ssx;fdfsfv_ssx<<(fdfsfv_a)[fdfsfv_][fdfsfv__];cerr<<setw(10)<<left<<fdfsfv_ssx.str();}cerr<<endl;}}
template<typename T> void pravi(const vector<T> *fdfsfv_a,int start,int end) {FOR(fdfsfv_,(start),(end)){FOR(fdfsfv__,0,sz((fdfsfv_a)[fdfsfv_])){ostringstream fdfsfv_ssx;fdfsfv_ssx<<'['<<fdfsfv_<<"]["<<fdfsfv__<<']'<<(fdfsfv_a)[fdfsfv_][fdfsfv__];cerr<<setw(17)<<left<<fdfsfv_ssx.str();}cerr<<endl;}}
template<typename T> void prvv(const vector<vector<T>> &fdfsfv_a,int start,int end) {FOR(fdfsfv_,(start),(end)){FOR(fdfsfv__,0,sz((fdfsfv_a)[fdfsfv_])){ostringstream fdfsfv_ssx;fdfsfv_ssx<<(fdfsfv_a)[fdfsfv_][fdfsfv__];cerr<<setw(10)<<left <<fdfsfv_ssx.str();}cerr<<endl;}}
template<typename T> void prvvi(const vector<vector<T>> &fdfsfv_a,int start,int end) {FOR(fdfsfv_,(start),(end)){FOR(fdfsfv__,0,sz((fdfsfv_a)[fdfsfv_])){ostringstream fdfsfv_ssx;fdfsfv_ssx<<'['<<fdfsfv_<<"]["<<fdfsfv__ <<']'<<(fdfsfv_a)[fdfsfv_][fdfsfv__];cerr<<setw(17)<<left<<fdfsfv_ssx.str();}cerr<<endl;}}
template<typename T> void prS(const stack<T> &fdfsfv_a) {stack<T> fdfsfv_S(fdfsfv_a);cerr<<"stack =  [top] ";while(!fdfsfv_S.empty()){cerr<<fdfsfv_S.top()<<' ';fdfsfv_S.pop();}cerr<<endl;}
template<typename T> void prQ(const queue<T> &fdfsfv_a) {queue<T> fdfsfv_Q(fdfsfv_a);cerr<<"queue =  [front] ";while(!fdfsfv_Q.empty()){cerr<<fdfsfv_Q.front()<<' ';fdfsfv_Q.pop();}cerr<<"[back]"<<endl;}
template<typename T> void prPQ(const priority_queue<T> &fdfsfv_a) {priority_queue<T> fdfsfv_PQ(fdfsfv_a);cerr << "heap =  [top] ";while(!fdfsfv_PQ.empty()){cerr<<fdfsfv_PQ.top()<<' ';fdfsfv_PQ.pop();}cerr<<endl;}
#else
#define quit 
#define nl 
#define pr(args...)
#define pra(A,start,end)
#define prai(A,start,end)
#define praa(A,start1,end1,start2,end2)
#define praai(A,start1,end1,start2,end2)
#define prit(A)
template<typename T> void prav(const vector<T> *fdfsfv_a,int start,int end) {}
template<typename T> void pravi(const vector<T> *fdfsfv_a,int start,int end) {}
template<typename T> void prvv(const vector<vector<T>> &fdfsfv_a,int start,int end) {}
template<typename T> void prvvi(const vector<vector<T>> &fdfsfv_a,int start,int end) {}
template<typename T> void prS(const stack<T> &fdfsfv_a) {}
template<typename T> void prQ(const queue<T> &fdfsfv_a) {}
template<typename T> void prPQ(const priority_queue<T> &fdfsfv_a) {}
#endif
/*----------------------------------- CODE STARTS HERE ------------------------------------------------------*/
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
