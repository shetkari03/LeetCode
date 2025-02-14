class ProductOfNumbers {
public:
vector<pair<int,int>>arr;
int n=0;
    ProductOfNumbers() {
        arr.push_back({1,0});
        n++;
    }
    
    void add(int num) {
        if(num==0){
            arr.push_back({1,1+arr[n-1].second});
        }
        else{
            arr.push_back({num*arr[n-1].first,arr[n-1].second});
        }
        n++;
    }
    
    int getProduct(int k) {
        int d=arr[n-1].second-arr[n-k-1].second;
        if(d)return 0;
        return arr[n-1].first/arr[n-k-1].first;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */