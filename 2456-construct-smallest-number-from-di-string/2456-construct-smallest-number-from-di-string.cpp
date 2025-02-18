class Solution {
public:
    string smallestNumber(string pattern) {
        vector<int>arr={1,2,3,4,5,6,7,8,9};
        int n=pattern.size();
        //for(int i=1;i<=n+1;i++)arr.push_back(i);
        while(1){
            bool f=true;
            for(int i=0;i<n;i++){
                if(pattern[i]=='I' && arr[i]>arr[i+1])f=false;
                if(pattern[i]=='D' && arr[i]<arr[i+1])f=false;
            }
            if(f){
                string ans;
                for(int i=0;i<=n;i++){
                    ans.push_back(arr[i]+'0');
                }
                return ans;
            }
                next_permutation(arr.begin(),arr.end());
        }
        return "";
    }
};