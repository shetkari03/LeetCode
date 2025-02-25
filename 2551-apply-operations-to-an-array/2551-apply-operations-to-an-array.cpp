class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int>ans;
        int cur=nums[0];
        for(int i=0;i<nums.size()-1;i++){
            if(cur==nums[i+1]){
                if(cur)ans.push_back(cur*2);
                cur=0;
            }
            else{
                if(cur)ans.push_back(cur);
                cur=nums[i+1];
            }
        }
        if(cur)ans.push_back(cur);
        int m=nums.size()-ans.size();
        cout<<m;
        while(m--)ans.push_back(0);
        return ans;
    }
};