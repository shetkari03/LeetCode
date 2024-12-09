class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(); 
        vector<int>arr(n,0);
        for(int i=1;i<n;i++){
            if(nums[i]%2==nums[i-1]%2)arr[i]++;
            arr[i]=arr[i-1]+arr[i];
        }
        vector<bool>ans;
        for(auto q:queries){
            int start=q[0],end=q[1];
            int d=arr[end]-arr[start];
            ans.push_back((d==0));
        }
        return ans;
    }
};