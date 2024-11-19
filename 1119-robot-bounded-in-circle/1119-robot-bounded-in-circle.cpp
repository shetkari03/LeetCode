class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0,y=0;
        int d=1;
        for(auto it:instructions){
            if(it=='G'){
                if(d==1)y++;
                else if(d==2)x++;
                else if(d==4)x--;
                else y--;
            }
            else if(it=='L'){
                if(d==1)d=5;
                d--;
            }
            else{
                if(d==4)d=0;
                d++;
            }
        }
        cout<<d<<endl;
        if(d==1 && (x!=0 || y!=0))return false;
        return true;
    }
};