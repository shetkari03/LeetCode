class Solution {
public:
    string compressedString(string word) {
        int size=word.size();
        int ct=1;
        char prev=word[0];
        string ans;
        for(int i=1;i<size;i++){
            if(prev!=word[i]){
                cout<<ct<<endl;
                if(ct>0){string t=to_string(ct);
                for(auto it:t)ans.push_back(it);
                ans.push_back(prev);}
                ct=1;
            }
            else{
                ct++;
                if(ct==9){
                    string t=to_string(ct);
                    for(auto it:t)ans.push_back(it);
                    ans.push_back(prev);
                    ct=0;
                }
            }
            prev=word[i];
        }
        if(ct>0){string t=to_string(ct);
        for(auto it:t)ans.push_back(it);
        ans.push_back(prev);}
                
        return ans;
    }
};