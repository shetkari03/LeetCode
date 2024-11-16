class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        int ct=1;
        vector<int>ans;
        for(int i=0;i<=n-k;i++){
            bool f=true;
            for(int j=i+1;j<i+k;j++){
                if(nums[j]!=nums[j-1]+1){
                    ans.push_back(-1);
                    f=false;
                    break;
                }
            }
            if(f)ans.push_back(nums[i+k-1]);
        }
        return ans;
    }
};