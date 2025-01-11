class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> arr(26,0);

        for(int i=0;i<s.length();i++){
            arr[s[i]-'a']++;
        }
        int e=0,o=0;
        for(int i=0;i<26;i++){
            if(arr[i]%2==0 && arr[i]>0) e++;
            else if(arr[i]%2!=0) o++;
        }

        if(o<=k && s.length()>=k)    return true;
        else return false;
    }
};