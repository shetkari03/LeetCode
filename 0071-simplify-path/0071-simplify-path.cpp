class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        vector<string>arr;
        for(int i=0;i<n;i++){
            if(i<n-1 && path[i+1]=='/')continue;
            string t="/";
            //  if(i<n)cout<<path[i]<<endl;
           i++;
            while(i<n && path[i]!='/'){
                t+=path[i];
                i++;
            }
            i--;
            // if(i<n)cout<<path[i]<<endl;
            cout<<t<<endl;
            if(t=="/.." ){
                if(arr.size()>0)arr.pop_back();
            }
            else if(t!="/." && t!="/") arr.push_back(t);
        }
        string ans;
        for(auto it:arr)ans+=it;
        if(ans.size()==0)return "/";
        return ans;
    }
};