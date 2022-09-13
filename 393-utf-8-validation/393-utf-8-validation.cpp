class Solution {
    bool check10(int count, int i, vector<int>&data){
        while(count-- && i<data.size()){
            if(!((data[i]&(1<<7)) && (data[i]&(1<<6))==0)) {
                // cout<<"here\n";
                return false;
            }
            i++;
        }
        return count<0;
    }
    
public:
    bool validUtf8(vector<int>& data) {
        for(int i=0;i<data.size();i++){
            if((data[i]&(1<<7))==0) continue;
            else{
                int k=6;
                while(k>=0 && ((data[i]&(1<<k)))) k--;
                if(k==6) return false;
                int count=6-k;
                if(count>3) return false;
                // cout<<count<<endl;
                if(!check10(count,i+1,data)) return false;
                // cout<<"here";
                i+=count;                
            }
        }
        
        return true;
    }
};