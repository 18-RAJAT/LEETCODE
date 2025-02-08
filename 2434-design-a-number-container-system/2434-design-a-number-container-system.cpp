class NumberContainers {
public:
    unordered_map<int,int>mp;
    unordered_map<int,set<int>>m;
    NumberContainers() {
        // mp.clear();
    }
    
    void change(int index, int number) {
        auto tmp=mp[index];
        mp[index]=number;
        m[tmp].erase(index);
        if(m[tmp].empty())m.erase(tmp);
        m[number].insert(index);
    }
    
    int find(int number) {
        auto it=m.find(number);
        return (it==m.end())?-1:*it->second.begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */