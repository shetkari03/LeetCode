class NumArray {
public:
vector<int>temp;
    NumArray(vector<int>& nums) {
        temp=nums;
        for(int i=1;i<temp.size();i++){
            temp[i]+=temp[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0)return temp[right];
        return temp[right]-temp[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */