class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
    map<string,int>mpp;
    for(auto s:words){
         int n = s.length(); 
    
  for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
          
            // Print the substring from index i to j
            mpp[ s.substr(i, j - i)]++;
        }
    }
    }
    vector<string>ans;
    for(auto it:words)if(mpp[it]>=2)ans.push_back(it);
    return ans;
    }
};