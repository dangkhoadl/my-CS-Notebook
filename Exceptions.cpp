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
Your friend set up a small computational server that performs complex calculations.
It has a function that takes 2 large numbers as its input and returns a numeric result. 
Unfortunately, there are various exceptions that may occur during execution.

Complete the code in your editor so that it prints appropriate error messages, should anything go wrong. The expected behavior is defined as follows:
	If the compute function runs fine with the given arguments, then print the result of the function call.
	If it fails to allocate the memory that it needs, print "Not enough memory."
	If any other standard C++ exception occurs, print Exception: S where S is the exception's error message.
	If any non-standard exception occurs, print "Other Exception."

Input Format
	The first line contains an integer, , the number of test cases.
	Each of the  subsequent lines describes a test case as  space-separated integers,  and , respectively.

Sample Input
	2
	-8 5
	1435434255433 5

Sample Output
	Exception: A is negative
	Not enough memory
	2
*/
/*______________________________________________________________________________*/
class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if (A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if (B == 0) 
			throw 0;
		real = (A / B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;


/*______________________________________________________________________________*/
int main() {
	fcin.open("Input.txt");
/*______________________________________________________________________________*/
	int T; fcin >> T;
	while (T--) {
		long long A, B;
		fcin >> A >> B;

		try {
			cout << Server::compute(A, B) << endl;
		}
		catch (bad_alloc& ba) {
			cout << "Not enough memory" << endl;
		}
		catch (exception& e) {
			cout << "Exception: " << e.what() << endl;
		}
		catch (...) {
			cout << "Other Exception" << endl;
		}
	}
	cout << Server::getLoad() << endl;

/*______________________________________________________________________________*/
	fcin.close();
	cout << endl << endl;
	system("pause");
	return 0;
}
