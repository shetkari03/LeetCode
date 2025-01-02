class Solution {
public:
bool isVowel(char ch){
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;
    return false;
}
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>hash(n+1,0);
        for(int i=0;i<n;i++){
            int m=words[i].size();
            if(isVowel(words[i][0]) && isVowel(words[i][m-1]))hash[i+1]++;
            hash[i+1]+=hash[i];
        }
        vector<int>ans;
        for(auto it:queries){
            int l=it[0],r=it[1];
            ans.push_back(hash[r+1]-hash[l]);
        }
        return ans;
    }
};