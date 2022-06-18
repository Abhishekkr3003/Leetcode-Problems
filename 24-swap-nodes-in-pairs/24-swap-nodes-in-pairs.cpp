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
        
        ListNode *prev, *ptr1=head, *ptr2=head->next, *nxt=ptr2->next;
        ptr2->next=ptr1;
        head=ptr2;
        prev=ptr1;
        ptr1->next=nxt;
        
        while(nxt && nxt->next){
            ptr1=nxt;
            ptr2=nxt->next;
            nxt=ptr2->next;
            ptr2->next=ptr1;
            ptr1->next=nxt;
            prev->next=ptr2;
            prev=ptr1;
        }
        
        return head;      
    }
};