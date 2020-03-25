struct TrieNode {
    TrieNode *children[26];
    int num_word;   // Number of words pass through this node
    int end_word;   // Number of words end at this node (count version of boolean isWord)
    int len;        // current len of the prefix
    TrieNode(int len) : len(len) {
        this->end_word = 0;
        this->num_word = 0;
        memset(this->children, NULL, sizeof(this->children));
    }
};
class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode(0);
    }
    void insert(const string &S) {
        TrieNode *cur = root;
        for(const char &c:S) {
            if(cur->children[c-'a'] == NULL)
                cur->children[c-'a'] = new TrieNode(cur->len + 1);
            cur->children[c-'a']->num_word += 1;

            // Next
            cur = cur->children[c-'a'];
        }
        cur->end_word += 1;
    }
};
