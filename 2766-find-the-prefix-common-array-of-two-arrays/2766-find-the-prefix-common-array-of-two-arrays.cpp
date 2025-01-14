class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size(),ans=0;
        vector<int>arr;
        vector<int>hash1(n+1,0),hash2(n+1,0);
        for(int i=0;i<n;i++){
            if(A[i]==B[i]){
                ans++;
                hash1[A[i]]++;
                hash2[B[i]]++;
            }
            else{
                if(hash1[B[i]])ans++;
                if(hash2[A[i]])ans++;
                hash1[A[i]]++;
                hash2[B[i]]++;
            }
            arr.push_back(ans);
        }
        return arr;
    }
};