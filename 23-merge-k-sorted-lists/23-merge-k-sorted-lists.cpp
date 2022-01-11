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
    ListNode *merge(ListNode *h1, ListNode* h2){
        if(!h1 && !h2) return nullptr;
        if(!h1) return h2;
        if(!h2) return h1;
        ListNode *head, *tail;
        if(h1->val<h2->val) {
            head=tail=h1;
            h1=h1->next;
        }
        else{
            head=tail=h2;
            h2=h2->next;
        }
        while(h1 && h2){
            if(h1->val<h2->val){
                tail->next=h1;
                tail=h1;
                h1=h1->next;
            }else{
                tail->next=h2;
                tail=h2;
                h2=h2->next;
            }
        }
        if(h1) tail->next=h1;
        if(h2) tail->next=h2;
        return head;
    }
    
    ListNode *divide(int i, int j, vector<ListNode*>&list){
        if(i==j) return list[i];
        int mid=i+((j-i)/2);
        // cout<<mid<<endl;
        return merge(divide(i,mid,list),divide(mid+1,j,list));
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return divide(0,lists.size()-1,lists);
    }
};