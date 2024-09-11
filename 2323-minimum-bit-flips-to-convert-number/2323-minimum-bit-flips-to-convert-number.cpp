class Solution {
public:
    int minBitFlips(int start, int goal) {
        if(start<goal)return minBitFlips(goal,start);
        int ct=0;
        while(start>0 && goal>0){
            if(start%2!=goal%2)ct++;
            start=start/2;
            goal=goal/2;
        }
        while(start>0){
           if(start%2!=0) ct++;
            start=start/2;
        }
        return ct;                 
    }
};