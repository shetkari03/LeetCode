class Solution {
public: 
set<int> div(int n){
    set<int>temp;
    //cout<<n<<endl;
    for (int i = 2; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            temp.insert(i); 
            temp.insert(n/i);
           // cout<<i<<" "; 
        } 
    } 
    //cout<<endl;
    
    return temp;
}
    int minOperations(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                set<int>arr=div(nums[i]);
                int ct=0,f=0;
                for (auto rit = arr.rbegin(); rit != arr.rend(); rit++) {
                    int d=nums[i]/(*rit);
                   // cout<<(*rit)<<" ";
                    if(d>nums[i+1])break;
                    ct++;
                    f=d;
                } 
               // cout<<endl;
                if(ct==0)return -1;
                nums[i]=f;
                ans++;
            }
        }
        return ans;
    }
};