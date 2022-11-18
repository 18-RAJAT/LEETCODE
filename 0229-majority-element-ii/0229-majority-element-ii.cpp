class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>result;
        map<int,int>counts;
        int n=nums.size();
        
        for(auto it:nums)
        {
            counts[it]++;
            
            if(counts[it]>n/3)
            {
                result.push_back(it);
                counts[it]-=n;
            }
        }
        return result;
    }
};