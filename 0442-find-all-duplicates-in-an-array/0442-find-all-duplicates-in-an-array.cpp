class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<array<int,2>>dup;
        for(int i=0;i<nums.size();++i)
        {
            dup.push_back({nums[i],i});
        }
        sort(dup.begin(),dup.end());
        vector<int>res;
        for(int i=1;i<dup.size();++i)
        {
            if(dup[i][0]==dup[i-1][0])
            {
                res.push_back(dup[i][0]);
            }
        }
        return res;
    }
};