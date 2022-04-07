// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++


struct Node {
    vector<Node *> children;
    Node() {
        children.resize(2, nullptr);
    }
};

class Trie {
    Node *root = new Node;

public:
    void insert(int num) {
        Node *cur = root;
        for (int i = 31; i >= 0; i--) {
            int bit = ((num >> i) & 1);
            if (!cur->children[bit]) cur->children[bit] = new Node;
            cur = cur->children[bit];
        }
    }

    int search(int num) {
        Node *cur = root;
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            bool bit = ((num >> i) & 1);
            if (cur->children[!bit]) {
                cur = cur->children[!bit];
                res = res | (1 << i);
            } else {
                cur = cur->children[bit];
            }
        }
        return res;
    }
};

class Solution{   
public:
    int maxSubarrayXOR(int n, int t[]){    
        Trie *tree = new Trie;
        int res = 0;
        int prefix=0;
        tree->insert(0);
        for (int i = 0; i < n; i++) {
            prefix=prefix^t[i];
            tree->insert(prefix);
            int temp = tree->search(prefix);
            res = max(res, temp);
        }
        return res;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends