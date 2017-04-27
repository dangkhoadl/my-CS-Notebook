/*
Problem

The Constitution of a certain country states that the leader is the person with the name containing the greatest number of different alphabet letters. (The country uses the uppercase English alphabet from A through Z.) For example, the name GOOGLE has four different alphabet letters: E, G, L, and O. The name APAC CODE JAM has eight different letters. If the country only consists of these 2 persons, APAC CODE JAM would be the leader.

If there is a tie, the person whose name comes earliest in alphabetical order is the leader.

Given a list of names of the citizens of the country, can you determine who the leader is?
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a line with an interger N, the number of people in the country. Then N lines follow. The i-th line represents the name of the i-th person. Each name contains at most 20 characters and contains at least one alphabet letter.

Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the name of the leader.
Limits

1 ≤ T ≤ 100.
1 ≤ N ≤ 100.
Small dataset

Each name consists of at most 20 characters and only consists of the uppercase English letters A through Z.

Large dataset

Each name consists of at most 20 characters and only consists of the uppercase English letters A through Z and ' '(space).
All names start and end with alphabet letters.
Sample


Input

Output

2
3
ADAM
BOB
JOHNSON
2
A AB C
DEF

Case #1: JOHNSON
Case #2: A AB C


In sample case #1, JOHNSON contains 5 different alphabet letters('H', 'J', 'N', 'O', 'S'), so he is the leader.

Sample case #2 would only appear in Large data set. The name DEF contains 3 different alphabet letters, the name A AB C also contains 3 different alphabet letters. A AB C comes alphabetically earlier so he is the leader.
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
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
using namespace std;

#define ll long long
#define ull unsigned long long

//parameters
ull T;
ull N;
/*-------------------------------------------------------------------*/

vector<string> v;
vector<set<char>> result;
vector<pair<int, string> > L;

string solve() {
	while (N--) {
		string temp = "asas";
		getline(cin, temp);
		v.push_back(temp);
	}

	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j) if ('A' <= v[i][j] && v[i][j] <= 'Z') if (result[i].find(v[i][j]) == result[i].end()) {
			result[i].insert(v[i][j]);
		}
		L.push_back({ -int(result[i].size()), v[i] });
	}
	sort(L.begin(), L.end());

	return L[0].second;
}

int main(int agrc, char *argv[]) {
	freopen("..\\Debug\\Input.txt", "r", stdin);
	freopen("..\\Debug\\Output.txt", "w", stdout);
	//std::ios::sync_with_stdio(false);
	/*-------------------------------------------------------------------*/
	cin >> T;
	for (ull id = 1; id <= T; ++id) {
		cin >> N;
		//Clear parameter here
		L.clear();
		result.clear();
		result.resize(N);
		v.clear();
		cin.ignore();
		cout << "Case #" << id << ": " << solve() << endl;
	}
	return 0;
}
