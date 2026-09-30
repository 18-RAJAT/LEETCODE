class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int res=0;
        vector<int>ans;
        for(auto& it:seq)ans.push_back(it=='('?res++&1:--res&1);
        return ans;
    }
};