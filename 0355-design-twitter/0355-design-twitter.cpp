class Twitter {
public:
map<int,vector<pair<int,int>>>feed;
map<int,set<int>>relation;
int p=0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        feed[userId].push_back({p,tweetId});
        // for(auto it:feed){
        //     cout<<it.first<<" feed"<<endl;
        //     for(auto t:it.second)cout<<t.second<<" ";
        //     cout<<endl;
        // }
        p++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        for(auto it:feed[userId])pq.push(it);
        for(auto it:relation[userId]){
            for(auto t:feed[it])pq.push(t);
        }
        vector<int>ans;
        int ct=10;
        while(ct-- && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            
        }
        // cout<<userId<<" getFeed ";
        // for(auto it:ans)cout<<it<<" ";
        // cout<<endl;
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        relation[followerId].insert(followeeId);
        // for(auto it:relation){
        //     cout<<it.first<<" followed by"<<endl;
        //     for(auto t:it.second)cout<<t<<" ";
        //     cout<<endl;
        // }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(relation[followerId].find(followeeId)!=relation[followerId].end()){
            relation[followerId].erase(followeeId);
        }
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