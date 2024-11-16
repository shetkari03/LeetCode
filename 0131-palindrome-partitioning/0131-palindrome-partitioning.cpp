class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>>ans;
        vector<string>arr;
        string t;
        solve(s,1,n,t+s[0],1,arr,ans);
        return ans;
    }
    void solve(string s,int i,int n,string t,int ct,vector<string>&arr,vector<vector<string>>&ans){
        if(i==n){
            if(!ispal(t))return;
            if(t.size()>0) arr.push_back(t);
            //cout<<t<<" "<<ct<<endl;
            if(arr[0]!="" && ct==n)ans.push_back(arr);
            if(t.size()>0) arr.pop_back();
            return;
        }
        solve(s,i+1,n,t+s[i],ct+1,arr,ans);
        if(ispal(t)){
            arr.push_back(t);
            //cout<<t<<" ";
            t="";
            solve(s,i+1,n,t+s[i],ct+1,arr,ans);
            arr.pop_back();
        }
    }
    bool ispal(string t){
        int i=0,j=t.size()-1;
        while(i<j)if(t[i++]!=t[j--])return false;
        return true;
    }

};