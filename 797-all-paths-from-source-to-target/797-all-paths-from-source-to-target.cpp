
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* 
    Time: O(n*2^n)
    Space: O(n*2^n)
    Tag: DFS, Backtracking
    Difficulty: E
*/

class Solution {

    void dfs(vector<vector<int>>&graph, vector<vector<int>>&res, vector<int>curPath, int curNode){
        curPath.push_back(curNode);
        if(curNode==graph.size()-1){ res.push_back(curPath); return; }
        for(int nbr:graph[curNode]){
            dfs(graph,res,curPath,nbr);
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        vector<int>curPath;
        dfs(graph,res,curPath,0);
        return res;
    }
};