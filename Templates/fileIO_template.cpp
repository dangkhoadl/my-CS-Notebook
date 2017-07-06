//#define LINUX
#define DEBUG

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

#ifdef DEBUG
using namespace std;
#define quit exit(0);
#define FOR(iii,start,end) for(int iii=(start), _end=(end); iii < _end; ++iii)  // [start, end)
#define for_it(A) for(auto it = (A.begin()), _end(A.end()); it != _end; ++it)
template<typename T,typename TT> inline ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
#define pr(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); cerr << endl;}
vector<string> split(const string& s, char c) {vector<string> v;stringstream ssss_(s);string x;while(getline(ssss_, x, c)) {v.emplace_back(x);}return move(v);}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) {cerr << it -> substr((*it)[0] == ' ', it->length()) << " = " << a << ", ";err(++it, args...);}
#define pra(A, start, end) { cerr << #A << '[' << start << ',' << (end - 1) << "] = ";FOR(_,start, end) cerr << A[_] << ' '; cerr << endl; }
#define pra_(A, start, end) { cerr << #A << '[' << start << ',' << (end - 1) << "] = ";FOR(_,start, end) cerr << A[_] << ' '; cerr << " ; "; }
#define prai(A, start, end) { cerr << #A << '[' << start << ',' << (end - 1) << "] = ";FOR(_,start, end) cerr << '[' << _ << ']' << A[_] << ' '; cerr << endl; }
#define prai_(A, start, end) { cerr << #A << '[' << start << ',' << (end - 1) << "] = ";FOR(_,start, end) cerr << '[' << _ << ']' << A[_] << ' '; cerr << " ; "; }
#define pra2(A, start1, end1, start2, end2) {FOR(_,start1, end1) {FOR(__,start2, end2) cerr << '[' << _ << "]["  << __ << ']' << A[_][__] << ' '; cerr << endl;} }
#define prit(A) {cerr << #A << " = ";for_it(A) {cerr << *it << ' ';}cerr << endl;}
template<typename T> void prav(const vector<T> *a, int start, int end) {FOR(_,start,end) {FOR(__,0,sz(a[_])) {cerr << '[' << _ << "][" << __ << ']' << a[_][__] << "  ";} cerr << endl;}}
template<typename T> void prvv(const vector<vector<T>> &a, int start, int end) {FOR(_,start,end) {FOR(__,0,sz(a[_])) {cerr << '[' << _ << "][" << __ << ']' << a[_][__] << "  ";}cerr << endl;}}
template<typename T> void prS(const stack<T> &a) {stack<T> s(a);cerr << "stack =  [top] ";while(!s.empty()) {cerr << s.top() << ' ';s.pop();}cerr << endl;}
template<typename T> void prQ(const queue<T> &a) {queue<T> q(a);cerr << "queue =  [front] ";while(!q.empty()) {cerr << q.front() << ' ';q.pop();}cerr << "[back]" << endl;}
template<typename T> void prPQ(const priority_queue<T> &a) {priority_queue<T> pq(a);cerr << "heap =  [top] ";while(!pq.empty()) {cerr << pq.top() << ' ';pq.pop();}cerr << endl;}
#else
#define quit 
#define pr(args...)
#define pra(A, start, end)
#define pra_(A, start, end)
#define prai(A, start, end)
#define prai_(A, start, end)
#define pra2(A, start1, end1, start2, end2)
#define prit(A)
template<typename T> void prav(const vector<T> *a, int start, int end) {}
template<typename T> void prvv(const vector<vector<T>> &a, int start, int end) {}
template<typename T> void prS(const stack<T> &a) {}
template<typename T> void prQ(const queue<T> &a) {}
template<typename T> void prPQ(const priority_queue<T> &a) {}
#endif
/*******************************************************************************************/
int main(int agrc, char *argv[]) {
#ifdef DEBUG
    freopen("cerr.ce", "w", stderr);
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
