class Solution {
public:
    int minAddToMakeValid(string s) {
        // stack<char>st;
        // for(int i=0;i<s.size();i++){
        //     if(st.empty()==true){
        //         st.push(s[i]);
        //         continue;
        //     }
        //     else{
        //         char ch=st.top();
        //         if(ch=='(' && s[i]==')'){
        //             st.pop();
        //         }
        //         else st.push(s[i]);
        //     }
        // }
        // return st.size();
        stack<char>st;
        for(auto it:s){
            if(it=='(')st.push(it);
            else{
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else st.push(it);
            }
        }
        return st.size();
    }
};