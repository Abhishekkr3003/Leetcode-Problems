/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node *ptr1=head, *ptr2=head->next;
        while(ptr2){
            Node *temp=new Node(ptr1->val);
            temp->next=ptr2;
            ptr1->next=temp;
            ptr1=ptr2;
            ptr2=ptr2->next;
        }
        Node *temp=new Node(ptr1->val);
        temp->next=ptr2;
        ptr1->next=temp;
        
//         ptr1=head;
//         while(ptr1){
//             cout<<ptr1->val<<" ";
//             ptr1=ptr1->next;
//         }
//         cout<<endl;
        ptr1=head, ptr2=head->next;
        while(ptr1){
            // cout<<ptr1->val<<endl;
            // cout<<ptr2->val<<endl;
            if(ptr1->random) ptr2->random=ptr1->random->next;
            ptr1=ptr1->next->next;
            if(ptr1) ptr2=ptr1->next;
        }
        // ptr1=head;
        // while(ptr1){
        //     // cout<<ptr1->val<<" ";
        //     ptr1=ptr1->next;
        // }
        // cout<<endl;
        Node *newHead=head->next, *newTail=head->next;
        ptr1=head->next->next;
        head->next=ptr1;
        while(ptr1){
            newTail->next=ptr1->next;
            newTail=newTail->next;
            // cout<<ptr1->val<<endl;
            ptr2=ptr1->next->next;
            ptr1->next=ptr2;
            ptr1=ptr2;
        }
        return newHead;
    }
};