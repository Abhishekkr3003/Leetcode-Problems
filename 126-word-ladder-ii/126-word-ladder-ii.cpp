class Solution {
    vector<string> words;
    vector<vector<string>> res;
    
    void bfs(vector<int> graph[], int root, int target, int graphSize) {
        
        queue<vector<int>> q;
        q.push({root});
        int size = 0;
        bool stop=false;
        bool visited[1002] = {0};
        
        visited[root] = 1;
        
        while (!q.empty() && !stop) {
            size = q.size();
            for (int i = 0; i < size; i++) {
                vector<int> nodeList = q.front();
                // cout<<words[nodeList.back()]<<" ";
                visited[nodeList.back()] = true;
                q.pop();
                // if(nodeList.back()==target) {
                //     vector<string>temp(nodeList.size());
                //     for(int j=0;j<nodeList.size();j++) temp[j]=words[nodeList[j]];
                //     res.push_back(temp);
                //     stop=true;
                //     continue;
                // }
                for (int nbr : graph[nodeList.back()]) {
                    if(nbr==target){
                        nodeList.push_back(nbr);
                        vector<string>temp(nodeList.size());
                        for(int j=0;j<nodeList.size();j++) 
                            temp[j]=words[nodeList[j]];
                        res.push_back(temp);
                        stop=true;
                        break;
                    }
                    if (!visited[nbr]) {   
                        
                        nodeList.push_back(nbr);
                        q.push(nodeList);
                        nodeList.pop_back();
                    }
                }
            }
        }
    }

    // void dfs(vector<int> graph[], int root, int target, int dist, vector<string> &cur, vector<bool>&visited) {
    //     cout<<dist<<" ";
    //     cout<<words[root]<<endl;
    //     if (dist <= 0) return;
    //     dist--;
    //     for (int nbr : graph[root]) {
    //         if(!visited[nbr]){
    //             if(dist==0){
    //                 if(nbr==target){
    //                     cur.push_back(words[nbr]);
    //                     res.push_back(cur);
    //                     cur.pop_back();
    //                 }
    //                 return;
    //             }else{
    //                 cur.push_back(words[nbr]);
    //                 visited[nbr]=true;
    //                 dfs(graph, nbr, target, dist, cur,visited);
    //                 cur.pop_back();
    //                 // visited[nbr]=false;
    //             }
    //         }
    //     }
    // }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        int beginWordIndex = -1, endWordIndex = -1;
        // cout<<wordList.size()<<endl;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == beginWord)
                beginWordIndex = i;
            else if (wordList[i] == endWord)
                endWordIndex = i;
        }
        if (endWordIndex == -1) return (vector<vector<string>>){};
        if (beginWordIndex == -1) {
            beginWordIndex = wordList.size();
            wordList.push_back(beginWord);
        }
        int n=beginWord.length();
        vector<int> graph[wordList.size() + 2];
        for (int i = 0; i < wordList.size() - 1; i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                int diff = 0;
                for (int k = 0; k < n; k++) {
                    if(wordList[i][k]!=wordList[j][k]) diff++;
                }
                // cout<<diff<<endl;
                if (diff == 1) {
                    // cout<<i<<" "<<j<<endl;
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        this->words = wordList;
        // for(int num:graph[beginWordIndex]) cout<<wordList[num]<<" ";
        // cout<<endl;
        bfs(graph, beginWordIndex, endWordIndex, wordList.size());
        // if(dist==-1) return res;
        // cout<<dist<<" "<<beginWordIndex<<" "<<endWordIndex<<endl;
        // vector<string> cur;
        // cur.push_back(wordList[beginWordIndex]);
        // vector<bool>visited(wordList.size(),false);
        // visited[beginWordIndex]==1;
        // dfs(graph, beginWordIndex, endWordIndex, dist, cur,visited);
        return res;
    }
};