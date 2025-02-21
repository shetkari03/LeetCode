class Solution {
public:
    int romanToInt(string s) {
        map<char,int>mpp;
        mpp['I']=1,mpp['V']=5,mpp['X']=10,mpp['L']=50,mpp['C']=100,mpp['D']=500,mpp['M']=1000;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            
            if(i<n-1 && mpp[s[i+1]]>mpp[s[i]]){
                ans+=mpp[s[i+1]]-mpp[s[i]];
                i++;
            }
            else ans+=mpp[s[i]];
            //cout<<ans<<endl;
        }
        
        return ans;
    }
   
};