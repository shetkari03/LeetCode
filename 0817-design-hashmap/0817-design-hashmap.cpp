class MyHashMap {
public:
class hashMap{
    public:
    int hash[1000001];
    hashMap(){
        for(int  i=0;i<=1000000;i++)hash[i]=-1;
    }
    
};
hashMap obj;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        obj.hash[key]=value;
    }
    
    int get(int key) {
        return obj.hash[key];
    }
    
    void remove(int key) {
        obj.hash[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */