class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        map<string,int>mpp;
        vector<string>temp=folder;
        sort(temp.begin(),temp.end());
        vector<string>ans;
        for(auto it:temp){
            int n=it.size(),f=1;
            string s;
            for(int i=0;i<n;){
                s.push_back(it[i++]);
                while(i<n && it[i]!='/')s.push_back(it[i++]);
                //cout<<s<<" "<<i<<" ";
                if(mpp[s]>0){
                    f=0;
                    break;
                }
            }
            //cout<<f<<endl;
            if(f)mpp[s]=1;
            if(f)ans.push_back(s);
        }
        return ans;
    }
};