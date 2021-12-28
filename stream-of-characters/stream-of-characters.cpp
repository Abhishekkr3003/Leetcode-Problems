struct Node {
    vector<Node*> children;
    bool isTerminal;
    Node() {
        children.resize(26, nullptr);
        isTerminal = false;
    }
};

class Trie {
    Node* root;
    string s;
    

   public:
    Trie() { root = new Node; s="";}

    void insert(string s) {
        Node* cur = root;
        for (int i = s.length() - 1; i >= 0;i--) {
            if (!cur->children[s[i] - 'a']) cur->children[s[i] - 'a'] = new Node;
            cur = cur->children[s[i] - 'a'];
        }
        cur->isTerminal = true;
    }
    
    bool checkSuffix(char letter) {
        s += letter;
        Node* cur = root;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (!cur->children[s[i] - 'a']) return false;
            cur = cur->children[s[i] - 'a'];
            if (cur->isTerminal) return true;
        }
        return false;
    }
};

class StreamChecker {
    Trie* t;

   public:
    StreamChecker(vector<string>& words) {
        t = new Trie();
        for (int i = 0; i < words.size(); i++) {
            t->insert(words[i]);
        }
    }

    bool query(char letter) {
        return t->checkSuffix(letter);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */