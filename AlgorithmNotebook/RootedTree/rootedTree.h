//MultiTree adjnode presentation
//
//	V
//  NodeID| parent value
//
// root node has parent == 0
//Eg:
//6
//2 4	2 ----> 1(4)						
//0 5			2(5): root
//4 2	4 ----> 3(2)
//2 1	2 ----> 4(1)
//1 1	1 ----> 5(1)
//4 2	4 ----> 6(2)
//
const int MAXV = 21;

int V;
int par[MAXV];
vector<int> child[MAXV];
int val[MAXV];
int root;
void readInput() {
	cin >> V;
	for(int i=1; i <= V; ++i) {
		cin >> par[i] >> val[i];
		if (par[i] == 0)
			root = i;
		else
			child[par[i]].push_back(i);
	}
}
