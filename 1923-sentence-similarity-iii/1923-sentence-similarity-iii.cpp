class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.size()>s2.size())return areSentencesSimilar(s2,s1);
        int n=s1.size(),m=s2.size();
        int i1=0,j1=n-1;
        int i2=0,j2=m-1;
        while(i1<n && i2<m){
            string a,b;
            int t=i1;
            while(i1<n && s1[i1]!=' ')a.push_back(s1[i1++]);
            int r=i2;
            while(i2<m && s2[i2]!=' ')b.push_back(s2[i2++]);
            if(a!=b){
                i1=t;
                i2=r;
                break;
            }
            i1++;
            i2++;
            cout<<a<<" "<<b<<endl;
        }
        int ct=0,flag=0;
        while(j1>=0 && j2>=0){
             string a,b;
            int t=j1;
            while(j1>=0 && s1[j1]!=' ')a.push_back(s1[j1--]);
            int r=j2;
            while(j2>=0 && s2[j2]!=' ')b.push_back(s2[j2--]);
            if(a!=b){
                j1=t;
                j2=r;
                break;
            }
            cout<<a<<" "<<b<<endl;
            j1--;
            j2--;
        }
        cout<<i1<<" "<<j1<<endl;
        for(int k=i1;k<=j1;k++)if(s1[k]!=' ')flag=1;
        if(flag)return 0;
        return 1;

    }
};