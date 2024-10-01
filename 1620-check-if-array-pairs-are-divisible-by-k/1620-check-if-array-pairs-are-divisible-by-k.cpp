class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>mpp(k,0);
        for(auto it:arr)mpp[((it%k)+k)%k]++;
        if(mpp[0]%2!=0)return 0;
        int i=1,j=k-1;
        while(i<=j){
            if(i==j){
                if(mpp[i]%2!=0)return 0;
            }
            else if(mpp[i]!=mpp[j])return 0;
            i++;
            j--;
        }
        return 1;
        
    }
};