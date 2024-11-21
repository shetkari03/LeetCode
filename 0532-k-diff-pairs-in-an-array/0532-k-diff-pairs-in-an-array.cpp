class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size()==1)return 0;
        map<int,int>mpp;
        int n=nums.size(),ct=0;
        for(auto it:nums){
            mpp[it]++;
            if(mpp[it]==2)ct++;
        }
        cout<<ct<<endl;
        if(k==0){
            return ct;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(mpp[nums[i]]==0)continue;
            int d=nums[i]+k;
            if(mpp[d]!=0)ans++;
            d=nums[i]-k;
            if(mpp[d]!=0)ans++;
            mpp[nums[i]]=0;
        }
        return ans;
    }
};