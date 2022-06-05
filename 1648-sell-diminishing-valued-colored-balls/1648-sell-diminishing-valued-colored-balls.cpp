class Solution { 
    
    long long sumUpto(long long n){
        return (n*(n+1))/2;
    }
    
public:
    int maxProfit(vector<int>& inventory, int orders) {
        priority_queue<pair<int,int>>q;
        q.push({0,0});
        for(int i=0;i<inventory.size();i++){
            q.push({inventory[i],1});
        }
        
        int res=0;
        
        while(orders){
            long long maxEle=q.top().first;
            long long maxEleFreq=q.top().second;
            q.pop();
            while(q.top().first==maxEle) {
                maxEleFreq+=q.top().second;
                q.pop();
            }
            int secondMax=0;
            secondMax=q.top().first;
            int mod=1e9+7;
            if(orders>=(maxEle-secondMax)*maxEleFreq){
                res=(res+maxEleFreq*(sumUpto(maxEle)-sumUpto(secondMax)))%mod;
                int secondMaxFreq=q.top().second; q.pop();
                q.push({secondMax, secondMaxFreq+maxEleFreq});
                orders-=(maxEle-secondMax)*maxEleFreq;
            }else{
                int fullCount=orders/maxEleFreq;
                res=(res+maxEleFreq*(sumUpto(maxEle)-sumUpto(maxEle-fullCount)))%mod;
                res=(res+(maxEle-fullCount)*(orders%maxEleFreq))%mod;    
                break;
            }
        }
        return res;
    }
};