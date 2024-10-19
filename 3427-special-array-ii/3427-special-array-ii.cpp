class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        //map<int,int>mpp;
        int ct=0,n=nums.size();
        vector<int>mpp(n,0);
        for(int i=1;i<n;i++){
            if(nums[i]%2==nums[i-1]%2){
                ct++;
            }
            mpp[i]=ct;
        }
        vector<bool>ans;
        for(auto it:queries){
            int i=it[0],j=it[1];
            if(mpp[i]==mpp[j])ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};