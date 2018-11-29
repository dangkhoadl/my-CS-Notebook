
class Trie {
private:
    vector<string> patterns;

    int V;
    vector<map<char, int>> trie;
private:
    void constructTrie() {
        for(int p = 0; p < patterns.size(); ++p) {
            // start at root
            int curV = 0;
            for(int i = 0; i < patterns[p].size(); ++i) {
                char curSym = patterns[p][i];

                // Find if sym in next edge of v, move to next vertex
                auto it = trie[curV].find(curSym);
                if(it != trie[curV].end())
                    curV = it->second;

                // if sym not in next edge of v, create new vertex
                else {
                    int newNode = this->V;
                    trie.resize(++this->V);
                    trie[curV].insert( {patterns[p][i], newNode} );
                    curV = newNode;
                }
            }
        }
    }
    bool prefixMatch(const string &s, int i) {
        int sym = s[i];
        int v = 0;
        while(true) {
            // if next v contain $
            auto it = trie[v].find('$');
            if (it != trie[v].end()) return true;

            // if no edges from v contain symbol
            it = trie[v].find(sym);
            if (it == trie[v].end()) return false;

            // move to next symbol and next v
            sym = s[++i];
            v = it->second;
        }
    }
public:
    Trie(const vector<string> &patterns):
            patterns(patterns) {
        // Add $ to end of pattern
        for(int p = 0; p < this->patterns.size(); ++p)
            this->patterns[p].push_back('$');

        // Init trie root = vertex = 0
        this->V = 1;
        this->trie.assign(1, map<char, int>());

        // Contruct new trie from root
        this->constructTrie();
    }
    vector<int> patternMatching(const string &text) {
        vector<int> matches;
        for(int i = 0; i < text.size(); ++i) 
            if(prefixMatch(text, i))
                matches.push_back(i);
        return matches;
    }
};
