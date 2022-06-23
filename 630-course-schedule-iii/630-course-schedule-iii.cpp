

class Solution {
    
    class Comp{
    public:
        bool operator()(vector<int>&a, vector<int>&b){
            if(a[1]==b[1]) return a[0]<b[0];
            return a[1]<b[1];
        }
    };
    
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(), Comp());
        priority_queue<int>q;
        
        int endTime=0;
        
        for(auto course:courses){
            if(course[0]<=course[1]){
                if(q.empty() || endTime+course[0]<=course[1]) {
                    q.push(course[0]);
                    endTime+=course[0];
                }
                else if(course[0]<q.top()){
                    endTime+=course[0]-q.top();
                    q.pop();
                    q.push(course[0]);
                }
            }
            
        }
        return q.size();
    }
};