class Solution {
    int cycleSize;
    int cycles;
    bool findCycle(vector<int>graph[], vector<bool>&visited, vector<bool>&inStack, int node,vector<int>&stack_){
        visited[node]=true;
        inStack[node]=true;
        stack_.push_back(node);
        for(int nbr:graph[node]){
            // cout<<nbr<<endl;
            if(!visited[nbr]) {
                if(findCycle(graph,visited,inStack,nbr,stack_)) return true;
            }
            else if(visited[nbr] && inStack[nbr]){
                // cout<<"here";
                cycleSize=(int)stack_.size();
                cycles++;
                return true;
            }
        }
        inStack[node]=false;
        stack_.pop_back();
        return false;
    }
    
    int findMore(int node, vector<bool>&inStack, vector<int>graph[]){
        // if(inStack[node]){
        //     int size=0;
        //     for(auto nbr:graph[node]){
        //         if(inStack[nbr]==false){
        //             size=max(size, 1+findMore(nbr,inStack,graph));
        //         }
        //      }
        //      return size;
        // }
        // for(auto nbr:graph[node]){
        //     if(inStack[nbr]==false){
        //         return graph[node].size()+findMore(nbr,inStack,graph);
        //     }
        // }
        // return 0;
        int size=0;
        for(auto nbr:graph[node]){
            if(inStack[nbr]==false){
                size=max(size, 1+findMore(nbr,inStack,graph));
            }
         }
         return size;
    }
    
public:
    int maximumInvitations(vector<int>& f) {
        cycleSize=0;
        cycles=0;
        vector<int>graph[f.size()];
        for(int i=0;i<f.size();i++) graph[f[i]].push_back(i);
        vector<bool>visited(f.size(),false);
        vector<bool>inStack(f.size(),false);
        vector<int>stack_;
        int cycle=0;
        int res=0;
        int temp=0;
        for(int i=0;i<f.size();i++){
            if(!visited[i]) {
                if(findCycle(graph,visited,inStack,i,stack_)){
                    if(cycleSize==2){
                        temp+=findMore(stack_[0], inStack,graph);
                        temp+=findMore(stack_[1], inStack,graph);
                        temp+=cycleSize;
                        res=max(res,temp);
                    }else{
                        res=max(cycleSize,res);
                    }
                    
                }
            }
            inStack.clear();
            stack_.clear();
        }
        return res;
        
    }
};