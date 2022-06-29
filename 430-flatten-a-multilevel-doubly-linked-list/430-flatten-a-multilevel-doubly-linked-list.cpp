/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    pair<Node*,Node*> solve(Node* head, Node *secondHead){
        if(!head) return {NULL,NULL};
        Node *ptr=head, *nxt=head->next, *tail=head;
        
        Node *subListHead=NULL, *subListTail=NULL;
        while(ptr){
            // cout<<ptr->val<<endl;
            if(ptr->child){
                pair<Node*,Node*>p=solve(ptr->child, nxt);
                subListHead=p.first;
                subListTail=p.second;
                ptr->next=subListHead;
                subListHead->prev=ptr;   
                subListTail->next=nxt;
                // cout<<"next: "<<subListTail->val<<" "<<nxt->val<<endl;
                if(nxt) nxt->prev=subListTail;
                ptr->child=NULL;
            }
            if(nxt!=NULL) tail=nxt;
            else if(nxt==NULL && subListTail!=NULL) tail=subListTail;
            ptr=nxt;
            if(ptr) nxt=ptr->next;
            subListTail=NULL;
        }
        
    
        return {head,tail};
    }
public:
    Node* flatten(Node* head) {
        solve(head,NULL);
        return head;
    }
};