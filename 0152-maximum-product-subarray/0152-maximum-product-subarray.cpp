class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long int ans=nums[0],d=nums[0];
        int n=nums.size();
        // int m=INT_MAX,k=INT_MIN;
        // for(auto it:nums){
        //     if(it>=0) m=m>it?it:m;
        // }
        // for(auto it:nums)if(it<0)k=k<it?it:k;
        // k=m;
        // int i=1;
        // cout<<k<<endl;
        // while(i<n){
        //     if(d*nums[i]<=k){
                
        //         ans=max(ans,d);
        //         //continue;
        //         d=nums[i];
        //         i++;
        //         continue;
        //     }
        //     d=d*nums[i];
        //     i++;
        // }
        long long int min=INT_MAX,s=1;
        for(auto it:nums){
            ans=ans>it?ans:it;
          //  min=min>it?it:min;
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                min=INT_MAX;
                s=1;
                continue;
            }
            s=s*nums[i];
            ans=ans>s?ans:s;
            if(min!=0 && min!=INT_MAX)ans=ans>s/min?ans:s/min;
            if(min==INT_MAX && s<0)min=s;
            cout<<ans<<" "<<s<<" "<<min<<endl;
        }
        
        return ans;
    }
};