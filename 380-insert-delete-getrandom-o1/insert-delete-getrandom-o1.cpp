class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    map<int,int>omap;
    
    bool insert(int val) {
        if(omap.count(val)>0){
            return false;
        }
        else{
            omap[val]=1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(omap.count(val)>0){
            omap.erase(val);
            return true;
        }
        else{
            // omap[val]=1;
            return false;
        }        
    }
    
    int getRandom() {
        int mapSize = omap.size();

    // Generate a random index within the range of the map's size
        int randomIndex = std::rand() % mapSize;
        auto it = std::next(omap.begin(), randomIndex);

        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */