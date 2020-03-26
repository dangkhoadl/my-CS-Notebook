/************************************** Simple Trie ******************************************************************/
// Note: Apply for string in range[a,z]. Remember to adjust 'a' or 26
struct TrieNode {
    TrieNode *children[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        memset(this->children, NULL, sizeof(this->children));
    }
};
class Trie {
public:
    TrieNode *root;
    Trie() {
        this->root = new TrieNode();
    }
    void insert(const string &word) {
        TrieNode *cur = root;
        for(const char &c:word) {
            if(cur->children[c-'a'] == NULL) cur->children[c-'a'] = new TrieNode();
            cur = cur->children[c-'a'];
        }
        cur->isWord = true;
    }
};


/************************************** Advanced ******************************************************************/
// Note: Apply for string in range[a,z]. Remember to adjust 'a' or 26
struct TrieNode {
    TrieNode *children[26];
    string pref; // curent prefix (remove if not needed)

    int num_word; // Number of words pass through this node (remove if not needed)
    int end_word; // Number of words end at this node (count version of boolean isWord) (remove if not needed)
    int len;      // current len of the prefix (remove if not needed)
    TrieNode(int len = 0, string pref = "") : len(len), pref(pref) {
        this->end_word = 0;
        this->num_word = 0;
        memset(this->children, NULL, sizeof(this->children));
    }
};
class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode(0, "");
    }
    void insert(const string &S) {
        TrieNode *cur = root;
        for (const char &c : S) {
            if (cur->children[c - 'a'] == NULL) {
                cur->children[c - 'a'] = new TrieNode(cur->len + 1, cur->pref + c);
            }
            cur->children[c - 'a']->num_word += 1;

            // Next
            cur = cur->children[c - 'a'];
        }
        cur->end_word += 1;
    }
};

/******************** DFS template ********************/
// Driver: for (int i = 0; i < 26; ++i) dfs(trie->root->children[i]);
void dfs(TrieNode *cur) {
    if (cur == NULL) return;

    cout << "Current prefix: \"" << cur->pref << "\" - len = " << cur->len << endl;
    cout << "Number of words pass through this node: " << cur->num_word << endl;
    cout << "Number of words end at this node: " << cur->end_word << endl
         << endl;

    for (int i = 0; i < 26; ++i) {
        dfs(cur->children[i]);
    }
}
