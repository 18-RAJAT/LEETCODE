class Solution {
public:
    void backtrack(vector<int>& candidates,vector<vector<int>>& ans,vector<int>& v,int start,int target)
    {
        if(target==0)
        {
            ans.push_back(v);
            return ;
        }
        for(int i=start;i<candidates.size() && candidates[i]<=target;++i)
        {
            v.push_back(candidates[i]);
            backtrack(candidates,ans,v,i+1,target-candidates[i]);
            while (i+1<candidates.size() && candidates[i+1]==candidates[i])i++;
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,ans,v,0,target);
        return ans;
    }
};