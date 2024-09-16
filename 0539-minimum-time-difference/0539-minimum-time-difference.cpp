class Solution {
public:
    int findMinDifference(vector<string>& time) {
        bool flag=0,l=0;
        for(auto it:time){
            if(it=="00:00")flag=1;
            if(it=="24:00")l=1;
        }
        //if(flag==0 && l==1)time.push_back("00:00");
        //if(flag==1 && l==0)time.push_back("24:00");
        sort(time.begin(),time.end());
        int ans=24*60;
        int n=time.size();
        int k=24*60;
        int prev=(time[0][0]-'0')*10+(time[0][1]-'0');
        prev=prev*60;
        prev+=(time[0][3]-'0')*10+(time[0][4]-'0');
        int d=(time[n-1][0]-'0')*10+(time[n-1][1]-'0');
            d=d*60;
            d+=(time[n-1][3]-'0')*10+(time[n-1][4]-'0');
            if(d==prev)return 0;
            if(d==0){
                ans=min(ans,abs(k-prev));
                ans=min(ans,abs(prev-0));
            }
            if(prev==0){
                ans=min(ans,abs(k-d));
                ans=min(ans,abs(d-0));
            }
            ans=min(ans,abs(k-d+prev));
            ans=min(ans,abs(k+d-prev));
            ans=min(ans,abs(prev-d));
            cout<<prev<<" "<<d<<endl;
        for(int i=1;i<n;i++){
             d=(time[i][0]-'0')*10+(time[i][1]-'0');
            d=d*60;
            d+=(time[i][3]-'0')*10+(time[i][4]-'0');
            if(d==prev)return 0;
            if(d==0){
                ans=min(ans,abs(k-prev));
                ans=min(ans,abs(prev-0));
            }
            if(prev==0){
                ans=min(ans,abs(k-d));
                ans=min(ans,abs(d-0));
            }
            ans=min(ans,abs(prev-d));
            ans=min(ans,abs(k-d+prev));
            ans=min(ans,abs(k+d-prev));
            cout<<prev<<" "<<d<<endl;
            prev=d;
        }
        return ans;
    }
};