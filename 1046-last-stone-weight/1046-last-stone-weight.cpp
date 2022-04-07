class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for(int stone:stones) q.push(stone);
        while(q.size()>1){
            int num1=q.top(); q.pop();
            int num2=q.top(); q.pop();
            if(num1!=num2) q.push(abs(num1-num2));
        }
        return q.empty()?0:q.top();
    }
};