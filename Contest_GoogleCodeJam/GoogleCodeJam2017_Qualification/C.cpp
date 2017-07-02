
// https://codejam.withgoogle.com/codejam/contest/3264486/dashboard#s=p2

int N, K;
ll readInput() {
	scanf("%lld %lld", &N, &K);
	return 0;
}

/*_______________________________ O(K*log(K)) _________________________*/
pii sol1() {
    priority_queue<int> S;
    S.push(N);
    int x0 = 0;
    int x1 = 0;

    REP(K) {
        int x = S.top();
        S.pop();

        x0 = ceil((double)(x - 1) / 2);
        S.push(x0);

        x1 = floor((x - 1) / 2);
        S.push(x1);
    }
    return{ x0,x1 };
}

/*_______________________________ ~O(K) _________________________*/
pii sol2() {
    map<int,int> S;
    S.insert( {N,1} );
    int x0 = 0;
    int x1 = 0;
    
    REP(K) {
        auto it = S.end(); --it;
        int x = it->fi;
        if(it->se == 1)
            S.erase(it);
        else
            --it->se;

        x0 = ceil((double)(x-1) / 2);
        it = S.find(x0);
        if(it == S.end())
            S.insert( {x0, 1} );
        else
            ++it->se;

        x1 = floor((double)(x-1) / 2);
        it = S.find(x1);
        if(it == S.end())
            S.insert( {x1, 1} );
        else
            ++it->se;
    }
    return {x0,x1};
}

