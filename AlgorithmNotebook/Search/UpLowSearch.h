

// 5, 7, 9, 10, 88, 99
//      search(9) --> 9
//      search(55) --> 10
//      search(4) --> S.end()
bool searchLow(const set<int> &S, set<int>::iterator &it, int x) {
    it = S.lower_bound(x);

    if(it == S.end()) {
        --it; 
        return false;
    }

    if(*it == x) 
        return true;

    if(it == S.begin()) {
        it = S.end();
        return false;
    }
 
    --it;
    return false;
}

// 5, 7, 9, 10, 88, 99
//      search(9) --> 9
//      search(55) --> 88
//      search(100) --> S.end()
bool searchHigh(const set<int> &S, set<int>::iterator &it, int x) {
    it = S.lower_bound(x);

    if(it == S.end()) {
        return false;
    }

    if(*it == x) 
        return true;

    return false;
}
