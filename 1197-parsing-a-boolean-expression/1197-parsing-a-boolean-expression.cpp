class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;
        stack<pair<int,int>>arr;
        int f=0,t=0,n=expression.size();
        for(int i=0;i<n;i++){
            if(expression[i]=='('){
                arr.push({t,f});
                t=0;f=0;
            }
            if(expression[i]=='|' || expression[i]=='&' || expression[i]=='!')st.push(expression[i]);
            else if(expression[i]=='f')f++;
            else if(expression[i]=='t')t++;
            else if(expression[i]==')'){
                      cout<<t<<" "<<f<<endl;
                while(!st.empty()){
                      char ch=st.top();st.pop();
                      if(ch=='!'){
                          int a=f;
                          f=t;
                           t=a;
                      }
                      if(ch=='&'){
                          if(f>0){
                            f=1;
                            t=0;
                          }
                          else {
                             t=1;
                              f=0;
                          }
                      }
                      if(ch=='|'){
                          if(t>0){
                            t=1;
                            f=0;
                          }
                          else {
                             f=1;
                               t=0;
                          }
                      }
                      if(!arr.empty()){
                            t+=arr.top().first;
                            f+=arr.top().second;
                            arr.pop();
                      }
            
                    cout<<ch<<" "<<t<<" "<<f<<endl;
                //while end
                break;
                }
            }
            //for end
        }
        //cout<<t<<" "<<f<<endl;
        
        if(f>0)return 0;
        return 1;
    }
};