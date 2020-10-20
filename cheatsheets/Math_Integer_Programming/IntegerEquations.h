
// Application: Find all x that
//           S/W < x < E/W


// Find x in range[a,b] such that 
//      S <= W*x <= E
// a,b,S,W,E: int
bool findRange(int S, int W, int E, pair<int,int> &res) {
    assert(S <= E);
    int a = S/W+1;
    while(S <= W*a) --a;
    ++a;

    int b = E/W-1;
    while(W*b <= E) ++b;
    --b;

    if(a > b)
        return false;

    res = {a,b};
    return true;
}


// Find x in range[a,b] such that 
//      S < W*x <= E
// a,b,S,W,E: int
bool findRange(int S, int W, int E, pair<int,int> &res) {
    assert(S < E);
    int a = S/W+1;
    while(S < W*a) --a;
    ++a;

    int b = E/W-1;
    while(W*b <= E) ++b;
    --b;

    if(a > b)
        return false;

    res = {a,b};
    return true;
}

// Find x in range[a,b] such that 
//      S <= W*x < E
// a,b,S,W,E: int
bool findRange(int S, int W, int E, pair<int,int> &res) {
    assert(S < E);
    int a = S/W+1;
    while(S <= W*a) --a;
    ++a;

    int b = E/W-1;
    while(W*b < E) ++b;
    --b;

    if(a > b)
        return false;

    res = {a,b};
    return true;
}


// Find x in range[a,b] such that 
//      S < W*x < E
// a,b,S,W,E: int
bool findRange(int S, int W, int E, pair<int,int> &res) {
    assert(S < E);
    int a = S/W+1;
    while(S < W*a) --a;
    ++a;

    int b = E/W-1;
    while(W*b < E) ++b;
    --b;

    if(a > b)
        return false;

    res = {a,b};
    return true;
}
