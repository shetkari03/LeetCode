class NumberContainers {
public:
map<int,int>mpp;
map<int,set<int>>arr;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mpp[index]==0){
            mpp[index]=number;
            arr[number].insert(index);
        }
        else{
            int d=mpp[index];
            arr[d].erase(index);
            mpp[index]=number;
            arr[number].insert(index);
           //arr[d].erase(index);
        }
    }
    
    int find(int number) {
        if(arr[number].size()==0)return -1;
        auto it=arr[number].begin();
        return *it;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */