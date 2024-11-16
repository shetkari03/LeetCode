class Solution {
 void nextPermutation(vector<int>& nums) {
        int index1=0,index2=0,n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                index1=i;
                index2=i+1;
            }
        }
        if(index1==0 && index2==0){
            reverse(nums.begin(),nums.end());
            return;
        }
        int nextele=INT_MAX,ind=0;
        for(int i=index2;i<n;i++){
            if(nums[i]>nums[index1] && nums[i]<nextele){
                ind=i;
                nextele=nums[i];
            }
        }
        int temp=nums[index1];
        nums[index1]=nums[ind];
        nums[ind]=temp;
        sort(nums.begin()+index1+1,nums.end());
    }
int fact(int n){
    if(n==0 || n==1)return 1;
    return n*fact(n-1);
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int m=fact(n);
        vector<vector<int>>ans;
        ans.push_back(nums);
        if(n==1)return ans;
        for(int i=2;i<=m;i++){
            nextPermutation(nums);
            ans.push_back(nums);
        }
        return ans;

    }
};