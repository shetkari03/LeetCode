class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size(),ans=0;
        vector<int>arr;
        vector<int>hash1(n+1,0);
        for(int i=0;i<n;i++){
            hash1[A[i]]++;
            hash1[B[i]]++;
            if(A[i]==B[i]){
                ans++;
            }
            else{
                if(hash1[B[i]]==2 )ans++;
                if(hash1[A[i]]==2)ans++;
            }
            arr.push_back(ans);
        }
        return arr;
    }
};