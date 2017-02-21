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
/*
A student signed up for n workshops and wants to attend the maximum number of workshops
	where no two workshops overlap. You must do the following:

Implement 2 structures:

1. struct Workshop having the following members:
	The workshop's start time.
	The workshop's duration.
	The workshop's end time.

2. struct Available_Workshops having the following members:
	An integer, n (the number of workshops the student signed up for).
	An array of type Workshop array having size n.

Implement 2 functions:

1. Available_Workshops* initialize (int start_time[], int duration[], int n)
	Creates an Available_Workshops object and initializes its elements
	using the elements in the start_time[] and duration[] parameters (both are of size n).
	Here, start_time[i] and duration[i] are the respective start time and duration for the i-th workshop. 
	This function must return a pointer to an Available_Workshops object.

2. int CalculateMaxWorkshops(Available_Workshops* ptr)
	Returns the maximum number of workshops the student can attend—without overlap.
	The next workshop cannot be attended until the previous workshop ends.

Sample Input
	6
	1 3 0 5 5 8
	1 1 6 2 4 1
Output
	CalculateMaxWorkshops should return 4
*/
/*______________________________________________________________________________*/
struct Workshop {
	int starttime;
	int duration;
	int endtime;
};

struct Available_Workshops {
	int n;
	vector<Workshop> *arr = new vector<Workshop>(n);
};

Available_Workshops* initialize(int start_time[], int duration[], int n) {
	Available_Workshops *aw = new struct Available_Workshops();
	aw->n = n;
	for(int i=0; i < n; ++i) {
		Workshop *ws = new Workshop;
		ws->starttime = start_time[i];
		ws->duration = duration[i];
		ws->endtime = start_time[i] + duration[i];
		aw->arr->push_back(*ws);
	}
	return aw;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
	sort(ptr->arr->begin(), ptr->arr->end(), 
		[](Workshop& ws1, Workshop& ws2) {
			return ws1.endtime < ws2.endtime;
	}); // use lambda function here
	vector<Workshop> *result = new vector<Workshop>();
	int total_end_time = 0;
	for (vector<Workshop>::iterator it = ptr->arr->begin(); it != ptr->arr->end(); ++it) {
		if (it->starttime >= total_end_time) {
			result->push_back(*it);
			total_end_time = it->endtime;
		}
	}
	return result->size();
}

/*______________________________________________________________________________*/
int main() {
	fcin.open("Input.txt");
/*______________________________________________________________________________*/
	int n; // number of workshops
	fcin >> n;
	// create arrays of unknown size n
	int* start_time = new int[n];
	int* duration = new int[n];

	for (int i = 0; i < n; i++) {
		fcin >> start_time[i];
	}
	for (int i = 0; i < n; i++) {
		fcin >> duration[i];
	}

	Available_Workshops * ptr;
	ptr = initialize(start_time, duration, n);
	cout << CalculateMaxWorkshops(ptr) << endl;
/*______________________________________________________________________________*/
	fcin.close();
	cout << endl << endl;
	system("pause");
	return 0;
}
