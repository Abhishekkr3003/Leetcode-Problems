struct Node{
    vector<Node*>children;
    bool isTerminal;
    Node(){
        children.resize(26,NULL);
        isTerminal=false;
    }
};

class Trie {
    Node *root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node *cur=root;
        for(int i=0;i<word.length();i++){
            if(!cur->children[word[i]-'a']) cur->children[word[i]-'a']=new Node();
            cur=cur->children[word[i]-'a'];
        }
        cur->isTerminal=true;
    }
    
    bool search(string word) {
        Node *cur=root;
        for(int i=0;i<word.length();i++){
            if(!cur->children[word[i]-'a']) return false;
            cur=cur->children[word[i]-'a'];
        }
        return cur->isTerminal;
    }
    
    bool startsWith(string prefix) {
        Node *cur=root;
        for(int i=0;i<prefix.length();i++){
            if(!cur->children[prefix[i]-'a']) return false;
            cur=cur->children[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */