
// s1 = Test
// s2 = testTesttesT
//    cmpS1S2(0,4, 4,8) = true

class StrCmp {
private:
    string s1, s2;
    
    const int base = 1e9+7;
    vector<int> h1,h2,p1,p2;
private:
    bool cmpsubString(int start1, int end1, int start2, int end2) {
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
    int getHashVal(const vector<int> &h, const vector<int> &p, int start, int end) {
        return h[end]-h[start]*p[end-start];
    }
    void precompute() {
        p1[0]=1;
        h1[0]=1;
        for(int i=1; i<s1.size(); ++i) {
            p1[i]=p1[i-1]*base;
            h1[i]=h1[i-1]*base+s1[i];
        }

        p2[0]=1;
        h2[0]=1;
        for(int i=1; i<s2.size(); ++i) {
            p2[i]=p2[i-1]*base;
            h2[i]=h2[i-1]*base+s2[i];
        }
    }
public:
    StrCmp(const string &s1, const string &s2) {
        this->s1.assign(1, '$'); this->s1 += s1;
        this->s2.assign(1, '$'); this->s2 += s2;

        this->p1.assign(this->s1.size(), 0);
        this->h1.assign(this->s1.size(), 0);

        this->p2.assign(this->s2.size(), 0);
        this->h2.assign(this->s2.size(), 0);

        this->precompute();
    }
    // [start, end)
    bool cmpS1S2(int start1, int end1, int start2, int end2) {
        // O(1)
        if(getHashVal(h1,p1,start1,end1) != getHashVal(h2,p2,start2,end2))
            return false;
        // O(n) - return true; if wanna play riskly :D O(1)
        return cmpsubString(start1+1,end1+1, start2+1,end2+1); 
    }
};
