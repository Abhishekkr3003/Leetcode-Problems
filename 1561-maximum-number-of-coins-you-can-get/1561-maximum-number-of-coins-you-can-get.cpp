/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int res = 0;
        int i = 0, j = piles.size() - 1;
        while(i<j){
            i++;
            j--;
            res+=piles[j];
            j--;
        }
        return res;
    }
};