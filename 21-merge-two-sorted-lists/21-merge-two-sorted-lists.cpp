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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *start, *ptr;
        if((l1==nullptr && l2==nullptr) || l2==nullptr)
            return l1;
        else if(l1==nullptr)
            return l2;
        if(l2->val<=l1->val)
        {
            start=l2;
            l2=l2->next;
        }
        else
        {
            start=l1;
            l1=l1->next;
        }
        ptr=start;
        while(l1!=nullptr && l2!=nullptr)
        {
            if(l2->val<=l1->val)
            {
                //cout<<"l2: "<<l2->val<<" ";
                ptr->next=l2;
                ptr=ptr->next;
                //cout<<ptr->val<<"\n";
                l2=l2->next;
            }
            else
            {
                //cout<<"l1: "<<l1->val<<" ";
                ptr->next=l1;
                ptr=ptr->next;
                //cout<<ptr->val<<"\n";
                l1=l1->next;
            }
        }
        if(l1!=nullptr)
            ptr->next=l1;
        else
            ptr->next=l2;
        return start;
        
    }
};