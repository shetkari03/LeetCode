class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int preve=ratings[0],ct=1,prev=1;
        int ans=1;
        int inc=0,dec=0;
        // for(int i=1;i<n;i++){
        //     if(preve==ratings[i]){
        //         prev=1;
        //         ct=1;
        //         ans++;
        //         dec=0;
        //         inc=0;
        //     }
        //     if(preve>ratings[i]){
        //         prev--;
        //         if(inc>0)ct=1;
        //         if(prev==0){
        //             ans+=ct;
        //             prev++;
        //             ans++;
        //             ct++;
        //         }
        //         else{
        //             ans+=prev;
        //             ct++;
        //         }
        //         dec++;
        //         inc=0;
        //     }
        //     if(preve<ratings[i]){
        //         if(dec>0){
        //             int d=prev-1;
        //             ans-=(ct-1)*d;
        //             prev=1;
        //             ct=0;
        //         }
        //         ct++;
        //         prev++;
        //         ans+=prev;
        //         inc++;
        //         dec=0;
        //     }
        //     preve=ratings[i];
        // }
        // cout<<ans<<" "<<inc<<" "<<dec<<" "<<prev<<endl;
        //   if(dec>0 && prev>1){
        //             int d=prev-1;
        //             ans-=(ct-1)*d;
        //             prev=1;
        //         }
        ans=0;
        vector<int>arr(n,1);
        for(int i=1;i<n;i++)if(ratings[i]>ratings[i-1])arr[i]=arr[i-1]+1;
        for(int i=n-2;i>=0;i--)if(ratings[i]>ratings[i+1])arr[i]=arr[i+1]+1>arr[i]?arr[i+1]+1:arr[i];
        for(auto it:arr){
            ans+=it;
            cout<<it<<" ";
        }
        return ans;
    }
};