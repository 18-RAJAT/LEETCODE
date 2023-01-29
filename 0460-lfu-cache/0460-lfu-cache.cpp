class LFUCache {
public:
    LFUCache(int capacity):cap(capacity),minFreq(0){}
    
    int get(int key) {
        // if not found in map, return -1
        // if found in map, move node to list with ++freq
        // return the value
        auto it=cacheMap.find(key);
        if (it==cacheMap.end()) 
        {
            return -1;
        }
        move_node(it->second);
        return it->second.value;
    }
    
    void put(int key, int value) {
        // if found in map, move node to list with ++freq, update the value
        // if not found in map, 
        //     if size < cap fine
        //     if size == cap evit the LRU in list with minFreq
        //     add to list with freq = 1, minFreq is 1
        if(cap==0)
        {
            return;
        }
        auto it=cacheMap.find(key);
        if(it!=cacheMap.end())
        {
            it->second.value=value;
            move_node(it->second);
            return;
        }
        if(cacheMap.size()==cap)
        {
            int keyToEvict=cacheLists[minFreq].back();
            cacheLists[minFreq].pop_back();
            cacheMap.erase(keyToEvict);
        }
        cacheLists[1].push_front(key);
        minFreq=1;
        cacheMap[key]={key,value,1,cacheLists[1].begin()};
    }
private:
    int minFreq;
    int cap;
    struct Node 
    {
        int key; //key is used by move_node()
        int value;
        int freq;
        list<int>::iterator it;
    };
    // key to node
    unordered_map<int,Node>cacheMap;
    // freq to 'list of keys'
    unordered_map<int,list<int>>cacheLists;

    // move node from Freq to Freq+1
    // node can be anywhere in the list of Freq
    // need to check if minFreq need to be udpated
    void move_node(Node& node)
    {
        int oldFreq=node.freq;
        int freqPlus=oldFreq+1;

        cacheLists[oldFreq].erase(node.it);
        if (cacheLists[oldFreq].empty() and oldFreq==minFreq)
        {
            cacheLists.erase(oldFreq);
            ++minFreq;
        }

        cacheLists[freqPlus].push_front(node.key);
        node.it=cacheLists[freqPlus].begin();
        node.freq++;
    }

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */