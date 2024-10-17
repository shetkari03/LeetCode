class Solution {
public:
    int maximumSwap(int num) {
        vector<int>arr;
        while(num){
            arr.push_back(num%10);
            num=num/10;
        }
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            int max=-1,ind=-1;
            for(int j=i-1;j>=0;j--){
                if(max<=arr[j]){
                    ind=j;
                    max=arr[j];
                }
            }
            if(max>arr[i]){
                arr[ind]=arr[i];
                arr[i]=max;
                break;
            }
        }
        long long ans=0;
        for(int i=n-1;i>=0;i--)ans=ans*10+arr[i];
        return ans;
    }
};