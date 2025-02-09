class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp;
        int n=s.size();
        mp[0]=-1;
        int mask=0,ans=0;
        for (int i=0;i<n;i++) {
            if (s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='u' or s[i]=='o') {
                mask^=(1<<((int)(s[i]-'a')));
            }
            if (mp.count(mask)) {
                ans=max(ans, i-mp[mask]);
            } else {
                mp[mask]=i;
            }
        }
        return ans;
    }
};