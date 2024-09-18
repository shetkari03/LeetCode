class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end(), [](int a, int b) {
            string t=to_string(a);
            string q=to_string(b);
            if(t+q>q+t)return true;
            return false;
                });
    string ans;
    int ct=0;
        for(auto it:nums){
            if(it!=0)ans+=to_string(it);
            else ct++;
        }
        if(ans=="")return "0";
        while(ct--)ans+="0";
        return ans;
    }
};