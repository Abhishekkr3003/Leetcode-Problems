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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode *ptr1=head,*ptr2=head;
        int size=0;
        while(ptr1) {
            size++;
            ptr1=ptr1->next;
        }
        k=k%size;
        if(k==0) return head;
        ptr1=head;
        while(k--) ptr1=ptr1->next;
        while(ptr1 && ptr1->next) {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        ListNode *newHead=ptr2->next;
        ptr2->next=nullptr;
        ptr1->next=head;
        return newHead;      
    }
};