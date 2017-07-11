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

/*******************************************************************************************/
int main(int agrc, char *argv[]) {
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
