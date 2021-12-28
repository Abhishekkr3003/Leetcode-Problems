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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* ptr1=head, *ptr2=nullptr, *cur;
        while(ptr1->next){
            // cout<<head->val<<endl;
            cur=ptr1->next;
            if(cur->val<head->val){
                ptr1->next=cur->next;
                cur->next=head;
                head=cur;
            }else{
                ptr2=head;
                while((ptr2->next) && (ptr2->next!=cur) && ((ptr2->next->val)<cur->val)) ptr2=ptr2->next;
                if(ptr2->next==cur){
                    ptr1=ptr1->next;
                }else{
                    ptr1->next=cur->next;
                    cur->next=ptr2->next;
                    ptr2->next=cur;
                }
            }
        }
        return head;
    }
};