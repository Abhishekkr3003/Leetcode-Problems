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
    ListNode* findMid(ListNode *head){
        
        ListNode *slow=head, *fast=head;
        while(fast && fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;  
        
    }
    
    ListNode *getReverse(ListNode *head){
        ListNode *prev=NULL, *ptr=head, *nxt=head->next;
        while(nxt){
            ptr->next=prev;
            prev=ptr;
            ptr=nxt;
            nxt=nxt->next;
        }
        ptr->next=prev;
        return ptr;
    }
    
public:
    int pairSum(ListNode* head) {
        
        ListNode *mid=findMid(head);
        ListNode *ptr2=mid->next;
        mid->next=NULL;
        mid->next=getReverse(ptr2);
        int res=0;
        ListNode *ptr1=head;
        ptr2=mid->next;
        while(ptr2){
            res=max(res,ptr1->val+ptr2->val);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return res;
    }
};