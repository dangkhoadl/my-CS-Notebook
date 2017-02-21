#include <iostream>
#include <fstream>
#include <vector>
#include <list>
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

using namespace std;
ifstream fcin;
/*______________________________________________________________________________*/
/*
You are given a main function which reads the enumeration values for two different types as input, 
then prints out the corresponding enumeration names. 
Write a class template that can provide the names of the enumeration values for both types.
If the enumeration value is not valid, then print "unknown."

Input Format
	The first line contains T, the number of test cases.
	Each of the T subsequent lines contains 2 space-separated integers. 
		The first integer is a color value, C, and the second integer is a fruit value, F.

Output Format
	The locked stub code in your editor prints T lines containing the color name and the fruit name corresponding to the input enumeration index.

Sample Input
	2
	1 0
	3 3

Sample Output
	green apple
	unknown unknown
*/
/*______________________________________________________________________________*/
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

template<>
struct Traits<Color> {
	static string name(int idx) {
		switch (static_cast<Color>(idx)) {
		case Color::red:
			return "red";
			break;
		case Color::green:
			return "green";
			break;
		case Color::orange:
			return "orange";
			break;
		}
		return "unknown";
	}
};

template<>
struct Traits<Fruit> {
	static string name(int idx) {
		switch (static_cast<Fruit>(idx)) {
		case Fruit::apple:
			return "apple";
			break;
		case Fruit::orange:
			return "orange";
			break;
		case Fruit::pear:
			return "pear";
			break;
		}
		return "unknown";
	}
};

/*______________________________________________________________________________*/
int main() {
	fcin.open("Input.txt");
/*______________________________________________________________________________*/
	int t = 0; fcin >> t;

	for (int i = 0; i != t; ++i) {
		int index1; fcin >> index1;
		int index2; fcin >> index2;
		cout << Traits<Color>::name(index1) << " ";
		cout << Traits<Fruit>::name(index2) << "\n";
	}

/*______________________________________________________________________________*/
	fcin.close();
	cout << endl << endl;
	system("pause");
	return 0;
}
