
// 3 Advanced Problem: Network packet processing simulation

const int MAXN = 1e5 + 3;

int S,N;
int A[MAXN];
int P[MAXN];
ll readInput() {
    sii(S,N);
    FOR(n,1,N+1) {
        si(A[n]);
        si(P[n]);
    }
    
    return 0;
}


int stt[MAXN];
int endt[MAXN];
void sol() {
    ms(stt, -1);
    ms(endt, -1);

    queue<int> Q;

    FOR(n,1,N+1) {
        // pop
        while(!Q.empty()) {
            int i = Q.front();

            if(A[n] >= endt[i]) {
                Q.pop();
                if(!Q.empty()) {
                    stt[Q.front()] = endt[i];
                    endt[Q.front()] = stt[Q.front()] + P[Q.front()];
                }
            }
            else
                break;
        }

        // Insert
        if(sz(Q) < S) {
            if(Q.empty()) {
                stt[n] = A[n];
                endt[n] = stt[n] + P[n];
            }
            Q.push(n);
        }
    }

    while(!Q.empty()) {
        int i = Q.front();
        Q.pop();
        if(!Q.empty()) {
            stt[Q.front()] = endt[i];
            endt[Q.front()] = stt[Q.front()] + P[Q.front()];
        }
    }
}


ll solve() {
    sol();
    FOR(n,1,N+1)
        cout << stt[n] << endl;
    
    return 0;
}
