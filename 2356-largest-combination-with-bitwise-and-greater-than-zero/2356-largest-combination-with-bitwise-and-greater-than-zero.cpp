class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int>hash(30,0);
        for(auto it:candidates){
            int d=it,ct=0;
            while(d){
                if(d%2!=0)hash[ct]++;
                ct++;
                d=d/2;
            }
        }
        int ans=1;
        for(int i=0;i<30;i++){
            ans=ans>hash[i]?ans:hash[i];
        }
        return ans;
    }
};