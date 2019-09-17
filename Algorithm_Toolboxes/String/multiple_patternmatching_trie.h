
class Trie {
private:
    class Node {
    public:
        Node *children[26];
        bool isWord;
        int len;
    public:
        Node(int len) : len(len) {
            this->isWord = false;
            memset(this->children, NULL, sizeof(this->children));
        }
    };
    Node *root;
public:
    Trie() {
        root = new Node(0);
    }
    void insert(const string &P) {
        Node *cur = root;
        for(const char &c:P) {
            if(cur->children[c-'a'] == NULL) 
                cur->children[c-'a'] = new Node(cur->len + 1);
            cur = cur->children[c-'a'];
        }
        cur->isWord = true;
    }
};

