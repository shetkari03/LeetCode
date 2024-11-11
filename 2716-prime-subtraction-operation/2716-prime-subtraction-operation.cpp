class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int>prime;
        for(int i=2;i<=1000;i++){
            int ct=0;
            for(int j=1;j<=1000;j++)if(i%j==0)ct++;
            if(ct==2)prime.push_back(i);
        }
        int m=prime.size();
        int prev=0;
        for(int i=0;i<nums.size();i++){
            int left=0,right=m-1;
            while(left<=right){
                int mid=(left+right)/2;
                int d=nums[i]-prime[mid];
                if(d>prev)left=mid+1;
                else right=mid-1;
            }
            int a=min(left,right),b=max(left,right);
            if(b>=0 && b<m && nums[i]-prime[b]>prev){
                nums[i]-=prime[b];
            }
            else if(a>=0 && a<m && nums[i]-prime[a]>prev)nums[i]-=prime[a];
            prev=nums[i];
        }
        for(int i=1;i<nums.size();i++)if(nums[i]<=nums[i-1])return false;
        return true;
    }
};