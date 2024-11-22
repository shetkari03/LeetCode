class Solution {
public:
bool isValid(vector<int>&piles,int h, long long int mid){
    long long int ct=0;
    long long int sum=0;
    for(auto it:piles){
        ct=ct+it/mid;
        if(it%mid!=0)ct++;
    }
    cout<<" "<<ct<<" ";
    if(ct<=h)return 1;
    return 0;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int sum=0;
        long long int ans=0;
        for(auto it:piles)sum+=it;
        long long int low=1,high=sum;
        while(low<=high){
            long long int mid=(low+high)/2;
            cout<<mid<<" ";
            if(isValid(piles,h,mid)){
                ans=mid;
                cout<<"true"<<endl;
                high=mid-1;
            }
            else{
                cout<<"false"<<endl;
                low=mid+1;
            }
        }
        return ans;
    }
};