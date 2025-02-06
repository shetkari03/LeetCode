class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(i==j) continue;
                freq[nums[i] * nums[j]]++;
            }
        }

        for(auto [product,count] : freq) {
            ans += (count * (count-1)) / 2 * 8;
        }

        return ans;
    }
};