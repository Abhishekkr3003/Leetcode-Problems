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
    ListNode *findMid(ListNode *head){
        ListNode *fast=head, *slow=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    void reverse(ListNode *mid){
        ListNode *ptr1=nullptr;
        ListNode *ptr2=mid->next;
        ListNode *ptr3=ptr2->next;
        
        while(true){
            ptr2->next=ptr1;
            ptr1=ptr2;
            ptr2=ptr3;
            // cout<<ptr1->val;
            if(!ptr2) break;
            ptr3=ptr3->next;
        }
        mid->next=ptr1;
        
    }
    
    
public:
    bool isPalindrome(ListNode* head) {
        if(!head->next)return true;
        ListNode *mid=findMid(head);
        reverse(mid);
        ListNode *ptr1=head, *ptr2=mid->next;
        ListNode *temp=head;
      
        while(ptr2){
            if((ptr1->val)!=(ptr2->val)){
                return false;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return true;
    }
};