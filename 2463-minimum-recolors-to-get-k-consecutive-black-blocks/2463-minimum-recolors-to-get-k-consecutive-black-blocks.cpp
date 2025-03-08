class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0,j=0,n=blocks.size();
        int ct=0,ans=k;
        for(int l=0;l<k;l++){
            if(blocks[i]=='W')ct++;
            i++;
        }
        ans=min(ans,ct);
        while(i<n){
            if(blocks[i]=='W')ct++;
            if(blocks[j]=='W')ct--;
            j++;
            i++;
            ans=min(ct,ans);
        }
        return ans;
    }
};