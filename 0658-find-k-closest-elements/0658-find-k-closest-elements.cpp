class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i=0,j=arr.size()-1;
        while(j-i+1>k){
            int d=abs(arr[i]-x);
            int f=abs(arr[j]-x);
            if(d>f)i++;
            else j--;
        }
        vector<int>ans;
        for(int p=i;p<=j;p++)ans.push_back(arr[p]);
        return ans;
    }
};