class Solution {
public:
    void rotate(vector<int>& nums, int k){ 
        int n=nums.size();
        k=k%n;
        if(k==0) return;
        int temp,valueToSwitch=nums[0], i=0, targetI=(i+k)%n;
        int maxRot=nums.size();
        // int count=0;
        int start=0;
        while(maxRot--){
            // count++;
            temp=nums[targetI];
            nums[targetI]=valueToSwitch;
            valueToSwitch=temp;
            i=targetI;
            targetI=(i+k)%n;
            if(start==i){
                // cout<<count<<endl;
                start++;
                i++;
                valueToSwitch=nums[i];
                targetI=(i+k)%n;
            }
        }
    }
};