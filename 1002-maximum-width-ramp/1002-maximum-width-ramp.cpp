class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<pair<int,int>>st;
        int ans=0,n=nums.size();
        st.push({nums[0],0});
        for(int i=1;i<n;i++){
            stack<pair<int,int>>temp;
            if(st.empty() || st.top().first>nums[i])st.push({nums[i],i});
            else{
            while(!st.empty() && st.top().first<=nums[i]){
                int t=st.top().first;
                int d=st.top().second;
                ans=ans>i-d?ans:i-d;
                temp.push({t,d});
                st.pop();
            }
            while(!temp.empty()){
                st.push(temp.top());
                temp.pop();
            }
            }

        }
        return ans;
    }
};