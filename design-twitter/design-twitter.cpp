class Twitter {
    unordered_map<int,unordered_set<int>>iFollows;
    unordered_map<int,deque<pair<int,int>>>tweetsOf;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minHeap;
    int time;
public:
    Twitter() {
        iFollows.clear();
        tweetsOf.clear();
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        // cout<<"post";
        tweetsOf[userId].push_back({++time,tweetId});
        if(tweetsOf[userId].size()>10) tweetsOf[userId].pop_front(); 
    }
    
    vector<int> getNewsFeed(int userId) {
        // cout<<"get";
        for(auto p:tweetsOf[userId]){
            minHeap.push(p);
        }
        for(auto followee:iFollows[userId]){
            for(auto p:tweetsOf[followee]){
                minHeap.push(p);
                if(minHeap.size()>10) minHeap.pop();
            }
        }
        vector<int>feed(minHeap.size());
        for(int i=minHeap.size()-1;i>=0;i--){
            feed[i]=minHeap.top().second;
            minHeap.pop();
        }      
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        // cout<<"follow";
        iFollows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // cout<<"unfollow";
        iFollows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */