class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int ct=0,one=0,zero=0;
        bool ans=1;
        for(auto it:bits){
            if(ct==0 && it==0){
                ans=1;
                continue;
            }
            if(it==1)one++;
            else zero++;
            ct++;
            if(ct==2){
                ct=0;
                zero=0;
                if(one>0)ans=0;
                else ans=1;
                one=0;
            }
        }
        if(ct>0){
            if(one>0)ans=0;
            else ans=1;
        }
        return ans;
    }
};