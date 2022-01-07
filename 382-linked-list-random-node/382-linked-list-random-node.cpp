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
    int size;
    ListNode *head;
public:
    Solution(ListNode* head) {
        size=0;
        this->head=head;
        while(head) {
            head=head->next;
            size++;
        }
    }
    
    int getRandom() {
        int r=rand()%size;
        ListNode *ptr=head;
        while(r--) ptr=ptr->next;
        return ptr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */