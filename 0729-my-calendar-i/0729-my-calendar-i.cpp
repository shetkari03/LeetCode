class MyCalendar {
public:
        set<pair<int,int>>arr;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
            for(auto it:arr){
                if(it.first>=end)break;
                // if(it.first<end && start<=it.first)return false;
                // if(start>=it.first && end<it.second)return false;
                // if(start<it.second && end>=it.second)return false;
                if(end<=it.first || it.second<=start);
                else return false;
            }
            arr.insert({start,end});
            return true;

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */