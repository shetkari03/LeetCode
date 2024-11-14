class Solution {
public:
int check(int n,int mid,vector<int>& quantities,int size){
    int i=0,rem=0;
    for(;i<size;i++){
        rem+=quantities[i]/mid;
        if(quantities[i]%mid)rem++;
    }
    //cout<<i<<" ";
    if(rem<=n)return 0;
    return 1;
    
}

    int minimizedMaximum(int n, vector<int>& quantities) {
        int size=quantities.size();
        int low=1,high=0;
        for(int i=0;i<size;i++)high=high>quantities[i]?high:quantities[i];
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            int d=check(n,mid,quantities,size);
            //cout<<mid<<" "<<d<<endl; 
            if(d==0){
                high=mid-1;
                ans=ans>mid?mid:ans;
            }
            else {
                low=mid+1;
            }
        }
        //cout<<low<<" "<<high<<endl;
        return ans;
    }
};