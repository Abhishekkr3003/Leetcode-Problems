class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        list<string>words;
        for(int i=0;i<wordList.size();i++){
            // sort(wordList[i].begin(), wordList[i].end());
            if(wordList[i]!=beginWord) words.push_back(wordList[i]);
        }
        q.push(beginWord);
        int dist=0;
        int size=0;
        while(!q.empty()){
            size=q.size();
            dist++;
            for(int i=0;i<size;i++){
                string curWord=q.front();
                q.pop();
                if(curWord==endWord) return dist;
                auto it=words.begin();
                while(it!=words.end()){
                    string temp=*it;
                    
                    int diff=0;
                    for(int j=0;j<curWord.length();j++){
                        if(curWord[j]!=temp[j]) diff++;
                    }
                    
                    // cout<<diff<<endl;
                    if(diff==1){
                        q.push(temp);
                        auto prev=it;
                        it++;
                        words.erase(prev);
                    }else{
                        it++;
                    }
                }
            }
        }
        return 0;
    }
};