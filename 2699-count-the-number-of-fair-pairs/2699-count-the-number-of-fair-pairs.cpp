class Solution {
public:
    long long countFairPairs(vector<int>& arr, int lower, int upper) {
       // vector<int>arr=nums;
        sort(arr.begin(),arr.end());
        long long int ans=0;
        for(int j=0;j<arr.size();j++){
            int low=0,high=j-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(arr[mid]+arr[j]<lower)low=mid+1;
                else high=mid-1;
            }
            int x=low;
            low=0;high=j-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(arr[mid]+arr[j]>upper)high=mid-1;
                else low=mid+1;
            }
            ans=ans+abs(low-x);
        }
        return ans;
    }
};