class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int>mpp;
        for(auto it:arr){
            if(it%2==0 && mpp[it/2]>0)return true;
            if(mpp[it*2]>0 )return true;
            mpp[it]++;
        }
        return false;
    }
};