class MyHashMap {
    int hashmap[1000001];
public:
    MyHashMap() {
        for(int i=0;i<1000001;i++) hashmap[i]=-1;
    }
    
    void put(int key, int value) {
        hashmap[key]=value;
    }
    
    int get(int key) {
        return hashmap[key];
    }
    
    void remove(int key) {
        hashmap[key]=-1;
    }
};