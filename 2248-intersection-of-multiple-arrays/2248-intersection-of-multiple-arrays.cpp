class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        // vector<int>res;
        // bool f=0;
        // for(auto it:nums[0])
        // {
        //     for(int i=0;i<nums.size();++i)
        //     {
        //         if(find(nums[i].begin(),nums[i].end(),it)==nums[i].end()){f=1;break;}
        //     }
        //     if(f==0){res.push_back(it);}
        // }
        // return res;
        
        vector<int>res;map<int,int>mp;int n=nums.size();
        for(int i=0;i<n;++i)
        {for(int j=0;j<nums[i].size();++j){mp[nums[i][j]]++;}}
        for(auto it:mp){if(it.second==n){res.push_back(it.first);}}
        return res;
    }
};
