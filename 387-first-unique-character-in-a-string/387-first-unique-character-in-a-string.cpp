class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26];
        memset(arr, -1, sizeof(arr));
        for(int i=0;i<s.length();i++){
            if(arr[s[i]-97]==-1)
                arr[s[i]-97]=i;
            else
                arr[s[i]-97]=-2;
        }
        int ans=INT_MAX;
        for(int i=0;i<26;i++){
            // cout<<arr[i]<<endl;
            if(arr[i]!=-1 && arr[i]!=-2 && arr[i]<ans){
                ans=arr[i];
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};