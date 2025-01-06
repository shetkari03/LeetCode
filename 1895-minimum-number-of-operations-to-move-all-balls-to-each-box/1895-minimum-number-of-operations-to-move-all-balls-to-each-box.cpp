class Solution {
public:
    vector<int> minOperations(string boxes) {
    int n=boxes.size(),c=0,op=0;
    vector<int> res(n); 
    //this loop is for no. of operations for the no. of ones before the current index.
    for (int i=0;i<n;i++) {  
       res[i] += op;
       if(boxes[i]=='1'){c++;}
       op+=c;
    }
    //this loop is for no. of operations for the no. of ones after the current index.
    c=0;op=0;
    for (int i=n-1;i>=0;i--) {
       res[i]+=op;
       if(boxes[i]=='1'){c++;}
       op+=c;
    }
    return res;
    }
};