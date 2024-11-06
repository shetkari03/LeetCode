class Solution {
public:
int countSetBits(int n) {
    int count = 0;
  
    // Runs till n becomes 0
    while (n) {

      	// Turn off/reset the rightmost set bit
        n &= (n - 1);

      	// Increment the count of set bits
        count++;
    }
    return count;
}
void swap(int &a,int &b){
    a=a^b;
    b=b^a;
    a=a^b;
}
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                if(nums[j]<nums[j-1] && countSetBits(nums[j])==countSetBits(nums[j-1])){
                    swap(nums[j],nums[j-1]);
                }
                if(nums[j]<nums[j-1] && countSetBits(nums[j])!=countSetBits(nums[j-1])){
                    return 0;
                }
                
            }
        }for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1])return 0;
        }
        return 1;
    }
};