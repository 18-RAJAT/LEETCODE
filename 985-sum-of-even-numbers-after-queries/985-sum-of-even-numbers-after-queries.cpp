class Solution {
private:

vector<int>ans;int sum=0;

public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto query:queries)
        {
            if(ans.size()==0)
            {
                nums[query[1]]+=query[0];
                for(auto it:nums)
                if(it%2==0)
                {
                    sum+=it;
                }
            }
            else 
            {
                if(nums[query[1]]%2==0)sum-=nums[query[1]];
                nums[query[1]]+=query[0];
                
                if(nums[query[1]]%2==0)
                {
                    sum+=nums[query[1]];
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};