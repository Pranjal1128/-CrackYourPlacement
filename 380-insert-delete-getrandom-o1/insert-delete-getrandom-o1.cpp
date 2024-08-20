class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp[val]) return false;
        v.push_back(val);
        mp[val] = v.size();
        return true;
    }
    
    bool remove(int val) {
        if(!mp[val]) return false;

        int idx = mp[val] - 1;
        v[idx] = v.back();
        mp[v[idx]] = idx + 1;
        mp[val] = 0;
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        int n = v.size();
        int r = rand();
        return v[r % n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */