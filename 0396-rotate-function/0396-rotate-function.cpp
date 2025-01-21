class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long int sum=0,sum1=0;
        int d=0;
        for(auto it:nums){
            sum+=it;
            sum1+=d*it;
            d++;
        }
        //d=0;
        d--;
        long long int  sum2=0,sum3=0,ans=sum1;
        for(int i=nums.size()-1;i>=0;i--){
            sum-=nums[i];
            sum1-=nums[i]*d;
            sum1+=sum;
            sum3+=sum2;
            ans=max(ans,sum1+sum3);
            sum2+=nums[i];
        }
        return ans;
    }
};