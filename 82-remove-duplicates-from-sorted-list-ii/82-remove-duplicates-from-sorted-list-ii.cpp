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
    ListNode* deleteDuplicates(ListNode* head)  {
        if(!head || !head->next){
            return head;
        }
        ListNode *ptr=head, *prev=nullptr;
        bool flag=false;
        while(ptr && ptr->next && ptr->val==ptr->next->val){
            while(ptr && ptr->next){
                if(ptr->val==ptr->next->val){
                    ptr=ptr->next;
                }
                else{
                    break;
                }
            }
            ptr=ptr->next;
        }
        head=ptr;
        prev=head;
        flag=false;
        while(ptr && ptr->next){
            if(ptr->val==ptr->next->val){
                prev->next=ptr->next;
                ptr=ptr->next;
                flag=true;
            }
            else{
                if(!flag){
                    prev=ptr;
                }
                ptr=ptr->next;
                if(flag){
                    prev->next=ptr;
                    flag=false;
                }
            }
        }
        if(flag){
            prev->next=ptr->next;
        }
        return head;
    }
};