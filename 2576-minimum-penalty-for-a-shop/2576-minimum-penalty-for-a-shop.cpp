class Solution {
public:
    int bestClosingTime(string customers) {
        int ans=customers.size(),n=customers.size();
        int cty=0;
        for(auto it:customers){
            if(it=='Y')cty++;
        }
        ans=min(ans,cty);
        int ct=0,j=-1;
        for(int i=0;i<n;i++){
            if(customers[i]=='N'){
                ct++;
            }
            else cty--;
            //cout<<ct<<" "<<cty<<endl;
            if(ans>cty+ct){
                ans=cty+ct;
                j=i;
            }
        }
        if(ans==n)return 0;
        return j+1;
    }
};