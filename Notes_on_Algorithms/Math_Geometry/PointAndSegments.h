
// segment = [a, b]

// Notes: Greedy segment: Consider the end(b) of a segment (sorted in incresing order...)

// Check if point in Segments
bool isInRange(int p, int a, int b) {
    assert(a<=b);
    return a <= p and p <= b;
}


// Check interect of 2 segments or points, return the overlapped range
bool isIntersect(pair<int,int> seg1, pair<int,int> seg2, pair<int,int> &res) {
    assert(seg1.first <= seg1.second and seg2.first <= seg2.second);

    int a = max(seg1.first, seg2.first);
    int b = min(seg1.second, seg2.second);
    if(a > b)
        return false;
    res = {a,b};
    return true;
}


// Check if all segment intersect, return the overlapped range
bool isAllIntersect(const vector<pair<int,int>> &segs, pair<int,int> &res) {
    int a = -inf;
    int b = inf;
    for(int i = 0; i < segs.size(); ++i) {
        a = max(a,segs[i].first);
        b = min(b,segs[i].second);
    }

    if(a > b)
        return false;
    res = {a,b};
    return true;
}
