class Solution {
public:
bool isVowel(char ch){
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;
    return false;
}
    int maxVowels(string s, int k) {
        int ct=0,ans=0, left=0;
        for(int right=0;right<s.size();right++){
            if(isVowel(s[right])){
                ct++;
            }
            while(right-left+1>k){
                if(isVowel(s[left]))ct--;
                left++;
            }
            if(right-left+1==k){
                ans=ans>ct?ans:ct;
            }            
        }
        return ans;
    }
};