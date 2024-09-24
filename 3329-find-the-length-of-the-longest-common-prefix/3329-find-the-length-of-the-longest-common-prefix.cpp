class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mpp;
        for(auto it:arr1){
            int d=it;
            int f=d,ct=0;
            while(f){
                f=f/10;
                ct++;
            }
            while(d){
                mpp[d]=ct;
                d=d/10;
                ct--;
            }
        }
        int ans=0;
        for(auto it:arr2){
            int d=it;
            while(d){
                ans=ans>mpp[d]?ans:mpp[d];
                d=d/10;
            }
        }
        return ans;
    }
};