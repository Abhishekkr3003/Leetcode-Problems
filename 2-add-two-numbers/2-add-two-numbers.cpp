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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1=l1;
        ListNode *temp2=l2;
        vector<int>v;
        int rem=0;
        int sum=0;
        while((temp1!=nullptr) && (temp2!=nullptr)){
            sum= temp1->val+temp2->val+rem; 
            v.push_back((sum)%10);
            rem=sum/10;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=nullptr){
            sum=temp1->val+rem;
            v.push_back((sum)%10);
            rem=sum/10;
            temp1=temp1->next;
        }
        while(temp2!=nullptr){
            sum=temp2->val+rem;
            v.push_back((sum)%10);
            rem=sum/10;
            temp2=temp2->next;
        }
        if(rem)
            v.push_back(rem);
        ListNode *ptr1, *ptr2;
        ptr1=new ListNode(v[v.size()-1]);
        for(int i=v.size()-2;i>=0;i--){
            ptr2=new ListNode(v[i], ptr1);
            ptr1=ptr2;
        }
        v.clear();
        v.shrink_to_fit();
        return ptr1;
    }
};