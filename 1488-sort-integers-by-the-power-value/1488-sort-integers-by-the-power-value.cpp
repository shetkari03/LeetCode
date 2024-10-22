class Solution {
public:
int sol(vector<int>&dp,int i,int hi){
    int d=i;
    if(i%2==0){
        i=i/2;
    }
    else i=i*3+1;
    if(d>hi || i>hi)return 1+sol(dp,i,hi);
    if(i<=hi && dp[i]!=-1){
        dp[d]=1+dp[i];
        return dp[d];
    }
    dp[d]=1+sol(dp,i,hi);
    return dp[d];
}
    int getKth(int lo, int hi, int k) {
        vector<int>dp(hi+1,-1);
        dp[1]=1;
        for(int i=2;i<=hi;i++){
            dp[i]=sol(dp,i,hi);
        //     int ct=0,d=i;
        //     while(1){
        //         if(d<=hi && dp[d]!=-1){
        //             dp[i]=dp[d]+ct;
        //             break;
        //         }
        //         //cout<<d<<" ";
        //         ct++;
        //         if(d%2==0)d=d/2;
        //         else d=d*3+1;
        //     }
        //    // cout<<endl;
        //   // if(dp[i]==-1) dp[i]=ct;
        }
        vector<int>arr;
        for(int i=lo;i<=hi;i++){
            arr.push_back(i);
        }
        int n=arr.size();
        for(int i=0;i<n;i++){
            int j=i;
            while(j>0 && dp[arr[j]]<dp[arr[j-1]]){
                int t=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=t;
                j--; 
            }
        }
        for(auto it:arr)cout<<it<<" "<<dp[it]<<endl;
        return arr[k-1];
    }
};