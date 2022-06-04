class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo=0, hi=letters.size()-1;
        int mid=0, ans=0;
        
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(letters[mid]>target){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        if(letters[ans]<=target) return letters[0];
        return letters[ans];
    }
};