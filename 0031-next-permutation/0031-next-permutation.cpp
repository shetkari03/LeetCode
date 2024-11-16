class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1,n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int ind=0;
        for(int i=n-1;i>=index;i--){
            if(nums[i]>nums[index] ){
                ind=i;
                break;
            }
        }
        int temp=nums[index];
        nums[index]=nums[ind];
        nums[ind]=temp;
        sort(nums.begin()+index+1,nums.end());
    }
};