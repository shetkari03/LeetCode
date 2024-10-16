class Solution {
public:
void sol(map<char,int>&mpp,int a,int b,int c){
    vector<pair<int,char>>st;
    st.push_back({a,'a'});st.push_back({b,'b'});st.push_back({c,'c'});
    sort(st.begin(),st.end());
    for(int i=2;i>=0;i--){
        mpp[st[i].second]=i;
    }
}
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,int >>pq;
        map<char,int>mpp;
        map<int,char>mp;
        sol(mpp,a,b,c);
        for(auto it:mpp)mp[it.second]=it.first;
        string ans;
        if(a>0)pq.push({a,mpp['a']});
        if(b>0)pq.push({b,mpp['b']});
        if(c>0)pq.push({c,mpp['c']});
        while(!pq.empty()){
            int d=pq.top().first;
            int  ch=pq.top().second;
            pq.pop();
            if(pq.empty()){
                if(d>=1){ans.push_back(mp[ch]);
                d--;
                if(d>=1)ans.push_back(mp[ch]);
                return ans;}
            }
            int p=pq.top().first;
            int q=pq.top().second;
            pq.pop();
            cout<<d<<" "<<ch<<"  "<<p<<" "<<q<<endl;
            if(d>p){
                ans.push_back(mp[ch]);
                d--;
                if(d>=1){
                    ans.push_back(mp[ch]);
                    d--;
                }
                ans.push_back(mp[q]);
                p--;
            }
            else{
                ans.push_back(mp[ch]);
                d--;
                if(d>=1){
                    ans.push_back(mp[ch]);
                    d--;
                }
                ans.push_back(mp[q]);
                p--;
                if(p>=1){
                    ans.push_back(mp[q]);
                    p--;
                }
            }
            if(d>0)pq.push({d,ch});
            if(p>0)pq.push({p,q});
        }
        return ans;
    }
};