class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i=0,j=skill.size()-1;
        int prev=skill[i]+skill[j];
        long long ans=0;
        while(i<j){
            long long  d=skill[i]+skill[j];
            long long m=skill[i]*skill[j];
            if(d!=prev)return -1;
            ans+=m;
            i++;
            j--;
        }
        return ans;
    }
};