class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(groupSize==1) return true;
        if(hand.size()%groupSize) return false;
        map<int,int>mp;
        for(int val:hand) mp[val]++;
        queue<pair<int,int>>q;
        for(auto [num,count] : mp){
            if(q.empty()) while(count--) q.push({num,1});
            else{
                if(q.front().first!=num-1) return false;
                int n=q.size();
                if(count<n) return false;
                while(n-- && count--){
                    auto cur=q.front();
                    q.pop();
                    if(cur.second!=groupSize-1) q.push({num,cur.second+1});
                }
                while(count--) q.push({num,1});
            }
        }
        return q.empty();
    }
};