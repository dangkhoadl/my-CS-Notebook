
// Vertex start from 1 

/*------------------------------------- Directed Graph ---------------------------------------------------------------*/
// V E
// vertex adjvertex weight 
//Eg:
//
//6 6           V E
//1 2 2         1 --(2)--> 2
//2 3 2         2 --(2)--> 3
//2 6 3         2 --(3)--> 6
//3 4 1         3 --(1)--> 4
//4 2 3         4 --(3)--> 2
//5 6 1         5 --(1)--> 6

const int MAXV = 101;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

void readInput() {
    scanf("%lld %lld", &V, &E);     // cin >> V >> E;

    for (int i = 1; i <= V; ++i) {
        e[i].clear();
        wei[i].clear();
    }
    int v, u, w;
    for (int i = 1; i <= E; ++i) {
        scanf("%lld %lld %lld", &v, &u, &w); // cin >> v >> u >> w;
        e[v].push_back(u);
        wei[v].push_back(w);
    }
}
/********************************************************************************/
// V E
// vertex | numOfAdjVertex  adjvertex[0] weight[0]  adjvertex[1] weight[1]  ... 
//Eg:
//
//6 6           V E
//1 2 2         1 --(2)--> 2
//2 3 2 6 3     2 --(2)--> 3        2 --(3)--> 6    
//1 4 1         3 --(1)--> 4
//1 2 3         4 --(3)--> 2
//1 6 1         5 --(1)--> 6

const int MAXV = 101;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

void readInput() {
    scanf("%lld %lld", &V, &E);     // cin >> V >> E;
    for (int i = 1; i <= V; ++i) {
        e[i].clear();
        wei[i].clear();
    }
    for (int i = 1; i <= V; ++i) {
        int num, u, w;
        scanf("%lld", &num); // cin >> num;
        for (int j = 0; j < num; ++j) {
            scanf("%lld %lld", &u, &w); // cin >> u >> w;
            e[i].push_back(u);
            wei[i].push_back(w);
        }
    }
}


/*------------------------------------- BiDirected Graph ---------------------------------------------------------------*/
// V E
// vertex adjvertex weight 
//Eg:
//
//6 6           V E
//1 2 2         1 --(2)-- 2
//2 3 2         2 --(2)-- 3
//2 6 3         2 --(3)-- 6
//3 4 1         3 --(1)-- 4
//4 2 3         4 --(3)-- 2
//5 6 1         5 --(1)-- 6

const int MAXV = 101;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

void readInput() {
    scanf("%lld %lld", &V, &E);     // cin >> V >> E;
    for (int i = 1; i <= V; ++i) {
        e[i].clear();
        wei[i].clear();
    }
    int v, u, w;
    for (int i = 1; i <= E; ++i) {
        scanf("%lld %lld %lld", &v, &u, &w); // cin >> v >> u >> w;
        e[v].push_back(u), e[u].push_back(v);
        wei[v].push_back(w), wei[u].push_back(w);
    }
}
/********************************************************************************/
// V E
// vertex | numOfAdjVertex  adjvertex[0] weight[0]  adjvertex[1] weight[1]  ... 
//Eg:
//
//6 6           V E
//1 2 2         1 --(2)-- 2
//2 3 2 6 3     2 --(2)-- 3     2 --(3)-- 6 
//1 4 1         3 --(1)-- 4
//1 2 3         4 --(3)-- 2
//1 6 1         5 --(1)-- 6
const int MAXV = 101;
int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

void readInput() {
    scanf("%lld %lld", &V, &E);     // cin >> V >> E;
    for (int i = 1; i <= V; ++i) {
        e[i].clear();
        wei[i].clear();
    }
    for (int i = 1; i <= V; ++i) {
        int num, u, w;
        scanf("%lld", &num); // cin >> num;
        for (int j = 0; j < num; ++j) {
            scanf("%lld %lld", &u, &w); // cin >> u >> w;
            e[i].push_back(u), e[u].push_back(i);
            wei[i].push_back(w), wei[u].push_back(w);
        }
    }
}
