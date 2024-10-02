class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>nums(arr);
        sort(nums.begin(),nums.end());
            
        unordered_map<int,int>mp;
        int cnt=1;
        for(int i=0;i<nums.size();++i)
        {
            if(i==0 || nums[i]!=nums[i-1])
            {
                mp[nums[i]]=cnt++;
            }
        }
        vector<int>ans;
        for(int i=0;i<arr.size();++i)ans.push_back(mp[arr[i]]);
        return ans;
    }
};