

// Rabin-Karp
// Find the index of pattern P in text T:
//      Examples:
//          P = aba
//          T = abacaba
//              --> 0 4

//  O(|T| + (q+1)*|P|) : q = number of occurrences of P in T (the case pHash == tHash, usually small)

class RabinKarp {
private:
    string T, P;
    
    const int base = 1e9+7;
    vector<int> h1,h2,p1,p2;
private:
    bool cmpsubString(int start1, int end1, int start2, int end2) {
        assert(start1 >= 0 and start1 < end1 and end1 <= T.size());
        assert(start2 >= 0 and start2 < end2 and end2 <= P.size());
        if((end1 - start1) != (end2 - start2))
            return false;
        for(int i = 0; i < (end1-start1); ++i) {
            if(T[i+start1] != P[i+start2])
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
        for(int i=1; i<T.size(); ++i) {
            p1[i]=p1[i-1]*base;
            h1[i]=h1[i-1]*base+T[i];
        }

        p2[0]=1;
        h2[0]=1;
        for(int i=1; i<P.size(); ++i) {
            p2[i]=p2[i-1]*base;
            h2[i]=h2[i-1]*base+P[i];
        }
    }
public:
    RabinKarp(const string &T, const string &P) {
        this->T.assign(1, '$'); this->T += T;
        this->P.assign(1, '$'); this->P += P;

        this->p1.assign(this->T.size(), 0);
        this->h1.assign(this->T.size(), 0);

        this->p2.assign(this->P.size(), 0);
        this->h2.assign(this->P.size(), 0);

        this->precompute();
    }
    vector<int> patterMatching() {
        vector<int> results;
        int pHash = getHashVal(h2,p2,0,P.size()-1);

        for(int i=0; i <= (T.size()-P.size()); ++i) {
            if(getHashVal(h1,p1,i,i+P.size()-1) != pHash)
                continue;

            if(cmpsubString(
                    i+1, i+P.size(),
                    1, P.size()))
                results.push_back(i);
        }
        return results;
    }
};
