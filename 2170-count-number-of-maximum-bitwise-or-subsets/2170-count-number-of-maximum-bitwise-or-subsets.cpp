class Solution {
public:
void dfs(vector<int>&nums,int i,int n, int xrr,priority_queue<int>&pq){
    if(i>=n){
        pq.push(xrr);
    return ;  
    }
    //cout<<i<<" "<<xrr<<endl;
    dfs(nums,i+1,n,xrr,pq);
    xrr=xrr|nums[i];
    dfs(nums,i+1,n,xrr,pq);
}
    int countMaxOrSubsets(vector<int>& nums) {
        priority_queue<int>pq;
        int n=nums.size();
        dfs(nums,0,n,0,pq);
        int ans=0,ct=0;
        if(pq.empty())return 0;
        ans=pq.top();
        pq.pop();
        ct=1;
        cout<<ans<<endl;
        while(!pq.empty()){
            cout<<pq.top()<<endl;
            if(ans!=pq.top())break;
            ct++;
            pq.pop();
        }
        return ct;
    }
};