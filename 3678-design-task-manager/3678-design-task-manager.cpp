class TaskManager {
public:
    unordered_map<int,int>mp;
    unordered_map<int,int>mp1;
    set<pair<int,int>>st;
    
    TaskManager(vector<vector<int>>& tasks) {
        for(auto& it:tasks)
        {
            int userId=it[0],taskId=it[1];
            int priority=it[2];
            mp[taskId]=userId;
            mp1[taskId]=priority;
            st.insert({-priority,-taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId]=userId;
        mp1[taskId]=priority;
        st.insert({-priority,-taskId});
    }
    
    void edit(int taskId, int newPriority) {
        auto it = st.find(make_pair(-mp1[taskId],-taskId));
        st.erase(it);
        st.insert({-newPriority,-taskId});
        mp1[taskId]=newPriority;
    }
    
    void rmv(int taskId) {
        st.erase({-mp1[taskId],-taskId});
        mp.erase(taskId);
        mp1.erase(taskId);
    }
    
    int execTop() {
        if(st.empty())return -1;
        int task=-(st.begin()->second),user=mp[task];
        st.erase(st.begin());
        mp.erase(task);
        mp1.erase(task);
        return user;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */