#define INF (int)1e9
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<vector<int>> VII;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;

class MyHashSet {
    VB HASH;
public:
    MyHashSet() {
        HASH=VB(INF,false);
    }
    
    void add(int key) {
        // VB ert;
        HASH[key]=true;
    }
    
    void remove(int key) {
        HASH[key]=false;
    }
    
    bool contains(int key) {
        return HASH[key];//=false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */