/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *ptr=head, *prev=nullptr;
        ListNode *temp;
        temp=ptr->next;
        ptr->next=temp->next;
        temp->next=ptr;
        prev=ptr;
        ptr=ptr->next;
        head=temp;
        while(ptr && ptr->next){
            temp=ptr->next;
            ptr->next=temp->next;
            temp->next=ptr;
            prev->next=temp;
            prev=ptr;
            ptr=ptr->next;
        }
        return head;
        
    }
};