class Solution {
public:
    bool isCircularSentence(string sentence) {
        char prev=sentence[0];
        int index=0,n=sentence.size();
        while(index<n){
            if(prev!=sentence[index])return false;
            while(index<n-1 && sentence[index+1]!=' ')index++;
            prev=sentence[index];
            index=index+2;
        }
        if(sentence[n-1]!=sentence[0])return false;
        return true;
    }
};