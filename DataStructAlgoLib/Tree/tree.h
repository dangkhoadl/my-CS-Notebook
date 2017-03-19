//MultiTree adjnode presentation
//Node	| childNode	 data
// root node has adjnode == 0
//Eg:
//6
//2 4	2 ----> 1(4)						
//0 5	2(5): root
//4 2	4 ----> 3(2)
//2 1	2 ----> 4(1)
//1 1	1 ----> 5(1)
//4 2	4 ----> 6(2)
//

const int MAXEDGE = 21;
int n;
int par[MAXEDGE];
int dat[MAXEDGE];

int root;
vector<int> child[MAXEDGE];

void readInput() {
	cin >> n;
	for(int i=1; i <=n; ++i) {
		cin >> par[i] >> dat[i];
		if (par[i] == 0)
			root = i;
		else
			child[par[i]].push_back(i);
	}
}
