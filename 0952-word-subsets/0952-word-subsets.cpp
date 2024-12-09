class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int hash[26]={0};
        for(auto it:words2){
            int temp[26]={0};
            for(auto s:it)temp[s-'a']++;
            for(int i=0;i<26;i++)hash[i]=max(hash[i],temp[i]);
        }
        vector<string>ans;
        for(auto it:words1){
            int temp[26]={0};
            for(auto s:it)temp[s-'a']++;
            bool f=true;
            for(int i=0;i<26;i++){
                if(temp[i]<hash[i])f=false;
            }
            if(f)ans.push_back(it);
        }
        return ans;
    }
};