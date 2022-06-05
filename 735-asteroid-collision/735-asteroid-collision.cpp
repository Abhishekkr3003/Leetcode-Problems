class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>space;
        for(int i=0;i<asteroids.size();i++){
            // cout<<i<<endl;
            if(space.empty()){
                space.push_back(asteroids[i]);
                continue;
            }
            if(asteroids[i]<0){
                while(!space.empty() && space.back()>0 && space.back()<-asteroids[i]) space.pop_back();
                if(!space.empty() && space.back()==-asteroids[i]) space.pop_back();
                else if(space.empty() || space.back()<0) space.push_back(asteroids[i]);
            }else{
                space.push_back(asteroids[i]);
            }   
        }
        return space;
    }
};