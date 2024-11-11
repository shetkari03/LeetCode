class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<bool>prime(1001,false);
        for(int i=2;i<=1000;i++){
            int ct=0;
            for(int j=1;j<=1000;j++)if(i%j==0)ct++;
            if(ct==2)prime[i]=true;
        }
        int prev=-1;
        for(int i=0;i<nums.size();i++){
            int d=0;
            for(int j=2;j<nums[i];j++){
                if(prime[j]==true && nums[i]-j>prev)d=j;
            }
            nums[i]=nums[i]-d;
            prev=nums[i];
        }
        for(int i=1;i<nums.size();i++)if(nums[i]<=nums[i-1])return false;
        return true;
    }
};