class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        // int n=nums.size();
        // int ct=1;
        // vector<int>ans;
        // for(int i=0;i<=n-k;i++){
        //     bool f=true;
        //     for(int j=i+1;j<i+k;j++){
        //         if(nums[j]!=nums[j-1]+1){
        //             ans.push_back(-1);
        //             f=false;
        //             break;
        //         }
        //     }
        //     if(f)ans.push_back(nums[i+k-1]);
        // }
        // return ans;
        vector<int>arr;
        int n=nums.size(),ct=1;
        arr.push_back(1);
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                ct++;
                arr.push_back(ct);
            }
            else {
                ct=1;
                arr.push_back(ct);
            }
        }
        for(int i=0;i+k-1<n;i++){
            int d=arr[i+k-1];
            if(d>=k)arr[i]=nums[i+k-1];
            else arr[i]=-1;
        }
        for(int i=1;i<k;i++)arr.pop_back();
        return arr;
    }
};