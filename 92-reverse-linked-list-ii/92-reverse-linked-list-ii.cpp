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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode *prev=nullptr, *cur=head, *nxt=head->next;
        while(cur->next){
            cur->next=prev;
            prev=cur;
            cur=nxt;
            nxt=nxt->next;
        }
        cur->next=prev;
        head=cur;
        return head;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head->next || left==right){
            return head;
        }
        ListNode *prev, *ptr=head, *temp=nullptr, *tempHead=nullptr;
        bool header=false;
        right=right-left;
        if(left==1){
            header=true;
            tempHead=head;
            ptr=head;
        }
        else{
            left-=2;
            while(left--){
                ptr=ptr->next;
            }
            prev=ptr;
            ptr=ptr->next;
            tempHead=ptr;
        }
        
        while(right--){
            ptr=ptr->next;
        }
        temp=ptr->next;
        ptr->next=nullptr;
        tempHead=reverseList(tempHead);
        
        if(header){
            head->next=temp;
            head=tempHead;
        }
        else{
            prev->next->next=temp;
            prev->next=tempHead; 
        }
        return head;
    }
};