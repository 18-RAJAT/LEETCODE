class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(auto it:queries)
        {
            int sum=0;
            int ct=0;
            for(int i=0;i<nums.size();++i)
            {
                //pf
                sum+=nums[i];
                if(sum<=it)
                {
                    ct++;
                }
            }
            ans.push_back(ct);
        }
        return ans;
    }
};