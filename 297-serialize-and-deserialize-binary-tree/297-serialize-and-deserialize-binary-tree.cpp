/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        return to_string(root->val)+"#"+serialize(root->left)+"#"+serialize(root->right);
    }
    
    TreeNode *deser(string data, int &index){
        if(index>=data.length()) return nullptr;
        if(data[index]=='#') {
            index++;
            return nullptr;
        }
        int start=index;
        while(index<data.length() && data[index]!='#') {
            index++;
        }
        index++;
        TreeNode *newNode=new TreeNode(stoi(data.substr(start,index-start)));
        newNode->left=deser(data,index);
        newNode->right=deser(data,index);
        return newNode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // cout<<data<<endl;
        int index=0;
        return deser(data,index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));