class Solution {
public:
bool isValid(vector<int>&nums,int k,long long int  mid){
    int ct=1;
    long long int sum=0;
    for(auto it:nums){
        if(sum+it>mid){
            ct++;
            sum=it;
        }
        else sum+=it;
    }
    return (ct<=k);
}
    int splitArray(vector<int>& nums, int k) {
        long long int left=0,right=0;
        for(auto it:nums){
            left=left<it?it:left;
            right+=it;
        }
        long long int ans=0;
        while(left<=right){
            long long int mid=(left+right)/2;
            if(isValid(nums,k,mid)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};