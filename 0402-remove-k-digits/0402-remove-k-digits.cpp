class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;
        string ans;
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                k--;
                st.pop();
            }
            st.push(num[i]);
        }
        while(!st.empty() && k>0){
            k--;
            st.pop();
        }
        //while(!st.empty() && st.top()=='0')st.pop();
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        int ct=0;
        reverse(ans.begin(),ans.end());
         for(int i=0;i<ans.size();i++){
            if(ans[i]!='0')break;
            ct++;
        }
        ans=ans.substr(ct,n);
        if(ans=="")return "0";
        return ans;
    }
};