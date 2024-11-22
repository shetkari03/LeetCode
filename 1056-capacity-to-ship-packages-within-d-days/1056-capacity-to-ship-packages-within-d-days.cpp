class Solution {
public:
bool isValid(vector<int>&arr,int days,int mid){
    int ct=1;
    int sum=0;
    for(auto it:arr){
        if(sum+it>mid){
            ct++;
            sum=it;
        }
        else sum+=it;
    }
    return (ct<=days);
}
    int shipWithinDays(vector<int>& weights, int days) {
        int left=0,right=0,ans=weights.size();
        for(auto it:weights){
            right+=it;
            left=left<it?it:left;
        }
        while(left<=right){
            int mid=(left+right)/2;
            if(isValid(weights,days,mid)){
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};