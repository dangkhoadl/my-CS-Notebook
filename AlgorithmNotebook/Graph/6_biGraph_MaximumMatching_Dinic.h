

/*
    O(E*V^2)
    // vertex_id start by 1
*/

int F,C;
int G[MAXV][MAXV];
void maximumMatching() {
    int src = F + C + 1;
    int snk = F + C + 2;
    DinicFlow Flow(F+C+2);

    // Connect source -> F
    for(int f=1; f<=F; ++f) {
        Flow.addEdge(src, f, 1);
    }

    // Connect C -> sink
    for(int c=1; c<=C; ++c) {
        Flow.addEdge(F+c, snk, 1);
    }

    // Connect F -> C
    for(int f=1; f<=F; ++f) for(int c=1; c<=C; ++c){
        if(G[f][c] == 1)
            Flow.addEdge(f, F+c, 1);
    }

    // Find Maximum matching
    Flow.maxFlow(src, snk);
    for(int f=1; f<=F; ++f) for(int c=1; c<=C; ++c) {
        if(Flow.checkFlow(f,F+c) == 1)
            cout << f << " matches " << c << endl; 
    }
}
