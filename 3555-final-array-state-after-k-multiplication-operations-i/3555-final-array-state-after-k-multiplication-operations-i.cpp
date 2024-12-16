class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        map<int,int>mpp;
        while(k--){
            auto it=min_element(nums.begin(),nums.end());
            int d=(*it)*multiplier;
            *it=d;
            cout<<*it<<endl;
        }
        return nums;
    }
};