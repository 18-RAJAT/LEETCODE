class TimeMap {
public:
    
    unordered_map<string, unordered_map<int, string> > m;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        int temp = -1;
        if(m[key].count(timestamp))
        {
            return m[key][timestamp];
        }
        while(timestamp--)
        {
            if(timestamp == 0)
            {
                return "";
            }
            else if(m[key].count(timestamp))
            {
                return m[key][timestamp];
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */