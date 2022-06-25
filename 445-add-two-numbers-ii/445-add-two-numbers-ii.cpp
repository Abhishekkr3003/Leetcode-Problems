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
    
    int findLen(ListNode *head){
        int len=0;
        while(head){
            head=head->next;
            len++;
        }
        return len;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=findLen(l1);
        int len2=findLen(l2);
        
        if(len1<len2) {
            swap(l1,l2);
            swap(len1,len2);
        }
        
        stack<ListNode*>st;
        
        while(len1>len2) {
            st.push(l1);
            l1=l1->next;
            len1--;
        }
        while(l1){
            l1->val+=l2->val;
            st.push(l1);
            l1=l1->next;
            l2=l2->next;
        }
        
        bool carry=false;
        while(st.size()>1){
            bool temp=(st.top()->val+carry)/10;
            st.top()->val=(st.top()->val+carry)%10;
            carry=temp;
            st.pop();
        }
        
        if(st.top()->val+carry>9){
            st.top()->val=(st.top()->val+carry)%10;
            ListNode *newNode=new ListNode(1);
            newNode->next=st.top();
            return newNode;
        }
        st.top()->val=(st.top()->val+carry);
        return st.top();
    }
};