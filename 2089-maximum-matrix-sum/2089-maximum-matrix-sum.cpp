class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        long long sum=0;
        int min=INT_MAX,ct=0;
        int col[4]={-1,0,1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0)ct++;
                int d=abs(matrix[i][j]);
                min=min>d?d:min;
                sum+=d;
            }
        }
        if(ct%2==0)return sum;
        return sum-2*min;
    }
};