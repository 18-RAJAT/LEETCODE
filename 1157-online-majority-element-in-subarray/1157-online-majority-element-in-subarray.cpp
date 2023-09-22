class MajorityChecker {
public:
    unordered_map<int,vector<int>> mp;
    MajorityChecker(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;++i)
        {
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        for(auto& it:mp)
        {
            if(it.second.size()<threshold)
            {
                continue;
            }
            auto it1=lower_bound(it.second.begin(),it.second.end(),left);//first element >=left
            auto it2=upper_bound(it.second.begin(),it.second.end(),right);//first element >right
            if(it2-it1>=threshold)
            {
                return it.first;
            }
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */