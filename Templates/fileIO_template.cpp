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
#define for_(start,end,step) for(int _ = start; _ < (int)end; _ += step) // [start, end)
#define for__(start,end,step) for(int __ = start; __ < (int)end; __ += step) // [start, end)
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
