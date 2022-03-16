class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        vector<bool>roomUnlocked(rooms.size());
        for(auto key:rooms[0])
        {
            q.push(key);
        }
        int key;
        int count=1;
        roomUnlocked[0]=true;
        while(!q.empty() && count!=rooms.size())
        {
            key=q.front();
            q.pop();
            if(!roomUnlocked[key])
            {
                count++;
                roomUnlocked[key]=true;
                for(auto nextKey:rooms[key])
                {
                    q.push(nextKey);
                }
            }
        }
        if(count!=rooms.size())
            return false;
        return true;
    }
};