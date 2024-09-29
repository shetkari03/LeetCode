class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n=word.size(),ans=0;
        for(int i=0;i<n;i++){
            map<char,int>mpp;
            int vow=0,con=0;
            for(int j=i;j<n;j++){
                if(word[j]=='a' || word[j]=='e' || word[j]=='i' || word[j]=='o' || word[j]=='u'){
                    mpp[word[j]]++;
                }
                else con++;
                if(con==k && mpp.size()==5)ans++;
                if(con>k)break;
            }
            //cout<<i<<" "<<con<<" "<<vow<<endl;
        }
        return ans;
    }
};