
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=candidates.size();
        function<void(int,int)>helper=[&](int sum,int i)
        {
            if(sum==target)
            {
                ans.push_back(temp);
            }
            if(sum>target)
            {
                return;
            }
            for(int j=i;j<n;j++)
            {
                temp.push_back(candidates[j]);
                helper(sum+candidates[j],j);
                temp.pop_back();
            }
        };
        helper(0,0);
        return ans;       
    }
};