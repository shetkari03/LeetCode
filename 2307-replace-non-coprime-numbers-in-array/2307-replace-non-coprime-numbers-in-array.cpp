class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int>st;
        st.push(nums[0]);
        int n=nums.size();
        for(int i=1;i<n;i++){
            int b=nums[i];
            while(!st.empty()){
                int a=st.top();st.pop();
                int d=__gcd(a,b);
                if(d==1){
                    st.push(a);
                    st.push(b);
                    break;
                }
                int l=lcm(a,b);
                b=l;
            }
            if(st.empty())st.push(b);
        }
        vector<int>ans(st.size(),0);
        int ind=st.size()-1;
        while(!st.empty()){
            ans[ind]=st.top();
            st.pop();
            ind--;
        }
        return ans;
    }
};