class Solution {
public:
    vector<int> constructRectangle(int area) {
        int l=area,b=1;
        for(int i=1;i<=area;i++){
            if(area%i==0){
                if(abs(area/i-i)<abs(l-b)){
                    l=max(area/i,i);
                    b=min(area/i,i);
                }
            }
        }
        return {l,b};
    }
};