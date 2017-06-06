// Character Recognition
// Description

// Character recognition is the conversion of images into text. For now we consider each character in the picture is a N*M matrix with only zeros and ones, and we need to recognize K characters. You are to write a program to find minimal number of pixels so that we can recognize each character.

// For example, we have only two characters 'T' and 'L', and the matrix size is 3*3, we can think 'T' and 'L' are

// 111    100
// 010    100
// 010    111
// so we can recognize the character with only bottom-left pixel, the answer is 1.

// Limits

// Memory limit per test: 256 megabytes
// Time limit per test: The faster the better
// Compile & Environment

// C++

// g++ Main.cc -o Main -fno-asm -Wall -lm --static -std=c++0x -DONLINE_JUDGE
// Java

// J2SE 8

// Maximum stack size is 50m

// Input

// The first line of input is three integers N, M, K (1 <= N, M <= 10, 2 <= K <= 6). Which represents the size of matrix and number of characters. Then is following K blocks, which represents the matrix. Notice that each block starts with a blank line and we guarantee that characters are different.

// Output

// You should output the minimum number of pixels, which is the answer.

// Sample Test
// input
// 2 3 2

// 111
// 010

// 100
// 100
// output
// 1


#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

const int inf = 1e9 + 7;

int n,m,k;
vector<vector<string>> dataSet;
void readInput() {
    cin >> n >> m >> k;
    dataSet.resize(k);
    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < n; ++j) {
            string tmp;
            cin >> tmp;
            dataSet[i].push_back(tmp);
        }
    }
}

map<pair<int,int>, int> M;
int solve() {
    for(int i = 0; i < k - 1; ++i)
        for(int j = i + 1; j < k; ++j) 
            for(int x = 0; x < n; ++x)
                for(int y = 0; y < m; ++y)
                    if(dataSet[i][x][y] != dataSet[j][x][y]) {
                        auto it = M.find({x,y});
                        if(it == M.end())
                            M.insert({{x,y},1});
                        else
                            ++it->second;
                    }

    int min = inf;
    for(auto it = M.begin(); it != M.end(); ++it) {
        if(min > it->second)
            min = it->second;
    }

    return min;
}

int main() {
    readInput();
    cout <<  solve() << endl;

    return 0;
}
