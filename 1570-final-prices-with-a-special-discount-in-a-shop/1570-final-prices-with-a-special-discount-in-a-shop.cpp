class Solution {
public:
    vector<int> finalPrices(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>ans=nums;
        for(int i=n-1;i>=0;i--){
            int d=nums[i];
            while(!st.empty() && st.top()>d)st.pop();
            if(!st.empty())d=d-st.top();
            ans[i]=d;
            st.push(nums[i]);
        }
        return ans;
    }
};