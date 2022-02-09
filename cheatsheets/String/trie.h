/************************************** Simple Trie ******************************************************************/
// Note: Apply for string in range[a,z]. Remember to adjust 'a' or 26
struct TrieNode {
public:
    TrieNode* _children[26];
    bool _is_word;

public:
    TrieNode() {
        _is_word = false;
        memset(_children, NULL, sizeof(_children));
    }
};

class Trie {
public:
    TrieNode *_root;

public:
    Trie() {
        _root = new TrieNode();
    }
    void insert(const string &pattern) {
        TrieNode *cur = _root;
        for(const char &c:pattern) {
            if(cur->_children[c-'a'] == NULL) cur->_children[c-'a'] = new TrieNode();
            cur = cur->_children[c-'a'];
        }
        cur->_is_word = true;
    }
};

/************************************** Advanced ******************************************************************/
// Note: Apply for string in range[a,z]. Remember to adjust 'a' or 26
struct TrieNode {
public:
    TrieNode *_children[26];
    string _pref; // curent prefix (remove if not needed)

public:
    int _num_word; // Number of words pass through this node (remove if not needed)
    int _end_word; // Number of words end at this node (count version of boolean isWord) (remove if not needed)
    int _len;      // current len of the prefix (remove if not needed)
    TrieNode(int len=0, string pref="") : _len(len), _pref(pref) {
        _end_word = 0;
        _num_word = 0;
        memset(_children, NULL, sizeof(_children));
    }
};

class Trie {
public:
    TrieNode *_root;
    Trie() {
        _root = new TrieNode(0, "");
    }

public:
    void insert(const string &pattern) {
        TrieNode *cur = _root;
        for (const char &c : pattern) {
            if (cur->_children[c - 'a'] == NULL) {
                cur->_children[c - 'a'] = new TrieNode(cur->len + 1, cur->_pref + c);
            }
            cur->_children[c - 'a']->_num_word += 1;

            // Next
            cur = cur->_children[c - 'a'];
        }
        cur->_end_word += 1;
    }
};

/******************** DFS template ********************/
// Driver: for (int i = 0; i < 26; ++i) dfs(trie->_root->_children[i]);
void dfs(TrieNode *cur) {
    if (cur == NULL) return;

    cout << "Current prefix: \"" << cur->_pref << "\" - len = " << cur->_len << endl;
    cout << "Number of words pass through this node: " << cur->_num_word << endl;
    cout << "Number of words end at this node: " << cur->_end_word << endl
         << endl;

    for (int i = 0; i < 26; ++i) {
        dfs(cur->_children[i]);
    }
}
