class SnapshotArray {
public:

vector<map<int,int ,greater<int>>> mp;
    int id=0;
    SnapshotArray(int length) {
        mp.resize(length);
    }
    
    void set(int index, int val) {
        mp[index][id]=val;
    }
    
    int snap() {
        auto ans=id;
        id++;
        return ans;
    }
    
    int get(int index, int snap_id) {
        auto i=mp[index].lower_bound(snap_id);
        return i->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */