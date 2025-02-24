class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(),pizzas.end());
        int i=0,j=pizzas.size()-1;
        int n=(j+1)/4;
        if(n==1)return pizzas[j];
        long long ans=0;
        for(int k=0;k<(n+1)/2;k++){
            ans+=pizzas[j];
            j--;
            i+=3;
        }
        n=n-(n+1)/2;
        for(int k=0;k<n;k++){
            ans+=pizzas[j-1];
            j-=2;
            i+=2;
        }
        return ans;
    }
};