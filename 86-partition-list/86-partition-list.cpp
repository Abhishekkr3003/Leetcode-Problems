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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next){
            return head;
        }
        ListNode* l1=nullptr, *l1ptr=nullptr, *l2=nullptr, *l2ptr=nullptr, *ptr=head;
        bool head1=false, head2=false;
        while(ptr){
            //cout<<ptr->val<<"\n";
            if(ptr->val<x){
                if(head1==false){
                    l1ptr=ptr;
                    ptr=ptr->next;
                    l1ptr->next=nullptr;
                    l1=l1ptr;
                    head1=true;
                }
                else{
                    l1ptr->next=ptr;
                    ptr=ptr->next;
                    l1ptr=l1ptr->next;
                    l1ptr->next=nullptr;
                }
            }
            else{
                if(head2==false){
                    l2ptr=ptr;
                    ptr=ptr->next;
                    l2ptr->next=nullptr;
                    l2=l2ptr;
                    head2=true;
                }
                else{
                    l2ptr->next=ptr;
                    ptr=ptr->next;
                    l2ptr=l2ptr->next;
                    l2ptr->next=nullptr;
                }
            }
        }
        if(head1){
            head=l1;
            //cout<<"Here";
            l1ptr->next=l2;
        }
        else
            head=l2;
        
        return head;
    }
};