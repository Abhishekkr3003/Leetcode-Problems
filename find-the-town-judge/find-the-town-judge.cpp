class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>trusts(n+1,0);
        vector<int>trustedBy(n+1,0);
        for(vector<int>v:trust){
            trusts[v[0]]++;
            trustedBy[v[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(trustedBy[i]==n-1 && trusts[i]==0) return i;
        }
        return -1;
    }
};