class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int>visited;
        unordered_set<int>repeated;
        int count=0;
        for(int num:nums){
            if(visited.find(num)==visited.end()){
                if(visited.find(num+k)!=visited.end()) count++; 
                if(visited.find(num-k)!=visited.end()) count++; 
            }else if(k==0 && repeated.find(num)==repeated.end()){
                count++;
                repeated.insert(num);
            }
            visited.insert(num);
        }
        return count;
    }
};