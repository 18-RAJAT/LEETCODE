class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       set<int>s1;
        for(auto i:nums){if(i!=0)s1.insert(i);}
        return (s1.size());
    }
};