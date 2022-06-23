class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start]==0) return true;
        queue<int>q;
        q.push(start);
        arr[start]=-arr[start];
        
        while(!q.empty()){
            int num=q.front();
            q.pop();
            
            if(num+(arr[num])>=0){
                if(arr[num+arr[num]]==0) return true;
                if(arr[num+arr[num]]>0) {
                    arr[num+arr[num]]*=-1;
                    q.push(num+arr[num]);
                }
            }
            if(num-(arr[num])<arr.size()){
                if(arr[num-arr[num]]==0) return true;
                if(arr[num-arr[num]]>0) {
                    arr[num-arr[num]]*=-1;
                    q.push(num-arr[num]);
                }
            }
        }
        return false;
    }
};