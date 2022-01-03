class Solution {
public:
    string reorganizeString(string s) {
        vector<int>count(26,0);
        for(char ch:s) count[ch-'a']++;
        priority_queue<pair<int,char>>maxHeap;
        for(int i=0;i<26;i++){
            if(count[i]>0) maxHeap.push({count[i],('a'+i)});
        }
        int maxFreq=maxHeap.top().first;
        char maxFreqChar=maxHeap.top().second;
        maxHeap.pop();
        int charLeft=s.length()-maxFreq;
        
        if(charLeft<maxFreq-1) return "";
        vector<string>temp(maxFreq);
        for(int i=0;i<maxFreq;i++){
            temp[i]+=maxFreqChar;
        }
        int i=0;
        while(!maxHeap.empty()){
            int freq=maxHeap.top().first;
            maxFreqChar=maxHeap.top().second;
            maxHeap.pop();
            while(freq--) {
                temp[i]+=maxFreqChar;
                i=(i+1)%maxFreq;
            }
        }
        string res="";
        for(int i=0;i<maxFreq;i++){
            res+=temp[i];
        }
        return res;
    }
};