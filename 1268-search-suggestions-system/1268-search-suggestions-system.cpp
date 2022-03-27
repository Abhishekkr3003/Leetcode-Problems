/*
    Time: O(len(all characters in products))
    Space: O(No. of nodes in Trie)
    Tag: Trie + DFS
    Difficulty: M
*/

struct Node {
    vector<Node*>children;
    bool isTerminal;

    Node() {
        children.resize(26, NULL);
        isTerminal = false;
    }
};

class Trie {
    Node* root = new Node();

    bool dfs(Node* node, vector<string>& res, string& cur) {
        if (node->isTerminal) res.push_back(cur);
        if (res.size() >= 3) return true;
        for (int i = 0;i < 26;i++) {
            if (node->children[i]) {
                cur += ('a' + i);
                if (dfs(node->children[i], res, cur)) return true;
                cur.pop_back();
            }
        }
        return false;
    }

public:

    void insert(string s) {
        Node* cur = root;
        for (char ch : s) {
            if (!(cur->children[ch - 'a'])) cur->children[ch - 'a'] = new Node;
            cur = cur->children[ch - 'a'];
        }
        cur->isTerminal = true;
    }

    vector<string>search(string s) {
        Node* cur = root;
        for (char ch : s) {
            if (!cur->children[ch - 'a']) return {};
            cur = cur->children[ch - 'a'];
        }
        vector<string>res;
        dfs(cur, res, s);
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* t = new Trie();
        for (string s : products) t->insert(s);
        string temp = "";
        vector<vector<string>>res;
        for (char ch : searchWord) {
            temp += ch;
            res.push_back(t->search(temp));
        }
        return res;
    }
};