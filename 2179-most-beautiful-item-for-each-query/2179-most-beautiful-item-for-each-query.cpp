#include<bits/stdc++.h>
class Solution {
public:
public: bool comp(const string &a, const string &b) {
    return lexicographical_compare(a.begin(), a.end(),
           b.begin(), b.end(), [](char c1, char c2) {
        return tolower(c1) < tolower(c2);
    });
}
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int n=items.size();
        vector<int>hash(n,0);
        hash[0]=items[0][1];
        for(int i=1;i<n;i++){
            hash[i]=hash[i-1]>items[i][1]?hash[i-1]:items[i][1];
        }
        vector<int>ans;
        for(auto it:queries){
            int left=0,right=n-1;
            while(left<=right){
                int mid=(left+right)/2;
                if(it<items[mid][0])right=mid-1;
                else left=mid+1;
            }
            cout<<left<<" "<<right<<endl;
            if(right>=0 && right<n)ans.push_back(hash[right]);
            else ans.push_back(0);
        }
        return ans;
    }
};