class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hash;
        vector<int>order;
        
        for(int i=0;i<nums.size();++i)
        {
            int numberFind=target-nums[i];
            if(hash.find(numberFind)!=hash.end())
            {
                order.push_back(hash[numberFind]);
                order.push_back(i);
                
                return order;
            }
            hash[nums[i]]=i;
        }
        return order;
    }
};