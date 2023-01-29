class LFUCache {
    int capacity;
    unordered_map<int, pair<int, int>> m; // key -> {value, freq}
    unordered_map<int, list<int>> freq;   // freq -> list of keys
    unordered_map<int, list<int>::iterator> pos; // key -> position in freq list

public:
    LFUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (m.count(key) == 0) return -1;
        freq[m[key].second].erase(pos[key]);
        m[key].second++;
        freq[m[key].second].push_back(key);
        pos[key] = --freq[m[key].second].end();
        if (freq[minFreq].size() == 0) minFreq++;
        return m[key].first;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;
        if (m.count(key) && get(key) != -1) {
            m[key].first = value;
            return;
        }
        if (m.size() >= capacity) {
            int k = freq[minFreq].front();
            freq[minFreq].pop_front();
            pos.erase(k);
            m.erase(k);
        }
        m[key] = {value, 1};
        freq[1].push_back(key);
        pos[key] = --freq[1].end();
        minFreq = 1;
    }

private:
    int minFreq = INT_MAX;
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */