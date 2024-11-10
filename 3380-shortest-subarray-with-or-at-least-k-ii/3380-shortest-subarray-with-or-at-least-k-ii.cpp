class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        long long int n=nums.size(),a=0;
        int hash[100]={0};
        long long int ans=n+2,left=0,right=0;
        while(right<n){
            a|=nums[right];
            long long int d=nums[right],i=0;
            while(d){
                if(d%2!=0)hash[i]++;
                i++;
                d=d/2;
            }
            while(left<right && a>=k){
                ans=ans<right-left+1?ans:right-left+1;
                d=nums[left];i=0;
                long long int p=0,q=1;
                while(d){
                    if(d%2!=0){
                        hash[i]--;
                        if(hash[i]==0)p=p+q;
                    }
                    d=d/2;i++;q=q*2;
                }
                a=a^p;
                left++;
            }
            if(a>=k)ans=ans<right-left+1?ans:right-left+1;
            right++;
        } 
        if(ans==n+2)return -1;
        return ans;
    }
};