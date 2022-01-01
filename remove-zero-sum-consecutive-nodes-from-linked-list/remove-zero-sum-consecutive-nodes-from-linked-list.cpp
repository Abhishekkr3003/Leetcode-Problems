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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // cout<<"here\n";
        unordered_map<int,ListNode*>mp;
        ListNode *ptr=head;
        int sum=0;
        while(ptr){
            sum+=ptr->val;
            if(sum==0) {
                ListNode *start=head;
                int sum2=0;
                while(start!=ptr){
                    sum2+=start->val;
                    mp.erase(sum2);
                    start=start->next;
                }
                head=ptr->next;
            }
            else if(mp.find(sum)!=mp.end()){
                ListNode *start=mp[sum]->next;
                int sum2=sum;
                while(start!=ptr){
                    sum2+=start->val;
                    mp.erase(sum2);
                    start=start->next;
                }
                mp[sum]->next=ptr->next;
                
            }
            else mp[sum]=ptr;
            // cout<<sum<<endl;
            ptr=ptr->next;
        }
        return head;
    }
};