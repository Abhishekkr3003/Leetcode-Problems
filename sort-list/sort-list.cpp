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
        ListNode *slow=head, *fast=head;
        while(fast && fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }    
        return slow;
    }
    
    ListNode *merge(ListNode *a, ListNode *b){
        ListNode *h1, *t1;
        if(a->val<b->val) {
            h1=t1=a;
            a=a->next;
        }else{
            h1=t1=b;
            b=b->next;
        }
        while(a && b){
            if(a->val<b->val){
                t1->next=a;
                t1=t1->next;
                a=a->next;
            }else{
                t1->next=b;
                t1=t1->next;
                b=b->next;
            }
        }
        if(!a) t1->next=b;
        else t1->next=a;
        return h1;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *mid=findMid(head);  
        ListNode *head1=head;
        ListNode *head2=mid->next;
        mid->next=nullptr;
        return merge(sortList(head1), sortList(head2));
    }
};