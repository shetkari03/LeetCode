class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp(arr.size(),0);
        int i=0;
        map<int,vector<int>>mpp;
        for(auto it:arr){
            mpp[it].push_back(i);
            i++;
        }
        i=1;
        for(auto it:mpp){
            for(auto t:it.second){
                temp[t]=i;
            }
            i++;
        }
        return temp;
    }
};