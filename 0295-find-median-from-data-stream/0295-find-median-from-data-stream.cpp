class MedianFinder {
public:
priority_queue<int,vector<int>,greater<int>>min1;
priority_queue<int>max1;
    MedianFinder() {
        
    }
    int abs(int a,int b){
        if(a>b)return a-b;
        return b-a;
    }
    void addNum(int num) {
        if(max1.empty()){max1.push(num);return;}
        else{
            if(max1.top()>=num)max1.push(num);
            else min1.push(num);
        }
        while(1){
            int a=max1.size(),b=min1.size();
            if(b-a>1 && b>0){
                max1.push(min1.top());
                min1.pop();
            }
            else if(a-b>1 && a>0){
                min1.push(max1.top());
                max1.pop();
            }
            break;           
        }
    }
    
    double findMedian() {
        if(min1.size()==max1.size()){
            cout<<min1.top()<<" "<<max1.top()<<endl;
            return double((max1.top()+min1.top())/2.0);   
        }
        else {
            if(min1.size()>max1.size()){
                cout<<min1.top()<<" min"<<endl;
                return 1.0*min1.top();
            }
            else {
                cout<<max1.top()<<" max"<<endl;
                return 1.0*max1.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */