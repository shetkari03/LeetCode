class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        //return 0;
        long long sum1=0,n1=0;
        long long sum2=0,n2=0;
        for(auto it:nums1){
            sum1+=it;
            if(!it)n1++;
        }
        for(auto it:nums2){
            sum2+=it;
            if(!it)n2++;
        }
        cout<<sum1<<" "<<n1<<endl;
        cout<<sum2<<" "<<n2<<endl;
        if(sum1==sum2){
            if((n1>0 && n2>0) || n1==n2)return sum1+max(n1,n2);
            return -1;
        }
        else if(sum1>sum2){
            if(n2>0){
                if(n1==0 && sum1>=n2+sum2)return sum1;
                if(n1>0)return max(sum1+n1,sum2+n2);
            }
        }
        else{
            if(n1>0){
                if(n2==0 && sum2>=n1+sum1)return sum2;
                if(n2>0)return max(sum1+n1,sum2+n2);
            }
        }
        return -1;

    }
};