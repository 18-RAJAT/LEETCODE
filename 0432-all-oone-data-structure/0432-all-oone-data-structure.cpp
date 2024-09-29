class AllOne{
public:
    unordered_map<string,int>m;
    map<int,unordered_set<string>>mp;
    AllOne(){}
    
    void inc(string key)
    {
        if(m.find(key)==m.end())
        {
            m[key]=1;
            mp[1].insert(key);
        }
        else
        {
            int p=m[key];
            m[key]=p+1;
            mp[p].erase(key);
            if(mp[p].size()==0)mp.erase(p);
            mp[p+1].insert(key);
        }
    }
    
    void dec(string key)
    {
        int p=m[key];
        if(p==1)
        {
            m.erase(key);
            mp[p].erase(key);
            if(mp[p].size()==0)mp.erase(p);
        }
        else
        {
            m[key]=p-1;
            mp[p].erase(key);
            if(mp[p].size()==0)mp.erase(p);
            mp[p-1].insert(key);
        }
    }
    
    string getMaxKey()
    {
        string s="";
        if(mp.size())
        {
            auto p=mp.rbegin()->second.begin();
            s=*p;
        }
        return s;
    }
    
    string getMinKey()
    {
        string s="";
        if(mp.size())
        {
            auto p=mp.begin()->second.begin();
            s=*p;
        }
        return s;
    }
};


/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */