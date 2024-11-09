class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        int n=hand.size();
        sort(hand.begin(),hand.end());
        for(int i=0;i<n;i++){
            if(hand[i]<0)continue;
            int cur=hand[i];
            hand[i]=-1;
            int ct=1;
            int j=0;
            while(j<n && ct<groupSize){
                if(hand[j]==cur+1){
                    cur=hand[j];
                    hand[j]=-1;
                    ct++;
                }
                j++;
            }if(ct<groupSize)return false;
        }
        return true;
        
    }
};