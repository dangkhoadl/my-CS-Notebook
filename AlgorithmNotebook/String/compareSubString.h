
// Notes: String must start w/ index 1

/*------------------------------------------ Sub API --------------------------------------*/
// [start,end)
bool cmpsubString(const string &s1, int start1, int end1, const string &s2, int start2, int end2) {
    assert(start1 >= 0 and start1 < end1 and end1 <= s1.size());
    assert(start2 >= 0 and start2 < end2 and end2 <= s2.size());
    if((end1 - start1) != (end2 - start2))
        return false;
    for(int i = 0; i < (end1-start1); ++i) {
        if(s1[i+start1] != s2[i+start2])
            return false;
    }
    return true;
}

// [start,end)
int getHashVal(int h[], int p[], int start, int end){
    return h[end-1]-h[start-1]*p[end-start];
}

/*------------------------------------------ MAIN API --------------------------------------*/
const int base=1e9+7;
int h1[MAXN],p1[MAXN];
int h2[MAXN],p2[MAXN];
void precompute(const string &s1, const string &s2) {
    memset(p1,0,sizeof(p1));
    memset(h1,0,sizeof(h1));
    p1[0]=1;
    h1[0]=1;
    for(int i=1; i<s1.size(); ++i){
        p1[i]=p1[i-1]*base;
        h1[i]=h1[i-1]*base+s1[i];
    }

    memset(p2,0,sizeof(p2));
    memset(h2,0,sizeof(h2));
    p2[0]=1;
    h2[0]=1;
    for(int i=1; i<s2.size(); ++i){
        p2[i]=p2[i-1]*base;
        h2[i]=h2[i-1]*base+s2[i];
    }
}

bool quickCmpsubString(const string &s1, int start1, int end1, const string &s2, int start2, int end2) {
    // O(1)
    if(getHashVal(h1,p1,start1,end1) != getHashVal(h2,p2,start2,end2))
        return false;
    // O(n)
    return cmpsubString(s1,start1,end1, s2,start2,end2); // return true; if wanna play riskly :D O(1)
}
