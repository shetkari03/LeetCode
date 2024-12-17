class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int hash[26]={0};
        for(auto it:s)hash[it-'a']++;
        priority_queue<char>pq;
        for(int i=0;i<26;i++){
            if(hash[i]>0)pq.push(i+'a');
        }
        string ans;
        while(!pq.empty()){
            char ch=pq.top();pq.pop();
            int d=hash[ch-'a'];
            for(int i=1;i<=min(d,repeatLimit);i++)ans.push_back(ch);
            if(d>repeatLimit){
                if(pq.empty())break;
                char q=pq.top();pq.pop();
                ans.push_back(q);
                hash[q-'a']--;
                if(hash[q-'a']>0)pq.push(q);
            }
            d=max(0,d-repeatLimit);
            hash[ch-'a']=d;
            if(d>0)pq.push(ch);
        }
        return ans;
    }
};