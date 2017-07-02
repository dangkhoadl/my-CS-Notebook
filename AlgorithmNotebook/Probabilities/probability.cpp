/*
https://community.topcoder.com/stat?c=problem_statement&pm=2989&rd=5869
Problem Statement

You are a contestant on a TV quiz show. Throughout the game, you and your 2 opponents have accumulated points by answering trivia questions. At the end of the game, the three of you are given one final question. Before you hear the question, each contestant must decide how many points he or she wishes to wager. Each contestant who answers the question correctly will gain a number of points equal to his or her wager, while the others will lose a number of points equal to their respective wagers. The contestant who ends up with the highest score after the final question wins the game.

It has come to the point in the game where you must select your wager. You can bet any amount between zero and your current score, inclusive. Given your current score, the scores of your two opponents, and how much you believe each of your opponents will wager, compute how much you should wager in order to have the highest probability of winning the game. Assume that you and your opponents each independently have a 50% chance of answering the final question correctly.

You will be given the three scores as a int[], scores. The first element is your score, the next element is your first opponent's score, and the last element is your second opponent's score. You will also be given wager1 and wager2, the amount of your first and second opponents' wagers, respectively.

Your goal is to maximize your chance of winning uncontested. As far as you're concerned, ending in a tie is as bad as losing. If there are multiple wagers that give you the same highest probability of winning, return the smallest such wager. If you have no chance of winning, return zero.


Definition

Class:	QuizShow
Method:	wager
Parameters:	int[], int, int
Returns:	int
Method signature:	int wager(int[] scores, int wager1, int wager2)
(be sure your method is public)


Constraints
-	scores will contain exactly 3 elements.
-	Each element of scores will be between 0 and 10000, inclusive.
-	wager1 will be between 0 and scores[1], inclusive.
-	wager2 will be between 0 and scores[2], inclusive.

Examples
0)

{ 100, 100, 100 }
25
75
Returns: 76
If you bet 76, you have a 50% chance of winning. In this case, it doesn't matter if your opponents are right or wrong. If you are right, you win. Otherwise, you lose. If you wager less than 76, your chance of winning drops below 50%, and if you wager more, your chance of winning will not increase. Therefore, the correct answer is 76.
1)

{ 10, 50, 60 }
30
41
Returns: 0
Even if your opponents are both wrong, they will end up with 20 and 19 points. Since you cannot win (even if you wager 10), the correct answer is 0.
2)

{ 10, 50, 60 }
31
41
Returns: 10
This is the same as the previous example, except in this case your opponents will each end up with 19 points if they are both wrong. Now, you have a 12.5% chance of winning if you wager 10.
3)

{ 2, 2, 12 }
0
10
Returns: 1
4)

{ 10000, 10000, 10000 }
9998
9997
Returns: 9999
5)

{ 5824, 4952, 6230 }
364
287
Returns: 694
*/
#define DEBUG
//#define LINUX

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
#endif
using namespace std;

#define ll long long
#define ull unsigned long long
#define for_i(start,end,step) for(int i = start; i < (int)end; i += step) // [start, end)
#define for_j(start,end,step) for(int j = start; j < (int)end; j += step) // [start, end)
#define for_k(start,end,step) for(int k = start; k < (int)end; k += step) // [start, end)

//parameters
int scores[3];
int wager1, wager2;


/*-------------------------------------------------------------------*/
//Idea: There will be 8 cases happen
//S = {
//	(you wrong, wager 1 right, wager 2 wrong),
//	(you right, wager 1 right, wager 2 wrong),
//	(you wrong, wager 1 right, wager 2 right),
//	(you right, wager 1 right, wager 2 right),
//	(you wrong, wager 1 wrong, wager 2 wrong),
//	(you right, wager 1 wrong, wager 2 wrong),
//	(you wrong, wager 1 wrong, wager 2 right),
//	(you right, wager 1 wrong, wager 2 right)
//}
// So Find the wage that return the best result in each case
int wager() {
	int best = 0; 
	int bet = 0;
	int myScore = scores[0];
	int loseOrWin[2] = {-1, 1}; // -1: if lose lost the wage
							  // 1: if win gain the wage

	//Find the best result
	for (int wage = 0; wage <= myScore; ++wage) {
		int odds = 0;
		// 'odds' count number of good results
		for_i(0, sizeof(loseOrWin) / sizeof(int), 1)
			for_j(0, sizeof(loseOrWin) / sizeof(int), 1)
				for_k(0, sizeof(loseOrWin) / sizeof(int), 1)
					if (myScore + loseOrWin[i] * wage > scores[1] + loseOrWin[j] * wager1  &&
						myScore + loseOrWin[i] * wage > scores[2] + loseOrWin[k] * wager2 )
						++odds;
					
		// Update result favor the number of good results
		if (odds > best) { 
			bet = wage;
			best = odds; 
		}
	}
	return bet;
}

ll solve() {
	return wager();
}
/**************	 THINK SIMPLY ************************/
int main(int agrc, char *argv[]) {
#ifdef DEBUG
	freopen("..\\Debug\\Input.txt", "r", stdin);
	freopen("..\\Debug\\Output.txt", "w", stdout);
	//std::ios::sync_with_stdio(false);
#endif
	/*-------------------------------------------------------------------*/
	//InOut
	for_i(0, 3, 1) 
		cin >> scores[i];
	cin >> wager1 >> wager2;
	//Clear parameter

	//solve
	cout << solve() << endl;

	return 0;
}
