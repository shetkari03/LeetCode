class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        long long maxi1 = 0,maxi2=0; // maximum sum
    long long sum1 = 0,sum2=0;

    for (int i = 0; i < n; i++) {
        int d=-1*nums[i];
        sum1 += nums[i];
        sum2+=d;
        if (sum1 > maxi1) {
            maxi1 = sum1;
        }
        if (sum2 > maxi2) {
            maxi2 = sum2;
        }

        // If sum < 0: discard the sum calculated
        if (sum1 < 0) {
            sum1 = 0;
        }
        if (sum2 < 0) {
            sum2 = 0;
        }
    }
    return maxi1>maxi2?maxi1:maxi2;
    
    }
};