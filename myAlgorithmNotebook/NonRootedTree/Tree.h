// Vertex start from 1 
// E = V - 1
//
// V
// Edges
// Values
//
// Ex:
// 7					 V
// 6 2					(6)---------(2)
// 5 2					(5)---------(2)
// 1 2					(1)---------(2)
// 1 3					(1)---------(3)
// 1 4					(1)---------(4)
// 4 7					(4)---------(7)
// 1 2 3 4 5 6 7		value[1,V]


const int MAXV = 21;

int V;
vector<int> e[MAXV];
int val[MAXV];
void readInput() {
	cin >> V;
	for (int i = 1; i <= V-1; ++i) {
		int v, u;
		cin >> v >> u;
		e[v].push_back(u), e[u].push_back(v);
	}
	for (int i = 1; i <= V-1; ++i) 
		cin >> val[i];
}
