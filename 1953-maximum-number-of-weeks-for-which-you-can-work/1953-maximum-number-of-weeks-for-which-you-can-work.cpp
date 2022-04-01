typedef long long ll;

/*
    Time: O(n)
    Space: O(1)
    Tag: Greedy
    Difficulty: H
*/

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        ll sum=accumulate(milestones.begin(),milestones.end(),0ll);
        ll maxEle=*max_element(milestones.begin(),milestones.end());
        if(maxEle>sum-maxEle) return sum=2*(sum-maxEle)+1;
        return sum;
    }
};