class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans=0;
        for(int i=0;i<derived.size();++i)
        {
            ans+=derived[i];
        }
        return ans&1?0:1;
    }
};