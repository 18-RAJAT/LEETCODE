class RandomizedSet {
public:
    vector<int>v;
    map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!mp[val])
        {
            v.push_back(val);
            mp[val]=1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp[val])
        {
            mp[val]=0;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        while(true)
        {
            int random=rand()%v.size();
            if(mp[v[random]])
            {
                return v[random];
            }
        }
    }
};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */