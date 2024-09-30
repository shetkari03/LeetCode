class CustomStack {
public:
vector<int>arr;
int i=0,n=0;
    CustomStack(int maxSize) {
        n=maxSize;
        for(int j=0;j<n;j++)arr.push_back(-1);
;    }
    
    void push(int x) {
        if(i<n){
            arr[i]=x;
            i++;
        }
    }
    
    int pop() {
        if(i>0){
            i--;
            return arr[i];
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for(int j=0;j<=min(k-1,i);j++)arr[j]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */