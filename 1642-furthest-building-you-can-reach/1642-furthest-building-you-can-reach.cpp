class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>>q;
        
        for(int i=0;i<heights.size()-1;i++){
            if(heights[i+1]<=heights[i]) continue;
            if(ladders){
                ladders--;
                q.push(heights[i+1]-heights[i]);
            }else{
                if(!q.empty() && q.top()<heights[i+1]-heights[i]){
                    q.push(heights[i+1]-heights[i]);
                    bricks-=q.top();
                    if(bricks<0) return i;
                    q.pop();
                }else{
                    bricks-=heights[i+1]-heights[i];
                    if(bricks<0) return i;
                }
            }
        }
        return heights.size()-1;
    }
};